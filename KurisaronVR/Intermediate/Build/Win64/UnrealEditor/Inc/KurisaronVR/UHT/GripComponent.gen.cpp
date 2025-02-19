// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "KurisaronVR/Public/GripComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGripComponent() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UHapticFeedbackEffect_Base_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USceneComponent();
KURISARONVR_API UClass* Z_Construct_UClass_UGripComponent();
KURISARONVR_API UClass* Z_Construct_UClass_UGripComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_KurisaronVR();
// End Cross Module References

// Begin Class UGripComponent
void UGripComponent::StaticRegisterNativesUGripComponent()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UGripComponent);
UClass* Z_Construct_UClass_UGripComponent_NoRegister()
{
	return UGripComponent::StaticClass();
}
struct Z_Construct_UClass_UGripComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "Category", "VR" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Trigger PhysicsVolume" },
		{ "IncludePath", "GripComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/GripComponent.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCanGrab_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Grip" },
		{ "ModuleRelativePath", "Public/GripComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GrabHapticEffect_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Grip" },
		{ "EditCondition", "bCanGrab" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/GripComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCanTelegrab_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Grip" },
		{ "ModuleRelativePath", "Public/GripComponent.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bCanGrab_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCanGrab;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_GrabHapticEffect;
	static void NewProp_bCanTelegrab_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCanTelegrab;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGripComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
void Z_Construct_UClass_UGripComponent_Statics::NewProp_bCanGrab_SetBit(void* Obj)
{
	((UGripComponent*)Obj)->bCanGrab = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UGripComponent_Statics::NewProp_bCanGrab = { "bCanGrab", nullptr, (EPropertyFlags)0x0040000000010015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UGripComponent), &Z_Construct_UClass_UGripComponent_Statics::NewProp_bCanGrab_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCanGrab_MetaData), NewProp_bCanGrab_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGripComponent_Statics::NewProp_GrabHapticEffect = { "GrabHapticEffect", nullptr, (EPropertyFlags)0x0040000000010015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGripComponent, GrabHapticEffect), Z_Construct_UClass_UHapticFeedbackEffect_Base_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GrabHapticEffect_MetaData), NewProp_GrabHapticEffect_MetaData) };
void Z_Construct_UClass_UGripComponent_Statics::NewProp_bCanTelegrab_SetBit(void* Obj)
{
	((UGripComponent*)Obj)->bCanTelegrab = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UGripComponent_Statics::NewProp_bCanTelegrab = { "bCanTelegrab", nullptr, (EPropertyFlags)0x0040000000010015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UGripComponent), &Z_Construct_UClass_UGripComponent_Statics::NewProp_bCanTelegrab_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCanTelegrab_MetaData), NewProp_bCanTelegrab_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGripComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGripComponent_Statics::NewProp_bCanGrab,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGripComponent_Statics::NewProp_GrabHapticEffect,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGripComponent_Statics::NewProp_bCanTelegrab,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGripComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UGripComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_USceneComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_KurisaronVR,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGripComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UGripComponent_Statics::ClassParams = {
	&UGripComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UGripComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UGripComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGripComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UGripComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UGripComponent()
{
	if (!Z_Registration_Info_UClass_UGripComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGripComponent.OuterSingleton, Z_Construct_UClass_UGripComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UGripComponent.OuterSingleton;
}
template<> KURISARONVR_API UClass* StaticClass<UGripComponent>()
{
	return UGripComponent::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UGripComponent);
UGripComponent::~UGripComponent() {}
// End Class UGripComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_Github_KurisaronVR_KurisaronVR_Source_KurisaronVR_Public_GripComponent_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UGripComponent, UGripComponent::StaticClass, TEXT("UGripComponent"), &Z_Registration_Info_UClass_UGripComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGripComponent), 1350568998U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_KurisaronVR_KurisaronVR_Source_KurisaronVR_Public_GripComponent_h_3491218582(TEXT("/Script/KurisaronVR"),
	Z_CompiledInDeferFile_FID_Github_KurisaronVR_KurisaronVR_Source_KurisaronVR_Public_GripComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_KurisaronVR_KurisaronVR_Source_KurisaronVR_Public_GripComponent_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
