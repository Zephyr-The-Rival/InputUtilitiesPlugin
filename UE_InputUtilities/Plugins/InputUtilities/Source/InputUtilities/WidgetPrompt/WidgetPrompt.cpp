// Fill out your copyright notice in the Description page of Project Settings.


#include "WidgetPrompt.h"
#include "Components/Image.h"
#include "InputUtilities/FunctionLibrary/InputUtilitiesFunctionLibrary.h"
#include "InputUtilities/InputUtilitySubsystem/InputUtilitySubsystem.h"

void UWidgetPrompt::NativeConstruct()
{
	Super::NativeConstruct();
	InitializePrompt();

	UInputUtilitySubsystem* Subsystem = GetGameInstance()->GetSubsystem<UInputUtilitySubsystem>();
	if (Subsystem)
		Subsystem->ReinitializePrompts.AddDynamic(this, &UWidgetPrompt::InitializePrompt);
}

void UWidgetPrompt::NativePreConstruct()
{
	Super::NativePreConstruct();
	InitializePrompt();
}

void UWidgetPrompt::InitializePrompt()
{
	if (!PromptImage)
		return;

	bool bUseGamepad = false;

	UGameInstance* GameInstance = GetGameInstance();
	if (GameInstance)
	{
		UInputUtilitySubsystem* Subsystem = GameInstance->GetSubsystem<UInputUtilitySubsystem>();
		if (Subsystem)
			bUseGamepad = Subsystem->bGamepadIsBeingUsed;
	}

	UTexture2D* Texture = UInputUtilitiesFunctionLibrary::GetTextureForMappedAction(
		Action, MappingContext, OverrideGamepadTexture, OverrideMakTexture, bUseGamepad);

	if (Texture)
		PromptImage->SetBrushFromTexture(Texture);
}
