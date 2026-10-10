// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputUtilities/InputUtility_RefreshingWidget.h"
#include "RemapWidget.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS(Blueprintable)
class INPUTUTILITIES_API URemapWidget : public UInputUtility_RefreshingWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input Prompt")
	UInputAction* Action = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input Prompt")
	UInputMappingContext* MappingContext = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input Prompt")
	bool bRemappingForGamepad = false;

	UFUNCTION(BlueprintCallable, Category = "Input Utilities")
	UTexture2D* GetActionTexture();

protected:
	virtual void Reinitialize() override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Input Utilities")
	void Refresh();
	void Refresh_Implementation();
};
