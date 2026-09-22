// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "MappingSave.generated.h"

class UInputAction;
class UInputMappingContext;

USTRUCT(BlueprintType)
struct FSavedMapping
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame)
	UInputMappingContext* MappingContext;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame)
	UInputAction* Action;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame)
	FKey MappedKey;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame)
	FKey OriginalKey;
};

UCLASS()
class INPUTUTILITIES_API UMappingSave : public USaveGame
{
	GENERATED_BODY()
	
public:
	UPROPERTY(SaveGame)
	TArray<FSavedMapping> SavedMappings;
};
