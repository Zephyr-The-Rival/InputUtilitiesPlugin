// Fill out your copyright notice in the Description page of Project Settings.


#include "InputUtilitySubsystem.h"
#include "Framework/Application/SlateApplication.h"

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

void UInputUtilitySubsystem::SetUseAlternativeGamepadTexture(bool bNewValue)
{
	bUseAlternativeGamepadTextures = bNewValue;
}
