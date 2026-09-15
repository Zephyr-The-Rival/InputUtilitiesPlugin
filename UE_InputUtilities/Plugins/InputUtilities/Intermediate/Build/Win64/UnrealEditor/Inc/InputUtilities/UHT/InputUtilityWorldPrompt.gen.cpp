// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "InputUtilities/InWorldPrompt/InputUtilityWorldPrompt.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInputUtilityWorldPrompt() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
	INPUTUTILITIES_API UClass* Z_Construct_UClass_AInputUtilityWorldPrompt();
	INPUTUTILITIES_API UClass* Z_Construct_UClass_AInputUtilityWorldPrompt_NoRegister();
	UPackage* Z_Construct_UPackage__Script_InputUtilities();
// End Cross Module References
	void AInputUtilityWorldPrompt::StaticRegisterNativesAInputUtilityWorldPrompt()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AInputUtilityWorldPrompt);
	UClass* Z_Construct_UClass_AInputUtilityWorldPrompt_NoRegister()
	{
		return AInputUtilityWorldPrompt::StaticClass();
	}
	struct Z_Construct_UClass_AInputUtilityWorldPrompt_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Plane_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Plane;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Action_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Action;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MappingContext_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MappingContext;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OverrideGamepadTexture_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_OverrideGamepadTexture;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OverrideMakTexture_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_OverrideMakTexture;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AInputUtilityWorldPrompt_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_InputUtilities,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AInputUtilityWorldPrompt_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "InWorldPrompt/InputUtilityWorldPrompt.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "InWorldPrompt/InputUtilityWorldPrompt.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AInputUtilityWorldPrompt_Statics::NewProp_Plane_MetaData[] = {
		{ "Category", "Input Prompt" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "InWorldPrompt/InputUtilityWorldPrompt.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AInputUtilityWorldPrompt_Statics::NewProp_Plane = { "Plane", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AInputUtilityWorldPrompt, Plane), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AInputUtilityWorldPrompt_Statics::NewProp_Plane_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AInputUtilityWorldPrompt_Statics::NewProp_Plane_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AInputUtilityWorldPrompt_Statics::NewProp_Action_MetaData[] = {
		{ "Category", "Input Prompt" },
		{ "ModuleRelativePath", "InWorldPrompt/InputUtilityWorldPrompt.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AInputUtilityWorldPrompt_Statics::NewProp_Action = { "Action", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AInputUtilityWorldPrompt, Action), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AInputUtilityWorldPrompt_Statics::NewProp_Action_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AInputUtilityWorldPrompt_Statics::NewProp_Action_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AInputUtilityWorldPrompt_Statics::NewProp_MappingContext_MetaData[] = {
		{ "Category", "Input Prompt" },
		{ "ModuleRelativePath", "InWorldPrompt/InputUtilityWorldPrompt.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AInputUtilityWorldPrompt_Statics::NewProp_MappingContext = { "MappingContext", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AInputUtilityWorldPrompt, MappingContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AInputUtilityWorldPrompt_Statics::NewProp_MappingContext_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AInputUtilityWorldPrompt_Statics::NewProp_MappingContext_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AInputUtilityWorldPrompt_Statics::NewProp_OverrideGamepadTexture_MetaData[] = {
		{ "Category", "Input Prompt" },
		{ "ModuleRelativePath", "InWorldPrompt/InputUtilityWorldPrompt.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AInputUtilityWorldPrompt_Statics::NewProp_OverrideGamepadTexture = { "OverrideGamepadTexture", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AInputUtilityWorldPrompt, OverrideGamepadTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AInputUtilityWorldPrompt_Statics::NewProp_OverrideGamepadTexture_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AInputUtilityWorldPrompt_Statics::NewProp_OverrideGamepadTexture_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AInputUtilityWorldPrompt_Statics::NewProp_OverrideMakTexture_MetaData[] = {
		{ "Category", "Input Prompt" },
		{ "ModuleRelativePath", "InWorldPrompt/InputUtilityWorldPrompt.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AInputUtilityWorldPrompt_Statics::NewProp_OverrideMakTexture = { "OverrideMakTexture", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AInputUtilityWorldPrompt, OverrideMakTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AInputUtilityWorldPrompt_Statics::NewProp_OverrideMakTexture_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AInputUtilityWorldPrompt_Statics::NewProp_OverrideMakTexture_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AInputUtilityWorldPrompt_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AInputUtilityWorldPrompt_Statics::NewProp_Plane,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AInputUtilityWorldPrompt_Statics::NewProp_Action,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AInputUtilityWorldPrompt_Statics::NewProp_MappingContext,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AInputUtilityWorldPrompt_Statics::NewProp_OverrideGamepadTexture,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AInputUtilityWorldPrompt_Statics::NewProp_OverrideMakTexture,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AInputUtilityWorldPrompt_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AInputUtilityWorldPrompt>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AInputUtilityWorldPrompt_Statics::ClassParams = {
		&AInputUtilityWorldPrompt::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AInputUtilityWorldPrompt_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AInputUtilityWorldPrompt_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AInputUtilityWorldPrompt_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AInputUtilityWorldPrompt_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AInputUtilityWorldPrompt()
	{
		if (!Z_Registration_Info_UClass_AInputUtilityWorldPrompt.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AInputUtilityWorldPrompt.OuterSingleton, Z_Construct_UClass_AInputUtilityWorldPrompt_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AInputUtilityWorldPrompt.OuterSingleton;
	}
	template<> INPUTUTILITIES_API UClass* StaticClass<AInputUtilityWorldPrompt>()
	{
		return AInputUtilityWorldPrompt::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AInputUtilityWorldPrompt);
	AInputUtilityWorldPrompt::~AInputUtilityWorldPrompt() {}
	struct Z_CompiledInDeferFile_FID_Users_oleor_Documents_GitHub_HobbyProject_InputUtilitiesPlugin_UE_InputUtilities_Plugins_InputUtilities_Source_InputUtilities_InWorldPrompt_InputUtilityWorldPrompt_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_oleor_Documents_GitHub_HobbyProject_InputUtilitiesPlugin_UE_InputUtilities_Plugins_InputUtilities_Source_InputUtilities_InWorldPrompt_InputUtilityWorldPrompt_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AInputUtilityWorldPrompt, AInputUtilityWorldPrompt::StaticClass, TEXT("AInputUtilityWorldPrompt"), &Z_Registration_Info_UClass_AInputUtilityWorldPrompt, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AInputUtilityWorldPrompt), 3190433836U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_oleor_Documents_GitHub_HobbyProject_InputUtilitiesPlugin_UE_InputUtilities_Plugins_InputUtilities_Source_InputUtilities_InWorldPrompt_InputUtilityWorldPrompt_h_1548505233(TEXT("/Script/InputUtilities"),
		Z_CompiledInDeferFile_FID_Users_oleor_Documents_GitHub_HobbyProject_InputUtilitiesPlugin_UE_InputUtilities_Plugins_InputUtilities_Source_InputUtilities_InWorldPrompt_InputUtilityWorldPrompt_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_oleor_Documents_GitHub_HobbyProject_InputUtilitiesPlugin_UE_InputUtilities_Plugins_InputUtilities_Source_InputUtilities_InWorldPrompt_InputUtilityWorldPrompt_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
