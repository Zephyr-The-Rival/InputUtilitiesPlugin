// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine/DataTable.h"
#include "InputUtilitiesFunctionLibrary.generated.h"

class UTexture2D;
class UInputAction;
class UInputMappingContext;

USTRUCT(BlueprintType)
struct FKeyTextures : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FKey Key;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<UTexture2D> KeyTexture;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<UTexture2D> AltTexture;
};

UCLASS()
class INPUTUTILITIES_API UInputUtilitiesFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Input Utilities")
	static UTexture2D* GetTextureForMappedAction(
		UInputAction* Action,
		UInputMappingContext* MappingContext,
		bool bGamepad,
		bool bUseAltTexture = false,
		UTexture2D* OverrideGamepadTexture = nullptr,
		UTexture2D* OverrideMakTexture = nullptr);

	UFUNCTION(BlueprintCallable, Category="Input Utilities")
	static FKey GetMappedKeyForAction(UInputAction* Action, UInputMappingContext* MappingContext, bool bLookingForGamepadKey);
};
