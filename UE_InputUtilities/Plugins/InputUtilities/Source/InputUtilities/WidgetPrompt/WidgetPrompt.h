// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WidgetPrompt.generated.h"

class UImage;
class UInputAction;
class UInputMappingContext;
class UTexture2D;

UCLASS(Blueprintable)
class INPUTUTILITIES_API UWidgetPrompt : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input Prompt")
	UInputAction* Action;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input Prompt")
	UInputMappingContext* MappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input Prompt")
	UTexture2D* OverrideGamepadTexture;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input Prompt")
	UTexture2D* OverrideMakTexture;

protected:
	UPROPERTY(meta=(BindWidget))
	UImage* PromptImage;

	virtual void NativeConstruct() override;
	virtual void NativePreConstruct() override;

private:
	UFUNCTION()
	void InitializePrompt();
};
