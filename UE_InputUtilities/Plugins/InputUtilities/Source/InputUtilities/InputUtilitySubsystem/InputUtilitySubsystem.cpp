// Fill out your copyright notice in the Description page of Project Settings.


#include "InputUtilitySubsystem.h"

void UInputUtilitySubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	FWorldDelegates::OnWorldInitializedActors.AddUObject(this, &UInputUtilitySubsystem::OnWorldInitialized);
}

void UInputUtilitySubsystem::OnAnyKeyPressed(FKey Key)
{
	UE_LOG(LogTemp, Warning, TEXT("UInputUtilitySubsystem::OnAnyKeyPressed"));
	bGamepadIsBeingUsed = Key.IsGamepadKey();
}

void UInputUtilitySubsystem::OnWorldInitialized(const UWorld::FActorsInitializedParams& Params)
{
	APlayerController* PC = GetGameInstance()->GetFirstLocalPlayerController(Params.World);
	if (!PC || !PC->InputComponent)
	{
		// PC not ready yet, bind to tick or PostLogin
		Params.World->GetTimerManager().SetTimerForNextTick([this, World = Params.World]()
		{
			APlayerController* PC = GetGameInstance()->GetFirstLocalPlayerController(World);
			if (PC && PC->InputComponent)
			{
				FInputKeyBinding KB(EKeys::AnyKey, IE_Pressed);
				KB.KeyDelegate.BindDelegate(this, &UInputUtilitySubsystem::OnAnyKeyPressed);
				PC->InputComponent->KeyBindings.Add(KB);
			}
		});
		return;
	}

	FInputKeyBinding KB(EKeys::AnyKey, IE_Pressed);
	KB.KeyDelegate.BindDelegate(this, &UInputUtilitySubsystem::OnAnyKeyPressed);
	PC->InputComponent->KeyBindings.Add(KB);
}

void UInputUtilitySubsystem::SetUseAlternativeGamepadTexture(bool bNewValue)
{
	bUseAlternativeGamepadTexture = bNewValue;
}
