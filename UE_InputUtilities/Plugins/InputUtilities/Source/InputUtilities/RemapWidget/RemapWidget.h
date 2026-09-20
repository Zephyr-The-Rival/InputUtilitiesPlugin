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
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UInputAction* Action = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UInputMappingContext* MappingContext = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bRemappingForGamepad = false;

	UFUNCTION(BlueprintCallable)
	UTexture2D* GetActionTexture();
	
protected:
	virtual void Reinitialize() override;
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Refresh();
	void Refresh_Implementation();
};
