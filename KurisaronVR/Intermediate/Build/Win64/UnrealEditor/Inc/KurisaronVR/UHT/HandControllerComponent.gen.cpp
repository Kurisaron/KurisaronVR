// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "KurisaronVR/Public/HandControllerComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHandControllerComponent() {}

// Begin Cross Module References
ENGINE_API UEnum* Z_Construct_UEnum_Engine_EObjectTypeQuery();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
HEADMOUNTEDDISPLAY_API UClass* Z_Construct_UClass_UMotionControllerComponent();
KURISARONVR_API UClass* Z_Construct_UClass_UGripComponent_NoRegister();
KURISARONVR_API UClass* Z_Construct_UClass_UHandControllerComponent();
KURISARONVR_API UClass* Z_Construct_UClass_UHandControllerComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_KurisaronVR();
// End Cross Module References

// Begin Class UHandControllerComponent
void UHandControllerComponent::StaticRegisterNativesUHandControllerComponent()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UHandControllerComponent);
UClass* Z_Construct_UClass_UHandControllerComponent_NoRegister()
{
	return UHandControllerComponent::StaticClass();
}
struct Z_Construct_UClass_UHandControllerComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "Category", "VR" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Mobility VirtualTexture Trigger" },
		{ "IncludePath", "HandControllerComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/HandControllerComponent.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractionInputMap_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Hand|Input|Interaction" },
		{ "ModuleRelativePath", "Public/HandControllerComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PoseInputMap_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Hand|Input|Pose" },
		{ "ModuleRelativePath", "Public/HandControllerComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GrabAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Hand|Input|Interaction" },
		{ "ModuleRelativePath", "Public/HandControllerComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FireAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Hand|Input|Interaction" },
		{ "ModuleRelativePath", "Public/HandControllerComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UseAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Hand|Input|Interaction" },
		{ "ModuleRelativePath", "Public/HandControllerComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AltUseAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Hand|Input|Interaction" },
		{ "ModuleRelativePath", "Public/HandControllerComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GraspAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Hand|Input|Pose" },
		{ "ModuleRelativePath", "Public/HandControllerComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IndexCurlAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Hand|Input|Pose" },
		{ "ModuleRelativePath", "Public/HandControllerComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PointAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Hand|Input|Pose" },
		{ "ModuleRelativePath", "Public/HandControllerComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ThumbUpAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Hand|Input|Pose" },
		{ "ModuleRelativePath", "Public/HandControllerComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GrabRadius_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Hand|Grabbing" },
		{ "ModuleRelativePath", "Public/HandControllerComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GrabObjectTypes_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Hand|Grabbing" },
		{ "ModuleRelativePath", "Public/HandControllerComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GrabbedGrip_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Hand|Grabbing" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/HandControllerComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowDebug_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Hand|Debug" },
		{ "ModuleRelativePath", "Public/HandControllerComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowTransform_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Hand|Debug" },
		{ "EditCondition", "bShowDebug" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/HandControllerComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InteractionInputMap;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PoseInputMap;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_GrabAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FireAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_UseAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AltUseAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_GraspAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_IndexCurlAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PointAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ThumbUpAction;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_GrabRadius;
	static const UECodeGen_Private::FBytePropertyParams NewProp_GrabObjectTypes_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_GrabObjectTypes;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_GrabbedGrip;
	static void NewProp_bShowDebug_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowDebug;
	static void NewProp_bShowTransform_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowTransform;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UHandControllerComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_InteractionInputMap = { "InteractionInputMap", nullptr, (EPropertyFlags)0x0144000000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHandControllerComponent, InteractionInputMap), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractionInputMap_MetaData), NewProp_InteractionInputMap_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_PoseInputMap = { "PoseInputMap", nullptr, (EPropertyFlags)0x0144000000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHandControllerComponent, PoseInputMap), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PoseInputMap_MetaData), NewProp_PoseInputMap_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_GrabAction = { "GrabAction", nullptr, (EPropertyFlags)0x0144000000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHandControllerComponent, GrabAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GrabAction_MetaData), NewProp_GrabAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_FireAction = { "FireAction", nullptr, (EPropertyFlags)0x0144000000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHandControllerComponent, FireAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FireAction_MetaData), NewProp_FireAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_UseAction = { "UseAction", nullptr, (EPropertyFlags)0x0144000000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHandControllerComponent, UseAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UseAction_MetaData), NewProp_UseAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_AltUseAction = { "AltUseAction", nullptr, (EPropertyFlags)0x0144000000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHandControllerComponent, AltUseAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AltUseAction_MetaData), NewProp_AltUseAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_GraspAction = { "GraspAction", nullptr, (EPropertyFlags)0x0144000000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHandControllerComponent, GraspAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GraspAction_MetaData), NewProp_GraspAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_IndexCurlAction = { "IndexCurlAction", nullptr, (EPropertyFlags)0x0144000000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHandControllerComponent, IndexCurlAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IndexCurlAction_MetaData), NewProp_IndexCurlAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_PointAction = { "PointAction", nullptr, (EPropertyFlags)0x0144000000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHandControllerComponent, PointAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PointAction_MetaData), NewProp_PointAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_ThumbUpAction = { "ThumbUpAction", nullptr, (EPropertyFlags)0x0144000000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHandControllerComponent, ThumbUpAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ThumbUpAction_MetaData), NewProp_ThumbUpAction_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_GrabRadius = { "GrabRadius", nullptr, (EPropertyFlags)0x0040000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHandControllerComponent, GrabRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GrabRadius_MetaData), NewProp_GrabRadius_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_GrabObjectTypes_Inner = { "GrabObjectTypes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UEnum_Engine_EObjectTypeQuery, METADATA_PARAMS(0, nullptr) }; // 1798967895
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_GrabObjectTypes = { "GrabObjectTypes", nullptr, (EPropertyFlags)0x0040000000010015, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHandControllerComponent, GrabObjectTypes), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GrabObjectTypes_MetaData), NewProp_GrabObjectTypes_MetaData) }; // 1798967895
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_GrabbedGrip = { "GrabbedGrip", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHandControllerComponent, GrabbedGrip), Z_Construct_UClass_UGripComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GrabbedGrip_MetaData), NewProp_GrabbedGrip_MetaData) };
void Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_bShowDebug_SetBit(void* Obj)
{
	((UHandControllerComponent*)Obj)->bShowDebug = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_bShowDebug = { "bShowDebug", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UHandControllerComponent), &Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_bShowDebug_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowDebug_MetaData), NewProp_bShowDebug_MetaData) };
void Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_bShowTransform_SetBit(void* Obj)
{
	((UHandControllerComponent*)Obj)->bShowTransform = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_bShowTransform = { "bShowTransform", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UHandControllerComponent), &Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_bShowTransform_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowTransform_MetaData), NewProp_bShowTransform_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UHandControllerComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_InteractionInputMap,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_PoseInputMap,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_GrabAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_FireAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_UseAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_AltUseAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_GraspAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_IndexCurlAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_PointAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_ThumbUpAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_GrabRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_GrabObjectTypes_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_GrabObjectTypes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_GrabbedGrip,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_bShowDebug,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_bShowTransform,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHandControllerComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UHandControllerComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UMotionControllerComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_KurisaronVR,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHandControllerComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UHandControllerComponent_Statics::ClassParams = {
	&UHandControllerComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UHandControllerComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UHandControllerComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHandControllerComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UHandControllerComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UHandControllerComponent()
{
	if (!Z_Registration_Info_UClass_UHandControllerComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UHandControllerComponent.OuterSingleton, Z_Construct_UClass_UHandControllerComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UHandControllerComponent.OuterSingleton;
}
template<> KURISARONVR_API UClass* StaticClass<UHandControllerComponent>()
{
	return UHandControllerComponent::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UHandControllerComponent);
UHandControllerComponent::~UHandControllerComponent() {}
// End Class UHandControllerComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_Github_KurisaronVR_KurisaronVR_Source_KurisaronVR_Public_HandControllerComponent_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UHandControllerComponent, UHandControllerComponent::StaticClass, TEXT("UHandControllerComponent"), &Z_Registration_Info_UClass_UHandControllerComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UHandControllerComponent), 2149794396U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_KurisaronVR_KurisaronVR_Source_KurisaronVR_Public_HandControllerComponent_h_875810793(TEXT("/Script/KurisaronVR"),
	Z_CompiledInDeferFile_FID_Github_KurisaronVR_KurisaronVR_Source_KurisaronVR_Public_HandControllerComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_KurisaronVR_KurisaronVR_Source_KurisaronVR_Public_HandControllerComponent_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
