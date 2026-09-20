// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Framework/Application/IInputProcessor.h"
#include "InputUtilitySubsystem.generated.h"

class UMappingSave;
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
	bool GetUseAlternativeGamepadTextures() const {return this->bUseAlternativeGamepadTextures;}
	
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

private:
	bool bUseAlternativeGamepadTextures = false;
	TSharedPtr<FInputUtilitiesInputProcessor> InputProcessor;
	
	
	//Saving
public:

	UFUNCTION(BlueprintCallable)
	void SaveMapping(FSavedMapping NewMapping);
	UMappingSave* LoadMappingSaveObj();
	void ApplyMappingSave(UMappingSave* MappingSave);
	
private:
	FString MappingSaveName = "Saved Input Mappings";
	UMappingSave* MappingSaveObj = nullptr;
	
	//returns -1 if not found
	int32 FindMappingInSavedArray(FSavedMapping NewMapping);
};
