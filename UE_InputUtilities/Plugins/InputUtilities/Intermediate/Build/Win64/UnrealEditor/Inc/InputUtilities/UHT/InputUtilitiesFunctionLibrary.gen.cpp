// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "InputUtilities/FunctionLibrary/InputUtilitiesFunctionLibrary.h"
#include "InputCore/Classes/InputCoreTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInputUtilitiesFunctionLibrary() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FTableRowBase();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
	INPUTCORE_API UScriptStruct* Z_Construct_UScriptStruct_FKey();
	INPUTUTILITIES_API UClass* Z_Construct_UClass_UInputUtilitiesFunctionLibrary();
	INPUTUTILITIES_API UClass* Z_Construct_UClass_UInputUtilitiesFunctionLibrary_NoRegister();
	INPUTUTILITIES_API UScriptStruct* Z_Construct_UScriptStruct_FKeyTextures();
	UPackage* Z_Construct_UPackage__Script_InputUtilities();
// End Cross Module References

static_assert(std::is_polymorphic<FKeyTextures>() == std::is_polymorphic<FTableRowBase>(), "USTRUCT FKeyTextures cannot be polymorphic unless super FTableRowBase is polymorphic");

	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_KeyTextures;
class UScriptStruct* FKeyTextures::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_KeyTextures.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_KeyTextures.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FKeyTextures, Z_Construct_UPackage__Script_InputUtilities(), TEXT("KeyTextures"));
	}
	return Z_Registration_Info_UScriptStruct_KeyTextures.OuterSingleton;
}
template<> INPUTUTILITIES_API UScriptStruct* StaticStruct<FKeyTextures>()
{
	return FKeyTextures::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FKeyTextures_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Key_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Key;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_KeyTexture_MetaData[];
#endif
		static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_KeyTexture;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AltTexture_MetaData[];
#endif
		static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_AltTexture;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FKeyTextures_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "FunctionLibrary/InputUtilitiesFunctionLibrary.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FKeyTextures_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FKeyTextures>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FKeyTextures_Statics::NewProp_Key_MetaData[] = {
		{ "Category", "KeyTextures" },
		{ "ModuleRelativePath", "FunctionLibrary/InputUtilitiesFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FKeyTextures_Statics::NewProp_Key = { "Key", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FKeyTextures, Key), Z_Construct_UScriptStruct_FKey, METADATA_PARAMS(Z_Construct_UScriptStruct_FKeyTextures_Statics::NewProp_Key_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FKeyTextures_Statics::NewProp_Key_MetaData)) }; // 2101135134
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FKeyTextures_Statics::NewProp_KeyTexture_MetaData[] = {
		{ "Category", "KeyTextures" },
		{ "ModuleRelativePath", "FunctionLibrary/InputUtilitiesFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UScriptStruct_FKeyTextures_Statics::NewProp_KeyTexture = { "KeyTexture", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FKeyTextures, KeyTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FKeyTextures_Statics::NewProp_KeyTexture_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FKeyTextures_Statics::NewProp_KeyTexture_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FKeyTextures_Statics::NewProp_AltTexture_MetaData[] = {
		{ "Category", "KeyTextures" },
		{ "ModuleRelativePath", "FunctionLibrary/InputUtilitiesFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UScriptStruct_FKeyTextures_Statics::NewProp_AltTexture = { "AltTexture", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FKeyTextures, AltTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FKeyTextures_Statics::NewProp_AltTexture_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FKeyTextures_Statics::NewProp_AltTexture_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FKeyTextures_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FKeyTextures_Statics::NewProp_Key,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FKeyTextures_Statics::NewProp_KeyTexture,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FKeyTextures_Statics::NewProp_AltTexture,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FKeyTextures_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_InputUtilities,
		Z_Construct_UScriptStruct_FTableRowBase,
		&NewStructOps,
		"KeyTextures",
		sizeof(FKeyTextures),
		alignof(FKeyTextures),
		Z_Construct_UScriptStruct_FKeyTextures_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FKeyTextures_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FKeyTextures_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FKeyTextures_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FKeyTextures()
	{
		if (!Z_Registration_Info_UScriptStruct_KeyTextures.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_KeyTextures.InnerSingleton, Z_Construct_UScriptStruct_FKeyTextures_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_KeyTextures.InnerSingleton;
	}
	DEFINE_FUNCTION(UInputUtilitiesFunctionLibrary::execGetTextureForMappedAction)
	{
		P_GET_OBJECT(UInputAction,Z_Param_Action);
		P_GET_OBJECT(UInputMappingContext,Z_Param_MappingContext);
		P_GET_OBJECT(UTexture2D,Z_Param_OverrideGamepadTexture);
		P_GET_OBJECT(UTexture2D,Z_Param_OverrideMakTexture);
		P_GET_UBOOL(Z_Param_bGamepad);
		P_GET_UBOOL(Z_Param_bUseAltTexture);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UTexture2D**)Z_Param__Result=UInputUtilitiesFunctionLibrary::GetTextureForMappedAction(Z_Param_Action,Z_Param_MappingContext,Z_Param_OverrideGamepadTexture,Z_Param_OverrideMakTexture,Z_Param_bGamepad,Z_Param_bUseAltTexture);
		P_NATIVE_END;
	}
	void UInputUtilitiesFunctionLibrary::StaticRegisterNativesUInputUtilitiesFunctionLibrary()
	{
		UClass* Class = UInputUtilitiesFunctionLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetTextureForMappedAction", &UInputUtilitiesFunctionLibrary::execGetTextureForMappedAction },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UInputUtilitiesFunctionLibrary_GetTextureForMappedAction_Statics
	{
		struct InputUtilitiesFunctionLibrary_eventGetTextureForMappedAction_Parms
		{
			UInputAction* Action;
			UInputMappingContext* MappingContext;
			UTexture2D* OverrideGamepadTexture;
			UTexture2D* OverrideMakTexture;
			bool bGamepad;
			bool bUseAltTexture;
			UTexture2D* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Action;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MappingContext;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_OverrideGamepadTexture;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_OverrideMakTexture;
		static void NewProp_bGamepad_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bGamepad;
		static void NewProp_bUseAltTexture_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseAltTexture;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInputUtilitiesFunctionLibrary_GetTextureForMappedAction_Statics::NewProp_Action = { "Action", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(InputUtilitiesFunctionLibrary_eventGetTextureForMappedAction_Parms, Action), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInputUtilitiesFunctionLibrary_GetTextureForMappedAction_Statics::NewProp_MappingContext = { "MappingContext", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(InputUtilitiesFunctionLibrary_eventGetTextureForMappedAction_Parms, MappingContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInputUtilitiesFunctionLibrary_GetTextureForMappedAction_Statics::NewProp_OverrideGamepadTexture = { "OverrideGamepadTexture", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(InputUtilitiesFunctionLibrary_eventGetTextureForMappedAction_Parms, OverrideGamepadTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInputUtilitiesFunctionLibrary_GetTextureForMappedAction_Statics::NewProp_OverrideMakTexture = { "OverrideMakTexture", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(InputUtilitiesFunctionLibrary_eventGetTextureForMappedAction_Parms, OverrideMakTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UInputUtilitiesFunctionLibrary_GetTextureForMappedAction_Statics::NewProp_bGamepad_SetBit(void* Obj)
	{
		((InputUtilitiesFunctionLibrary_eventGetTextureForMappedAction_Parms*)Obj)->bGamepad = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInputUtilitiesFunctionLibrary_GetTextureForMappedAction_Statics::NewProp_bGamepad = { "bGamepad", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(InputUtilitiesFunctionLibrary_eventGetTextureForMappedAction_Parms), &Z_Construct_UFunction_UInputUtilitiesFunctionLibrary_GetTextureForMappedAction_Statics::NewProp_bGamepad_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UInputUtilitiesFunctionLibrary_GetTextureForMappedAction_Statics::NewProp_bUseAltTexture_SetBit(void* Obj)
	{
		((InputUtilitiesFunctionLibrary_eventGetTextureForMappedAction_Parms*)Obj)->bUseAltTexture = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInputUtilitiesFunctionLibrary_GetTextureForMappedAction_Statics::NewProp_bUseAltTexture = { "bUseAltTexture", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(InputUtilitiesFunctionLibrary_eventGetTextureForMappedAction_Parms), &Z_Construct_UFunction_UInputUtilitiesFunctionLibrary_GetTextureForMappedAction_Statics::NewProp_bUseAltTexture_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInputUtilitiesFunctionLibrary_GetTextureForMappedAction_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(InputUtilitiesFunctionLibrary_eventGetTextureForMappedAction_Parms, ReturnValue), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInputUtilitiesFunctionLibrary_GetTextureForMappedAction_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInputUtilitiesFunctionLibrary_GetTextureForMappedAction_Statics::NewProp_Action,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInputUtilitiesFunctionLibrary_GetTextureForMappedAction_Statics::NewProp_MappingContext,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInputUtilitiesFunctionLibrary_GetTextureForMappedAction_Statics::NewProp_OverrideGamepadTexture,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInputUtilitiesFunctionLibrary_GetTextureForMappedAction_Statics::NewProp_OverrideMakTexture,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInputUtilitiesFunctionLibrary_GetTextureForMappedAction_Statics::NewProp_bGamepad,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInputUtilitiesFunctionLibrary_GetTextureForMappedAction_Statics::NewProp_bUseAltTexture,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInputUtilitiesFunctionLibrary_GetTextureForMappedAction_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInputUtilitiesFunctionLibrary_GetTextureForMappedAction_Statics::Function_MetaDataParams[] = {
		{ "Category", "Input Utilities" },
		{ "CPP_Default_bUseAltTexture", "false" },
		{ "ModuleRelativePath", "FunctionLibrary/InputUtilitiesFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInputUtilitiesFunctionLibrary_GetTextureForMappedAction_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInputUtilitiesFunctionLibrary, nullptr, "GetTextureForMappedAction", nullptr, nullptr, sizeof(Z_Construct_UFunction_UInputUtilitiesFunctionLibrary_GetTextureForMappedAction_Statics::InputUtilitiesFunctionLibrary_eventGetTextureForMappedAction_Parms), Z_Construct_UFunction_UInputUtilitiesFunctionLibrary_GetTextureForMappedAction_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInputUtilitiesFunctionLibrary_GetTextureForMappedAction_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UInputUtilitiesFunctionLibrary_GetTextureForMappedAction_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UInputUtilitiesFunctionLibrary_GetTextureForMappedAction_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UInputUtilitiesFunctionLibrary_GetTextureForMappedAction()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInputUtilitiesFunctionLibrary_GetTextureForMappedAction_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UInputUtilitiesFunctionLibrary);
	UClass* Z_Construct_UClass_UInputUtilitiesFunctionLibrary_NoRegister()
	{
		return UInputUtilitiesFunctionLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UInputUtilitiesFunctionLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UInputUtilitiesFunctionLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_InputUtilities,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UInputUtilitiesFunctionLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UInputUtilitiesFunctionLibrary_GetTextureForMappedAction, "GetTextureForMappedAction" }, // 1083309395
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInputUtilitiesFunctionLibrary_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "FunctionLibrary/InputUtilitiesFunctionLibrary.h" },
		{ "ModuleRelativePath", "FunctionLibrary/InputUtilitiesFunctionLibrary.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UInputUtilitiesFunctionLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UInputUtilitiesFunctionLibrary>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UInputUtilitiesFunctionLibrary_Statics::ClassParams = {
		&UInputUtilitiesFunctionLibrary::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UInputUtilitiesFunctionLibrary_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UInputUtilitiesFunctionLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UInputUtilitiesFunctionLibrary()
	{
		if (!Z_Registration_Info_UClass_UInputUtilitiesFunctionLibrary.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UInputUtilitiesFunctionLibrary.OuterSingleton, Z_Construct_UClass_UInputUtilitiesFunctionLibrary_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UInputUtilitiesFunctionLibrary.OuterSingleton;
	}
	template<> INPUTUTILITIES_API UClass* StaticClass<UInputUtilitiesFunctionLibrary>()
	{
		return UInputUtilitiesFunctionLibrary::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UInputUtilitiesFunctionLibrary);
	UInputUtilitiesFunctionLibrary::~UInputUtilitiesFunctionLibrary() {}
	struct Z_CompiledInDeferFile_FID_Users_oleor_Documents_GitHub_HobbyProject_InputUtilitiesPlugin_UE_InputUtilities_Plugins_InputUtilities_Source_InputUtilities_FunctionLibrary_InputUtilitiesFunctionLibrary_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_oleor_Documents_GitHub_HobbyProject_InputUtilitiesPlugin_UE_InputUtilities_Plugins_InputUtilities_Source_InputUtilities_FunctionLibrary_InputUtilitiesFunctionLibrary_h_Statics::ScriptStructInfo[] = {
		{ FKeyTextures::StaticStruct, Z_Construct_UScriptStruct_FKeyTextures_Statics::NewStructOps, TEXT("KeyTextures"), &Z_Registration_Info_UScriptStruct_KeyTextures, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FKeyTextures), 2181175075U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_oleor_Documents_GitHub_HobbyProject_InputUtilitiesPlugin_UE_InputUtilities_Plugins_InputUtilities_Source_InputUtilities_FunctionLibrary_InputUtilitiesFunctionLibrary_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UInputUtilitiesFunctionLibrary, UInputUtilitiesFunctionLibrary::StaticClass, TEXT("UInputUtilitiesFunctionLibrary"), &Z_Registration_Info_UClass_UInputUtilitiesFunctionLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UInputUtilitiesFunctionLibrary), 683380053U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_oleor_Documents_GitHub_HobbyProject_InputUtilitiesPlugin_UE_InputUtilities_Plugins_InputUtilities_Source_InputUtilities_FunctionLibrary_InputUtilitiesFunctionLibrary_h_4116685650(TEXT("/Script/InputUtilities"),
		Z_CompiledInDeferFile_FID_Users_oleor_Documents_GitHub_HobbyProject_InputUtilitiesPlugin_UE_InputUtilities_Plugins_InputUtilities_Source_InputUtilities_FunctionLibrary_InputUtilitiesFunctionLibrary_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_oleor_Documents_GitHub_HobbyProject_InputUtilitiesPlugin_UE_InputUtilities_Plugins_InputUtilities_Source_InputUtilities_FunctionLibrary_InputUtilitiesFunctionLibrary_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_Users_oleor_Documents_GitHub_HobbyProject_InputUtilitiesPlugin_UE_InputUtilities_Plugins_InputUtilities_Source_InputUtilities_FunctionLibrary_InputUtilitiesFunctionLibrary_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_oleor_Documents_GitHub_HobbyProject_InputUtilitiesPlugin_UE_InputUtilities_Plugins_InputUtilities_Source_InputUtilities_FunctionLibrary_InputUtilitiesFunctionLibrary_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
