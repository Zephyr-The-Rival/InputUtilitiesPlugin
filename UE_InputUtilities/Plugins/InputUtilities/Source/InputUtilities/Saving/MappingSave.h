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
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UInputMappingContext* MappingContext;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UInputAction* Action;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FKey MappedKey;
};

UCLASS()
class INPUTUTILITIES_API UMappingSave : public USaveGame
{
	GENERATED_BODY()
	
public:
	UPROPERTY()
	TArray<FSavedMapping> SavedMappings;
};
