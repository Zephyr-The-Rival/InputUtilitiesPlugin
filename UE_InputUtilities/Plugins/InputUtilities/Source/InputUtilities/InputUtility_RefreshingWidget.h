// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InputUtility_RefreshingWidget.generated.h"

/**
 * Base widget that automatically rebinds and refreshes when the input device changes.
 */
UCLASS()
class INPUTUTILITIES_API UInputUtility_RefreshingWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;
	virtual void NativePreConstruct() override;

	
	//override in children
	UFUNCTION(BlueprintCallable)
	virtual void Reinitialize();
};
