// Fill out your copyright notice in the Description page of Project Settings.


#include "WidgetPrompt.h"
#include "Components/Image.h"
#include "InputUtilities/FunctionLibrary/InputUtilitiesFunctionLibrary.h"
#include "InputUtilities/InputUtilitySubsystem/InputUtilitySubsystem.h"

void UWidgetPrompt::Reinitialize()
{
	Super::Reinitialize();
	if (!PromptImage)
		return;

	bool bUseGamepad = false;
	bool bUseAlternative = false;
	
	if (UGameInstance* GameInstance = GetGameInstance()) 
	{
		if (UInputUtilitySubsystem* Subsystem = GameInstance->GetSubsystem<UInputUtilitySubsystem>())
		{
			bUseGamepad = Subsystem->bGamepadIsBeingUsed;
			bUseAlternative = Subsystem->GetUseAlternativeGamepadTextures();
		}
	}

	UTexture2D* Texture = UInputUtilitiesFunctionLibrary::GetTextureForMappedAction(
		Action,
		MappingContext,
		bUseGamepad,
		bUseAlternative,
		OverrideGamepadTexture,
		OverrideMakTexture);

	if (Texture)
		PromptImage->SetBrushFromTexture(Texture);
}
