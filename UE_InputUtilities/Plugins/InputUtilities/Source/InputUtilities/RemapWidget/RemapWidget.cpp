// Fill out your copyright notice in the Description page of Project Settings.


#include "RemapWidget.h"

#include "InputUtilities/FunctionLibrary/InputUtilitiesFunctionLibrary.h"
#include "InputUtilities/InputUtilitySubsystem/InputUtilitySubsystem.h"

UTexture2D* URemapWidget::GetActionTexture()
{
	bool bUseAlternative = false;

	if (UGameInstance* GameInstance = GetGameInstance())
	{
		if (UInputUtilitySubsystem* Subsystem = GameInstance->GetSubsystem<UInputUtilitySubsystem>())
		{
			bUseAlternative = Subsystem->GetUseAlternativeGamepadTextures();
		}		
	}
	
	return UInputUtilitiesFunctionLibrary::GetTextureForMappedAction(Action, MappingContext, this->bRemappingForGamepad, bUseAlternative);
}

void URemapWidget::Reinitialize()
{
	Super::Reinitialize();
	Refresh();
}

void URemapWidget::Refresh_Implementation()
{
	//override in bp
}
