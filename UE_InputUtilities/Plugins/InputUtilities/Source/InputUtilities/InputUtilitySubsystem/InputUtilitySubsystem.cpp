// Fill out your copyright notice in the Description page of Project Settings.


#include "InputUtilitySubsystem.h"

#include "InputMappingContext.h"
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
	UE_LOG(LogTemp, Warning, TEXT("InputUtilitySubsystem: Initialize called"));
	UE_LOG(LogTemp, Warning, TEXT("InputUtilitySubsystem: Slate initialized = %s"), FSlateApplication::IsInitialized() ? TEXT("true") : TEXT("false"));

	InputProcessor = MakeShared<FInputUtilitiesInputProcessor>(this);
	bool bRegistered = FSlateApplication::Get().RegisterInputPreProcessor(InputProcessor);
	UE_LOG(LogTemp, Warning, TEXT("InputUtilitySubsystem: Processor registered = %s"), bRegistered ? TEXT("true") : TEXT("false"));


	this->MappingSaveObj = LoadMappingSaveObj();
	ApplyMappingSave(MappingSaveObj);
}

void UInputUtilitySubsystem::Deinitialize()
{
	if (FSlateApplication::IsInitialized() && InputProcessor.IsValid())
		FSlateApplication::Get().UnregisterInputPreProcessor(InputProcessor);

	Super::Deinitialize();
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
	if (!MappingSaveObj)
		return;

	//removing old mapping if it exists
	int index = FindMappingInSavedArray(NewMapping);
	if (index!=-1)
		MappingSaveObj->SavedMappings.RemoveAt(index);

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
	for (const FSavedMapping& MappingToApply : MappingSave->SavedMappings)
	{
		UInputMappingContext* MappingContext = MappingToApply.MappingContext;
		if (!MappingContext)
			continue;

		FKey OldKey;
		bool bFound = false;

		for (const FEnhancedActionKeyMapping& M : MappingContext->GetMappings())
		{
			if (M.Action == MappingToApply.Action && M.Key.IsGamepadKey() == MappingToApply.MappedKey.IsGamepadKey())
			{
				OldKey = M.Key;
				bFound = true;
				break;
			}
		}

		if (bFound)
		{
			MappingContext->UnmapKey(MappingToApply.Action, OldKey);
			MappingContext->MapKey(MappingToApply.Action, MappingToApply.MappedKey);
		}
	}
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
