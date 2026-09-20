// Fill out your copyright notice in the Description page of Project Settings.


#include "InputUtilitiesFunctionLibrary.h"
#include "Engine/Texture2D.h"
#include "Engine/DataTable.h"
#include "InputAction.h"
#include "InputMappingContext.h"

UTexture2D* UInputUtilitiesFunctionLibrary::GetTextureForMappedAction(UInputAction* Action, UInputMappingContext* MappingContext, bool bGamepad, bool bUseAltTexture, UTexture2D* OverrideGamepadTexture, UTexture2D* OverrideMakTexture)
{
	if (!Action)
		return LoadObject<UTexture2D>(nullptr, TEXT("/InputUtilities/Textures/Errors/T_NoActionSelected.T_NoActionSelected"));

	if (!MappingContext)
		return LoadObject<UTexture2D>(nullptr, TEXT("/InputUtilities/Textures/Errors/T_NoMappingContextSelected.T_NoMappingContextSelected"));

	if (OverrideGamepadTexture && bGamepad)
		return OverrideGamepadTexture;

	if (OverrideMakTexture && !bGamepad)
		return OverrideMakTexture;

	FKey Key = GetMappedKeyForAction(Action, MappingContext, bGamepad);
	if (!Key.IsValid())
		return LoadObject<UTexture2D>(nullptr, TEXT("/InputUtilities/Textures/Errors/T_ActionIsNotMappedInContext.T_ActionIsNotMappedInContext"));

	UDataTable* DataTable = bGamepad
		? LoadObject<UDataTable>(nullptr, TEXT("/InputUtilities/DataTables/TextureTable_Gamepad.TextureTable_Gamepad"))
		: LoadObject<UDataTable>(nullptr, TEXT("/InputUtilities/DataTables/TextureTable_MaK.TextureTable_MaK"));

	if (!DataTable)
	{
		UE_LOG(LogTemp, Warning, TEXT("UInputUtilitiesFunctionLibrary::GetPromptTexture: DataTable isn't valid"));
		return nullptr;
	}

	TArray<FKeyTextures*> Rows;
	DataTable->GetAllRows("", Rows);

	for (FKeyTextures* Row : Rows)
	{
		if (Key == Row->Key)
		{
			TSoftObjectPtr<UTexture2D> TextureToLoad = (bGamepad && bUseAltTexture) ? Row->AltTexture : Row->KeyTexture;
			if (!TextureToLoad.IsNull())
				return TextureToLoad.LoadSynchronous();
			else
				return LoadObject<UTexture2D>(nullptr, TEXT("/InputUtilities/Textures/Errors/T_NoTextureAvailable.T_NoTextureAvailable"));
		}
	}

	return nullptr;
}

FKey UInputUtilitiesFunctionLibrary::GetMappedKeyForAction(UInputAction* Action, UInputMappingContext* MappingContext, bool bLookingForGamepadKey)
{
	TArray<FEnhancedActionKeyMapping> Mappings = MappingContext->GetMappings();
	for (FEnhancedActionKeyMapping Mapping : Mappings)
	{
		if (Mapping.Action == Action && Mapping.Key.IsGamepadKey() == bLookingForGamepadKey)
			return Mapping.Key;
	}
	return FKey();
}
