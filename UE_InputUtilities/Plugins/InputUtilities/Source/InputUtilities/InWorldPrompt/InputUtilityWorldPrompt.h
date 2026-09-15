// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InputUtilityWorldPrompt.generated.h"

class UInputAction;
class UInputMappingContext;
class UTexture2D;

UCLASS(Blueprintable)
class INPUTUTILITIES_API AInputUtilityWorldPrompt : public AActor
{
	GENERATED_BODY()

public:
	AInputUtilityWorldPrompt();
	virtual void OnConstruction(const FTransform& Transform) override;

protected:
	virtual void BeginPlay() override;
	


public:
	virtual void Tick(float DeltaTime) override;

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input Prompt")
	UStaticMeshComponent* Plane;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input Prompt")
	UInputAction* Action;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input Prompt")
	UInputMappingContext* MappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input Prompt")
	UTexture2D* OverrideGamepadTexture;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input Prompt")
	UTexture2D* OverrideMakTexture;
	
private:
	void InitializePrompt();
	
	UMaterialInstanceDynamic* DynMat;
};
