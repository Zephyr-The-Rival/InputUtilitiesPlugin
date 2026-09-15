// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "InputUtilitySubsystem.generated.h"

class UTexture2D;
class UInputAction;
class UInputMappingContext;

UCLASS()
class INPUTUTILITIES_API UInputUtilitySubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	bool bGamepadIsBeingUsed = false;
	
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	void OnAnyKeyPressed(FKey Key);
	void OnWorldInitialized(const UWorld::FActorsInitializedParams& Params);
	
	UFUNCTION(BlueprintCallable, Category = "Input Utilities")
	void SetUseAlternativeGamepadTexture(bool bNewValue);

private:
	bool bUseAlternativeGamepadTexture = false;
};
