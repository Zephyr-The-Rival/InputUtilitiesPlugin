// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Framework/Application/IInputProcessor.h"
#include "Engine/World.h"
#include "InputUtilities/Saving/InputUserSettings.h"
#include "InputUtilitySubsystem.generated.h"

class UInputUserSettings;
struct FSavedMapping;
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FReinitializePromptsEvent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAnyKeyPressedEvent, FKey, Key);

class UInputUtilitySubsystem;

class FInputUtilitiesInputProcessor : public IInputProcessor
{
public:
	FInputUtilitiesInputProcessor(UInputUtilitySubsystem* InSubsystem) : Subsystem(InSubsystem) {}

	virtual void Tick(const float DeltaTime, FSlateApplication& SlateApp, TSharedRef<ICursor> Cursor) override {}

	virtual bool HandleKeyDownEvent(FSlateApplication& SlateApp, const FKeyEvent& InKeyEvent) override;
	virtual bool HandleMouseButtonDownEvent(FSlateApplication& SlateApp, const FPointerEvent& MouseEvent) override;
	virtual bool HandleMouseWheelOrGestureEvent(FSlateApplication& SlateApp, const FPointerEvent& InWheelEvent, const FPointerEvent* InGestureEvent) override;

private:
	TWeakObjectPtr<UInputUtilitySubsystem> Subsystem;
};

UCLASS()
class INPUTUTILITIES_API UInputUtilitySubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	bool bGamepadIsBeingUsed = false;
	
	UFUNCTION(BlueprintCallable, Category = "Input Utilities")
	bool GetUseAlternativeGamepadTextures() const { return UserSettings ? UserSettings->bUseAlternativeGamepadTextures : false; }

	UFUNCTION(BlueprintCallable, Category = "Input Utilities")
	void SetUseAlternativeGamepadTexture(bool bNewValue);

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	void OnAnyKeyPressed(FKey Key);
	
	UPROPERTY(BlueprintAssignable, Category="Input Utilities")
	FReinitializePromptsEvent ReinitializePrompts;

	UPROPERTY(BlueprintAssignable, Category="Input Utilities")
	FOnAnyKeyPressedEvent OnAnyKeyPressedEvent;
	
	UFUNCTION(BlueprintCallable)
	void TriggerRefresh();

	UPROPERTY(BlueprintReadWrite)
	bool bInProcessOfRemappingKey = false;
private:
	TSharedPtr<FInputUtilitiesInputProcessor> InputProcessor;

	

	//Saving
public:
	// Call before changing a mapping context to record the key that Reset should restore.
	UFUNCTION(BlueprintCallable, Category="Input Utilities|Saving")
	bool SaveOriginalMapping(UInputAction* Action, UInputMappingContext* MappingContext, bool bForGamepad);

	UFUNCTION(BlueprintCallable)
	void SaveMapping(FSavedMapping NewMapping);
	UInputUserSettings* LoadUserSettings();
	void ApplyMappingSave(UInputUserSettings* Settings);

	UFUNCTION(BlueprintCallable)
	void ResetMappingsToDefault();

private:
	FString UserSettingsSaveSlotName = "Input User Settings";
	UInputUserSettings* UserSettings = nullptr;

	// The true default key for every binding in every context listed in
	// UInputUtilitiesSettings. Captured once in Initialize(), before any saved
	// remap is applied, so Reset and Deinitialize always have a reliable
	// baseline to restore to (editor PIE sessions reuse the same in-memory
	// context asset, so this must not be re-derived from runtime context state).
	TArray<FSavedMapping> DefaultMappings;

	void OnWorldTickStart(UWorld* InWorld, ELevelTick TickType, float DeltaSeconds);
	void CaptureDefaultMappings();
	void RevertContextsToDefault();

	//returns -1 if not found
	int32 FindMappingInSavedArray(FSavedMapping NewMapping);
};
