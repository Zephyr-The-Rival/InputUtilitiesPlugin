// Fill out your copyright notice in the Description page of Project Settings.


#include "InputUtilityWorldPrompt.h"
#include "InputUtilities/FunctionLibrary/InputUtilitiesFunctionLibrary.h"
#include "InputUtilities/InputUtilitySubsystem/InputUtilitySubsystem.h"


// Sets default values
AInputUtilityWorldPrompt::AInputUtilityWorldPrompt()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	this->Plane = CreateDefaultSubobject<UStaticMeshComponent>("Plane");
	this->RootComponent = Plane;
}

// Called when the game starts or when spawned
void AInputUtilityWorldPrompt::BeginPlay()
{
	Super::BeginPlay();
	InitializePrompt();
	
	if (UInputUtilitySubsystem* Subsystem = GetGameInstance()->GetSubsystem<UInputUtilitySubsystem>())
		Subsystem->ReinitializePrompts.AddDynamic(this, &AInputUtilityWorldPrompt::InitializePrompt);
}

void AInputUtilityWorldPrompt::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	InitializePrompt();
}

// Called every frame
void AInputUtilityWorldPrompt::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AInputUtilityWorldPrompt::InitializePrompt()
{
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
	
	UTexture2D* texture = UInputUtilitiesFunctionLibrary::GetTextureForMappedAction(
		Action,
		MappingContext,
		bUseGamepad,
		bUseAlternative,
		OverrideGamepadTexture,
		OverrideMakTexture);
	
	DynMat = Plane->CreateDynamicMaterialInstance(0);
	if (!DynMat)
		return;
	
	DynMat->SetTextureParameterValue("Texture", texture);
}

