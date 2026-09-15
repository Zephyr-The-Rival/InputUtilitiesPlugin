// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "InputUtilities/InputUtilitySubsystem/InputUtilitySubsystem.h"
#include "Engine/Classes/Engine/GameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInputUtilitySubsystem() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
	INPUTUTILITIES_API UClass* Z_Construct_UClass_UInputUtilitySubsystem();
	INPUTUTILITIES_API UClass* Z_Construct_UClass_UInputUtilitySubsystem_NoRegister();
	UPackage* Z_Construct_UPackage__Script_InputUtilities();
// End Cross Module References
	DEFINE_FUNCTION(UInputUtilitySubsystem::execSetUseAlternativeGamepadTexture)
	{
		P_GET_UBOOL(Z_Param_bNewValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetUseAlternativeGamepadTexture(Z_Param_bNewValue);
		P_NATIVE_END;
	}
	void UInputUtilitySubsystem::StaticRegisterNativesUInputUtilitySubsystem()
	{
		UClass* Class = UInputUtilitySubsystem::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "SetUseAlternativeGamepadTexture", &UInputUtilitySubsystem::execSetUseAlternativeGamepadTexture },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UInputUtilitySubsystem_SetUseAlternativeGamepadTexture_Statics
	{
		struct InputUtilitySubsystem_eventSetUseAlternativeGamepadTexture_Parms
		{
			bool bNewValue;
		};
		static void NewProp_bNewValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bNewValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UInputUtilitySubsystem_SetUseAlternativeGamepadTexture_Statics::NewProp_bNewValue_SetBit(void* Obj)
	{
		((InputUtilitySubsystem_eventSetUseAlternativeGamepadTexture_Parms*)Obj)->bNewValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInputUtilitySubsystem_SetUseAlternativeGamepadTexture_Statics::NewProp_bNewValue = { "bNewValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(InputUtilitySubsystem_eventSetUseAlternativeGamepadTexture_Parms), &Z_Construct_UFunction_UInputUtilitySubsystem_SetUseAlternativeGamepadTexture_Statics::NewProp_bNewValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInputUtilitySubsystem_SetUseAlternativeGamepadTexture_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInputUtilitySubsystem_SetUseAlternativeGamepadTexture_Statics::NewProp_bNewValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInputUtilitySubsystem_SetUseAlternativeGamepadTexture_Statics::Function_MetaDataParams[] = {
		{ "Category", "Input Utilities" },
		{ "ModuleRelativePath", "InputUtilitySubsystem/InputUtilitySubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInputUtilitySubsystem_SetUseAlternativeGamepadTexture_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInputUtilitySubsystem, nullptr, "SetUseAlternativeGamepadTexture", nullptr, nullptr, sizeof(Z_Construct_UFunction_UInputUtilitySubsystem_SetUseAlternativeGamepadTexture_Statics::InputUtilitySubsystem_eventSetUseAlternativeGamepadTexture_Parms), Z_Construct_UFunction_UInputUtilitySubsystem_SetUseAlternativeGamepadTexture_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInputUtilitySubsystem_SetUseAlternativeGamepadTexture_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UInputUtilitySubsystem_SetUseAlternativeGamepadTexture_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UInputUtilitySubsystem_SetUseAlternativeGamepadTexture_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UInputUtilitySubsystem_SetUseAlternativeGamepadTexture()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInputUtilitySubsystem_SetUseAlternativeGamepadTexture_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UInputUtilitySubsystem);
	UClass* Z_Construct_UClass_UInputUtilitySubsystem_NoRegister()
	{
		return UInputUtilitySubsystem::StaticClass();
	}
	struct Z_Construct_UClass_UInputUtilitySubsystem_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UInputUtilitySubsystem_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
		(UObject* (*)())Z_Construct_UPackage__Script_InputUtilities,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UInputUtilitySubsystem_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UInputUtilitySubsystem_SetUseAlternativeGamepadTexture, "SetUseAlternativeGamepadTexture" }, // 1266198508
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInputUtilitySubsystem_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "InputUtilitySubsystem/InputUtilitySubsystem.h" },
		{ "ModuleRelativePath", "InputUtilitySubsystem/InputUtilitySubsystem.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UInputUtilitySubsystem_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UInputUtilitySubsystem>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UInputUtilitySubsystem_Statics::ClassParams = {
		&UInputUtilitySubsystem::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UInputUtilitySubsystem_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UInputUtilitySubsystem_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UInputUtilitySubsystem()
	{
		if (!Z_Registration_Info_UClass_UInputUtilitySubsystem.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UInputUtilitySubsystem.OuterSingleton, Z_Construct_UClass_UInputUtilitySubsystem_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UInputUtilitySubsystem.OuterSingleton;
	}
	template<> INPUTUTILITIES_API UClass* StaticClass<UInputUtilitySubsystem>()
	{
		return UInputUtilitySubsystem::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UInputUtilitySubsystem);
	UInputUtilitySubsystem::~UInputUtilitySubsystem() {}
	struct Z_CompiledInDeferFile_FID_Users_oleor_Documents_GitHub_HobbyProject_InputUtilitiesPlugin_UE_InputUtilities_Plugins_InputUtilities_Source_InputUtilities_InputUtilitySubsystem_InputUtilitySubsystem_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_oleor_Documents_GitHub_HobbyProject_InputUtilitiesPlugin_UE_InputUtilities_Plugins_InputUtilities_Source_InputUtilities_InputUtilitySubsystem_InputUtilitySubsystem_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UInputUtilitySubsystem, UInputUtilitySubsystem::StaticClass, TEXT("UInputUtilitySubsystem"), &Z_Registration_Info_UClass_UInputUtilitySubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UInputUtilitySubsystem), 4040854213U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_oleor_Documents_GitHub_HobbyProject_InputUtilitiesPlugin_UE_InputUtilities_Plugins_InputUtilities_Source_InputUtilities_InputUtilitySubsystem_InputUtilitySubsystem_h_3446910622(TEXT("/Script/InputUtilities"),
		Z_CompiledInDeferFile_FID_Users_oleor_Documents_GitHub_HobbyProject_InputUtilitiesPlugin_UE_InputUtilities_Plugins_InputUtilities_Source_InputUtilities_InputUtilitySubsystem_InputUtilitySubsystem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_oleor_Documents_GitHub_HobbyProject_InputUtilitiesPlugin_UE_InputUtilities_Plugins_InputUtilities_Source_InputUtilities_InputUtilitySubsystem_InputUtilitySubsystem_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
