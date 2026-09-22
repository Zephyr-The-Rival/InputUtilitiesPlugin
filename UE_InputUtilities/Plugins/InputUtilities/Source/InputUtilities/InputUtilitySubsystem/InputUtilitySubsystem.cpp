// Fill out your copyright notice in the Description page of Project Settings.


#include "InputUtilitySubsystem.h"

#include "InputMappingContext.h"
#include "Engine/World.h"
#include "Framework/Application/SlateApplication.h"
#include "InputUtilities/Saving/MappingSave.h"
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

void UInputUtilitySubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	InputProcessor = MakeShared<FInputUtilitiesInputProcessor>(this);
	FSlateApplication::Get().RegisterInputPreProcessor(InputProcessor);

	MappingSaveObj = LoadMappingSaveObj();
	FWorldDelegates::OnWorldTickStart.AddUObject(this, &UInputUtilitySubsystem::OnWorldTickStart);
}

void UInputUtilitySubsystem::Deinitialize()
{
	FWorldDelegates::OnWorldTickStart.RemoveAll(this);

	if (FSlateApplication::IsInitialized() && InputProcessor.IsValid())
		FSlateApplication::Get().UnregisterInputPreProcessor(InputProcessor);

	Super::Deinitialize();
}

void UInputUtilitySubsystem::OnWorldTickStart(UWorld* InWorld, ELevelTick TickType, float DeltaSeconds)
{
	if (!InWorld || !InWorld->IsGameWorld() || !InWorld->HasBegunPlay())
		return;

	FWorldDelegates::OnWorldTickStart.RemoveAll(this);
	ApplyMappingSave(MappingSaveObj);
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

bool UInputUtilitySubsystem::SaveOriginalMapping(UInputAction* Action, UInputMappingContext* MappingContext, bool bForGamepad)
{
	if (!MappingSaveObj || !Action || !MappingContext)
		return false;

	FSavedMapping OriginalMapping;
	OriginalMapping.Action = Action;
	OriginalMapping.MappingContext = MappingContext;

	for (const FEnhancedActionKeyMapping& Mapping : MappingContext->GetMappings())
	{
		if (Mapping.Action == Action && Mapping.Key.IsGamepadKey() == bForGamepad)
		{
			OriginalMapping.OriginalKey = Mapping.Key;
			OriginalMapping.MappedKey = Mapping.Key;
			break;
		}
	}

	if (!OriginalMapping.OriginalKey.IsValid())
		return false;

	// Defaults are captured only once. SaveMapping will replace this placeholder
	// with the player's new key while retaining OriginalKey.
	if (FindMappingInSavedArray(OriginalMapping) != -1)
		return true;

	MappingSaveObj->SavedMappings.Add(OriginalMapping);
	return UGameplayStatics::SaveGameToSlot(MappingSaveObj, MappingSaveName, 0);
}

void UInputUtilitySubsystem::SaveMapping(FSavedMapping NewMapping)
{
	if (!MappingSaveObj || !NewMapping.Action || !NewMapping.MappingContext)
		return;

	int32 ExistingIndex = FindMappingInSavedArray(NewMapping);
	if (ExistingIndex != -1)
	{
		// Preserve the original default key from the first save
		NewMapping.OriginalKey = MappingSaveObj->SavedMappings[ExistingIndex].OriginalKey;
		MappingSaveObj->SavedMappings.RemoveAt(ExistingIndex);
	}
	else if (!NewMapping.OriginalKey.IsValid())
	{
		// SaveMapping must be called before the caller changes the mapping context.
		// At this point, the context still contains the default key we need for reset.
		for (const FEnhancedActionKeyMapping& M : NewMapping.MappingContext->GetMappings())
		{
			if (M.Action == NewMapping.Action && M.Key.IsGamepadKey() == NewMapping.MappedKey.IsGamepadKey())
			{
				NewMapping.OriginalKey = M.Key;
				break;
			}
		}
	}

	MappingSaveObj->SavedMappings.Add(NewMapping);
	UGameplayStatics::SaveGameToSlot(MappingSaveObj, MappingSaveName, 0);
}

UMappingSave* UInputUtilitySubsystem::LoadMappingSaveObj()
{
	if (UGameplayStatics::DoesSaveGameExist(MappingSaveName, 0))
		return Cast<UMappingSave>(UGameplayStatics::LoadGameFromSlot(MappingSaveName, 0));
	else
		return Cast<UMappingSave>(UGameplayStatics::CreateSaveGameObject(UMappingSave::StaticClass()));
}

void UInputUtilitySubsystem::ApplyMappingSave(UMappingSave* MappingSave)
{
	if (!MappingSave)
		return;

	for (const FSavedMapping& MappingToApply : MappingSave->SavedMappings)
	{
		UInputMappingContext* MappingContext = MappingToApply.MappingContext;
		if (!MappingContext || !MappingToApply.Action || !MappingToApply.MappedKey.IsValid())
			continue;

		// The original key identifies the exact mapping to replace.  Matching only
		// by keyboard/gamepad type would replace the wrong binding when an action
		// has multiple keyboard or controller bindings.
		if (MappingToApply.OriginalKey.IsValid())
		{
			MappingContext->UnmapKey(MappingToApply.Action, MappingToApply.OriginalKey);
			MappingContext->MapKey(MappingToApply.Action, MappingToApply.MappedKey);
		}
	}
	TriggerRefresh();
}

void UInputUtilitySubsystem::ResetMappingsToDefault()
{
	if (bInProcessOfRemappingKey)
		return;
	
	for (const FSavedMapping& Saved : MappingSaveObj->SavedMappings)
	{
		if (!Saved.MappingContext || !Saved.Action || !Saved.MappedKey.IsValid() || !Saved.OriginalKey.IsValid())
			continue;

		// Remove the exact user-selected key, rather than the first binding with
		// the same device type. This keeps secondary bindings intact.
		Saved.MappingContext->UnmapKey(Saved.Action, Saved.MappedKey);

		bool bDefaultMappingAlreadyExists = false;
		for (const FEnhancedActionKeyMapping& Mapping : Saved.MappingContext->GetMappings())
		{
			if (Mapping.Action == Saved.Action && Mapping.Key == Saved.OriginalKey)
			{
				bDefaultMappingAlreadyExists = true;
				break;
			}
		}

		if (!bDefaultMappingAlreadyExists)
			Saved.MappingContext->MapKey(Saved.Action, Saved.OriginalKey);
	}

	UGameplayStatics::DeleteGameInSlot(MappingSaveName, 0);
	MappingSaveObj = Cast<UMappingSave>(UGameplayStatics::CreateSaveGameObject(UMappingSave::StaticClass()));
	TriggerRefresh();
}

int32 UInputUtilitySubsystem::FindMappingInSavedArray(FSavedMapping NewMapping)
{
	for (int i=0; i<MappingSaveObj->SavedMappings.Num(); i++)
	{
		if (MappingSaveObj->SavedMappings[i].Action == NewMapping.Action &&
			MappingSaveObj->SavedMappings[i].MappingContext == NewMapping.MappingContext &&
			MappingSaveObj->SavedMappings[i].MappedKey.IsGamepadKey() == NewMapping.MappedKey.IsGamepadKey())
		{
			return i;
		}
	}
	return -1;
}

void UInputUtilitySubsystem::SetUseAlternativeGamepadTexture(bool bNewValue)
{
	bUseAlternativeGamepadTextures = bNewValue;
}
