// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Framework/Application/IInputProcessor.h"
#include "InputUtilitySubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FReinitializePromptsEvent);

class UInputUtilitySubsystem;

class FInputUtilitiesInputProcessor : public IInputProcessor
{
public:
	FInputUtilitiesInputProcessor(UInputUtilitySubsystem* InSubsystem) : Subsystem(InSubsystem) {}

	virtual void Tick(const float DeltaTime, FSlateApplication& SlateApp, TSharedRef<ICursor> Cursor) override {}

	virtual bool HandleKeyDownEvent(FSlateApplication& SlateApp, const FKeyEvent& InKeyEvent) override;
	virtual bool HandleMouseButtonDownEvent(FSlateApplication& SlateApp, const FPointerEvent& MouseEvent) override;

private:
	TWeakObjectPtr<UInputUtilitySubsystem> Subsystem;
};

UCLASS()
class INPUTUTILITIES_API UInputUtilitySubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	bool bGamepadIsBeingUsed = false;

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	void OnAnyKeyPressed(FKey Key);

	UFUNCTION(BlueprintCallable, Category = "Input Utilities")
	void SetUseAlternativeGamepadTexture(bool bNewValue);
	
	FReinitializePromptsEvent ReinitializePrompts;

private:
	bool bUseAlternativeGamepadTexture = false;
	TSharedPtr<FInputUtilitiesInputProcessor> InputProcessor;
};
