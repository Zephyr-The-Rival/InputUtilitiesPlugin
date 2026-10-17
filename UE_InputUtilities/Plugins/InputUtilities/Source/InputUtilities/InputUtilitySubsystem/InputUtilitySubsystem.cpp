// Fill out your copyright notice in the Description page of Project Settings.


#include "InputUtilitySubsystem.h"

#include "InputMappingContext.h"
#include "Engine/World.h"
#include "Framework/Application/SlateApplication.h"
#include "InputUtilities/Saving/InputUserSettings.h"
#include "InputUtilities/Settings/InputUtilitiesSettings.h"
#include "Kismet/GameplayStatics.h"

bool FInputUtilitiesInputProcessor::HandleKeyDownEvent(FSlateApplication& SlateApp, const FKeyEvent& InKeyEvent)
{
	if (Subsystem.IsValid())
		Subsystem->OnAnyKeyPressed(InKeyEvent.GetKey());
	return false;
}

bool FInputUtilitiesInputProcessor::HandleMouseButtonDownEvent(FSlateApplication& SlateApp, const FPointerEvent& MouseEvent)
{
	if (Subsystem.IsValid())
		Subsystem->OnAnyKeyPressed(MouseEvent.GetEffectingButton());
	return false;
}

bool FInputUtilitiesInputProcessor::HandleMouseWheelOrGestureEvent(FSlateApplication& SlateApp, const FPointerEvent& InWheelEvent, const FPointerEvent* InGestureEvent)
{
	if (Subsystem.IsValid() && InWheelEvent.GetWheelDelta() != 0.f)
		Subsystem->OnAnyKeyPressed(InWheelEvent.GetWheelDelta() > 0.f ? EKeys::MouseScrollUp : EKeys::MouseScrollDown);
	return false;
}

void UInputUtilitySubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	InputProcessor = MakeShared<FInputUtilitiesInputProcessor>(this);
	FSlateApplication::Get().RegisterInputPreProcessor(InputProcessor);

	UserSettings = LoadUserSettings();
	CaptureDefaultMappings();
	FWorldDelegates::OnWorldTickStart.AddUObject(this, &UInputUtilitySubsystem::OnWorldTickStart);
}

void UInputUtilitySubsystem::Deinitialize()
{
	FWorldDelegates::OnWorldTickStart.RemoveAll(this);

	// Editor PIE sessions keep reusing the same in-memory context assets, so
	// put them back to default on shutdown. Otherwise the next session's
	// "default" snapshot would just be whatever this session last applied.
	RevertContextsToDefault();

	if (FSlateApplication::IsInitialized() && InputProcessor.IsValid())
		FSlateApplication::Get().UnregisterInputPreProcessor(InputProcessor);

	Super::Deinitialize();
}

void UInputUtilitySubsystem::CaptureDefaultMappings()
{
	DefaultMappings.Empty();

	const UInputUtilitiesSettings* Settings = GetDefault<UInputUtilitiesSettings>();
	if (Settings->ManagedMappingContexts.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("[InputUtilities] No Mapping Contexts configured in Project Settings > Plugins > Input Utilities. Remapping and Reset to Default will not work."));
		return;
	}

	for (const TSoftObjectPtr<UInputMappingContext>& ManagedMappingContextRef : Settings->ManagedMappingContexts)
	{
		UInputMappingContext* ManagedMappingContext = ManagedMappingContextRef.LoadSynchronous();
		if (!ManagedMappingContext)
			continue;

		for (const FEnhancedActionKeyMapping& M : ManagedMappingContext->GetMappings())
		{
			FSavedMapping Default;
			Default.Action = const_cast<UInputAction*>(M.Action.Get());
			Default.MappingContext = ManagedMappingContext;
			Default.MappedKey = M.Key;
			Default.Modifiers = M.Modifiers;
			Default.Triggers = M.Triggers;
			DefaultMappings.Add(Default);
		}
	}
}

void UInputUtilitySubsystem::RevertContextsToDefault()
{
	// Rebuild every action's bindings from scratch instead of patching individual
	// key rows. Actions with multiple same-device bindings (e.g. WASD movement,
	// where all four keys share one Action) can't be identified by Action +
	// device type alone - patching one row at a time ends up swapping/duplicating
	// the wrong key and losing the per-key Modifiers (Swizzle/Negate etc).
	TArray<TPair<UInputMappingContext*, UInputAction*>> ProcessedActions;

	for (const FSavedMapping& Default : DefaultMappings)
	{
		if (!Default.MappingContext || !Default.Action)
			continue;

		TPair<UInputMappingContext*, UInputAction*> ActionKey(Default.MappingContext, Default.Action);
		if (ProcessedActions.Contains(ActionKey))
			continue;
		ProcessedActions.Add(ActionKey);

		Default.MappingContext->UnmapAllKeysFromAction(Default.Action);

		for (const FSavedMapping& Slot : DefaultMappings)
		{
			if (Slot.MappingContext != Default.MappingContext || Slot.Action != Default.Action)
				continue;

			FEnhancedActionKeyMapping& NewEntry = Slot.MappingContext->MapKey(Slot.Action, Slot.MappedKey);
			NewEntry.Modifiers = Slot.Modifiers;
			NewEntry.Triggers = Slot.Triggers;
		}
	}
}

void UInputUtilitySubsystem::OnWorldTickStart(UWorld* InWorld, ELevelTick TickType, float DeltaSeconds)
{
	if (!InWorld || !InWorld->IsGameWorld() || !InWorld->HasBegunPlay())
		return;

	FWorldDelegates::OnWorldTickStart.RemoveAll(this);
	ApplyMappingSave(UserSettings);
}

void UInputUtilitySubsystem::OnAnyKeyPressed(FKey Key)
{
	OnAnyKeyPressedEvent.Broadcast(Key);

	if (bGamepadIsBeingUsed != Key.IsGamepadKey())
	{
		bGamepadIsBeingUsed = Key.IsGamepadKey();
		TriggerRefresh();
	}
}

void UInputUtilitySubsystem::TriggerRefresh()
{
	ReinitializePrompts.Broadcast();
}

void UInputUtilitySubsystem::SaveMapping(FSavedMapping NewMapping)
{
	if (!UserSettings || !NewMapping.Action || !NewMapping.MappingContext)
		return;

	int32 ExistingIndex = FindMappingInSavedArray(NewMapping);
	if (ExistingIndex != -1)
		UserSettings->SavedMappings.RemoveAt(ExistingIndex);

	UserSettings->SavedMappings.Add(NewMapping);
	UGameplayStatics::SaveGameToSlot(UserSettings, UserSettingsSaveSlotName, 0);
}

UInputUserSettings* UInputUtilitySubsystem::LoadUserSettings()
{
	if (UGameplayStatics::DoesSaveGameExist(UserSettingsSaveSlotName, 0))
		return Cast<UInputUserSettings>(UGameplayStatics::LoadGameFromSlot(UserSettingsSaveSlotName, 0));
	else
		return Cast<UInputUserSettings>(UGameplayStatics::CreateSaveGameObject(UInputUserSettings::StaticClass()));
}

void UInputUtilitySubsystem::ApplyMappingSave(UInputUserSettings* Settings)
{
	if (!Settings)
		return;

	for (const FSavedMapping& MappingToApply : Settings->SavedMappings)
	{
		UInputMappingContext* MappingContext = MappingToApply.MappingContext;
		if (!MappingContext || !MappingToApply.Action || !MappingToApply.MappedKey.IsValid())
			continue;

		// Find the default slot this remap replaces, so we know which key to
		// replace and which Modifiers/Triggers to carry over. Matching only by
		// keyboard/gamepad type can't disambiguate an action with multiple
		// same-device bindings (e.g. WASD) - this is a known limitation for
		// those actions until saved remaps carry their own slot identifier.
		const FSavedMapping* MatchedDefault = nullptr;
		for (const FSavedMapping& Default : DefaultMappings)
		{
			if (Default.Action == MappingToApply.Action && Default.MappingContext == MappingContext &&
				Default.MappedKey.IsGamepadKey() == MappingToApply.MappedKey.IsGamepadKey())
			{
				MatchedDefault = &Default;
				break;
			}
		}

		if (MatchedDefault)
		{
			MappingContext->UnmapKey(MappingToApply.Action, MatchedDefault->MappedKey);
			FEnhancedActionKeyMapping& NewEntry = MappingContext->MapKey(MappingToApply.Action, MappingToApply.MappedKey);
			NewEntry.Modifiers = MatchedDefault->Modifiers;
			NewEntry.Triggers = MatchedDefault->Triggers;
		}
	}
	TriggerRefresh();
}

void UInputUtilitySubsystem::ResetMappingsToDefault()
{
	if (bInProcessOfRemappingKey)
		return;

	RevertContextsToDefault();

	// Only clear the key remaps, not the whole settings object - it may also
	// hold unrelated preferences like bUseAlternativeGamepadTextures.
	UserSettings->SavedMappings.Empty();
	UGameplayStatics::SaveGameToSlot(UserSettings, UserSettingsSaveSlotName, 0);
	TriggerRefresh();
}

int32 UInputUtilitySubsystem::FindMappingInSavedArray(FSavedMapping NewMapping)
{
	for (int i=0; i<UserSettings->SavedMappings.Num(); i++)
	{
		if (UserSettings->SavedMappings[i].Action == NewMapping.Action &&
			UserSettings->SavedMappings[i].MappingContext == NewMapping.MappingContext &&
			UserSettings->SavedMappings[i].MappedKey.IsGamepadKey() == NewMapping.MappedKey.IsGamepadKey())
		{
			return i;
		}
	}
	return -1;
}

void UInputUtilitySubsystem::SetUseAlternativeGamepadTexture(bool bNewValue)
{
	if (!UserSettings)
		return;

	UserSettings->bUseAlternativeGamepadTextures = bNewValue;
	UGameplayStatics::SaveGameToSlot(UserSettings, UserSettingsSaveSlotName, 0);
	TriggerRefresh();
}
