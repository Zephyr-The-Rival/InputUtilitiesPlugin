// Fill out your copyright notice in the Description page of Project Settings.


#include "InputUtility_RefreshingWidget.h"
#include "InputUtilities/InputUtilitySubsystem/InputUtilitySubsystem.h"

void UInputUtility_RefreshingWidget::NativeConstruct()
{
	Super::NativeConstruct();
	Reinitialize();

	if (UGameInstance* GameInstance = GetGameInstance())
		if (UInputUtilitySubsystem* Subsystem = GameInstance->GetSubsystem<UInputUtilitySubsystem>())
			Subsystem->ReinitializePrompts.AddDynamic(this, &UInputUtility_RefreshingWidget::Reinitialize);
}

void UInputUtility_RefreshingWidget::NativePreConstruct()
{
	Super::NativePreConstruct();
	Reinitialize();
}

void UInputUtility_RefreshingWidget::Reinitialize()
{
	//override in BP
}