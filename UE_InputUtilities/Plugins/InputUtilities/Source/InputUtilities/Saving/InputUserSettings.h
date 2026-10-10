// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "InputUserSettings.generated.h"

class UInputAction;
class UInputMappingContext;

USTRUCT(BlueprintType)
struct FSavedMapping
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category = "InputUtilities")
	UInputMappingContext* MappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category = "InputUtilities")
	UInputAction* Action;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category = "InputUtilities")
	FKey MappedKey;
};

// Persisted per-player input preferences: key remaps and misc settings like
// which prompt texture style to use. Not "a save game" in the narrative
// sense - USaveGame is just Epic's generic on-disk UObject container.
UCLASS()
class INPUTUTILITIES_API UInputUserSettings : public USaveGame
{
	GENERATED_BODY()

public:
	UPROPERTY(SaveGame)
	TArray<FSavedMapping> SavedMappings;

	UPROPERTY(SaveGame)
	bool bUseAlternativeGamepadTextures = false;
};
