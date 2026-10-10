// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "InputUtilitiesSettings.generated.h"

class UInputMappingContext;

UCLASS(config = Game, defaultconfig, meta = (DisplayName = "Input Utilities"))
class INPUTUTILITIES_API UInputUtilitiesSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	// Every Input Mapping Context the plugin should know about. Their default
	// key bindings are snapshotted at startup, before any saved remap is applied,
	// so that mappings can reliably be restored to default later.
	UPROPERTY(EditAnywhere, config, Category = "Mapping Contexts")
	TArray<TSoftObjectPtr<UInputMappingContext>> ManagedMappingContexts;

	virtual FName GetCategoryName() const override { return FName("Plugins"); }
};
