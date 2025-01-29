// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "KurisaronVR/Public/LocomotionComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLocomotionComponent() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
ENGINE_API UClass* Z_Construct_UClass_UCharacterMovementComponent();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
KURISARONVR_API UClass* Z_Construct_UClass_ULocomotionComponent();
KURISARONVR_API UClass* Z_Construct_UClass_ULocomotionComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_KurisaronVR();
// End Cross Module References

// Begin Class ULocomotionComponent
void ULocomotionComponent::StaticRegisterNativesULocomotionComponent()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ULocomotionComponent);
UClass* Z_Construct_UClass_ULocomotionComponent_NoRegister()
{
	return ULocomotionComponent::StaticClass();
}
struct Z_Construct_UClass_ULocomotionComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "LocomotionComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/LocomotionComponent.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LocomotionInputMap_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Locomotion|Input" },
		{ "ModuleRelativePath", "Public/LocomotionComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoveAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Locomotion|Input" },
		{ "ModuleRelativePath", "Public/LocomotionComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TurnAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Locomotion|Input" },
		{ "ModuleRelativePath", "Public/LocomotionComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JumpAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Locomotion|Input" },
		{ "ModuleRelativePath", "Public/LocomotionComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DodgeAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Locomotion|Input" },
		{ "ModuleRelativePath", "Public/LocomotionComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CalibrateAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Locomotion|Input" },
		{ "ModuleRelativePath", "Public/LocomotionComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoveInput_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Locomotion|Input" },
		{ "ModuleRelativePath", "Public/LocomotionComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxHeight_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Locomotion|Roomscale|Height" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Current value for the player's max height. Used to evaluate standing/crouching/prone state based on head's current distance above the tracking origin\n" },
#endif
		{ "ModuleRelativePath", "Public/LocomotionComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current value for the player's max height. Used to evaluate standing/crouching/prone state based on head's current distance above the tracking origin" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HMD_HeightOffset_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Locomotion|Roomscale|Height" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Height offset added so capsule accurately matches player's height (above the HMD) during roomscale tracking\n" },
#endif
		{ "ModuleRelativePath", "Public/LocomotionComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Height offset added so capsule accurately matches player's height (above the HMD) during roomscale tracking" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDebugRoomscale_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Locomotion|Roomscale" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// True = Display in-game debugging elements to more easily understand roomscale operations\n" },
#endif
		{ "ModuleRelativePath", "Public/LocomotionComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "True = Display in-game debugging elements to more easily understand roomscale operations" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LocomotionInputMap;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MoveAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TurnAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_JumpAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DodgeAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CalibrateAction;
	static const UECodeGen_Private::FStructPropertyParams NewProp_MoveInput;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxHeight;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_HMD_HeightOffset;
	static void NewProp_bDebugRoomscale_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDebugRoomscale;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULocomotionComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULocomotionComponent_Statics::NewProp_LocomotionInputMap = { "LocomotionInputMap", nullptr, (EPropertyFlags)0x0144000000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULocomotionComponent, LocomotionInputMap), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LocomotionInputMap_MetaData), NewProp_LocomotionInputMap_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULocomotionComponent_Statics::NewProp_MoveAction = { "MoveAction", nullptr, (EPropertyFlags)0x0144000000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULocomotionComponent, MoveAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoveAction_MetaData), NewProp_MoveAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULocomotionComponent_Statics::NewProp_TurnAction = { "TurnAction", nullptr, (EPropertyFlags)0x0144000000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULocomotionComponent, TurnAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TurnAction_MetaData), NewProp_TurnAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULocomotionComponent_Statics::NewProp_JumpAction = { "JumpAction", nullptr, (EPropertyFlags)0x0144000000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULocomotionComponent, JumpAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JumpAction_MetaData), NewProp_JumpAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULocomotionComponent_Statics::NewProp_DodgeAction = { "DodgeAction", nullptr, (EPropertyFlags)0x0144000000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULocomotionComponent, DodgeAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DodgeAction_MetaData), NewProp_DodgeAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULocomotionComponent_Statics::NewProp_CalibrateAction = { "CalibrateAction", nullptr, (EPropertyFlags)0x0144000000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULocomotionComponent, CalibrateAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CalibrateAction_MetaData), NewProp_CalibrateAction_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ULocomotionComponent_Statics::NewProp_MoveInput = { "MoveInput", nullptr, (EPropertyFlags)0x0040000000020015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULocomotionComponent, MoveInput), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoveInput_MetaData), NewProp_MoveInput_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ULocomotionComponent_Statics::NewProp_MaxHeight = { "MaxHeight", nullptr, (EPropertyFlags)0x0040000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULocomotionComponent, MaxHeight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxHeight_MetaData), NewProp_MaxHeight_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ULocomotionComponent_Statics::NewProp_HMD_HeightOffset = { "HMD_HeightOffset", nullptr, (EPropertyFlags)0x0040000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULocomotionComponent, HMD_HeightOffset), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HMD_HeightOffset_MetaData), NewProp_HMD_HeightOffset_MetaData) };
void Z_Construct_UClass_ULocomotionComponent_Statics::NewProp_bDebugRoomscale_SetBit(void* Obj)
{
	((ULocomotionComponent*)Obj)->bDebugRoomscale = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ULocomotionComponent_Statics::NewProp_bDebugRoomscale = { "bDebugRoomscale", nullptr, (EPropertyFlags)0x0040040000010015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ULocomotionComponent), &Z_Construct_UClass_ULocomotionComponent_Statics::NewProp_bDebugRoomscale_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDebugRoomscale_MetaData), NewProp_bDebugRoomscale_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ULocomotionComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULocomotionComponent_Statics::NewProp_LocomotionInputMap,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULocomotionComponent_Statics::NewProp_MoveAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULocomotionComponent_Statics::NewProp_TurnAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULocomotionComponent_Statics::NewProp_JumpAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULocomotionComponent_Statics::NewProp_DodgeAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULocomotionComponent_Statics::NewProp_CalibrateAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULocomotionComponent_Statics::NewProp_MoveInput,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULocomotionComponent_Statics::NewProp_MaxHeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULocomotionComponent_Statics::NewProp_HMD_HeightOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULocomotionComponent_Statics::NewProp_bDebugRoomscale,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULocomotionComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ULocomotionComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UCharacterMovementComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_KurisaronVR,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULocomotionComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ULocomotionComponent_Statics::ClassParams = {
	&ULocomotionComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ULocomotionComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ULocomotionComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ULocomotionComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_ULocomotionComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ULocomotionComponent()
{
	if (!Z_Registration_Info_UClass_ULocomotionComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ULocomotionComponent.OuterSingleton, Z_Construct_UClass_ULocomotionComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ULocomotionComponent.OuterSingleton;
}
template<> KURISARONVR_API UClass* StaticClass<ULocomotionComponent>()
{
	return ULocomotionComponent::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ULocomotionComponent);
ULocomotionComponent::~ULocomotionComponent() {}
// End Class ULocomotionComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_Github_KurisaronVR_KurisaronVR_Source_KurisaronVR_Public_LocomotionComponent_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ULocomotionComponent, ULocomotionComponent::StaticClass, TEXT("ULocomotionComponent"), &Z_Registration_Info_UClass_ULocomotionComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ULocomotionComponent), 2061897168U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_KurisaronVR_KurisaronVR_Source_KurisaronVR_Public_LocomotionComponent_h_126221946(TEXT("/Script/KurisaronVR"),
	Z_CompiledInDeferFile_FID_Github_KurisaronVR_KurisaronVR_Source_KurisaronVR_Public_LocomotionComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_KurisaronVR_KurisaronVR_Source_KurisaronVR_Public_LocomotionComponent_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
