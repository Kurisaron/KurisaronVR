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
ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
HEADMOUNTEDDISPLAY_API UClass* Z_Construct_UClass_UMotionControllerComponent();
KURISARONVR_API UClass* Z_Construct_UClass_UHandControllerComponent();
KURISARONVR_API UClass* Z_Construct_UClass_UHandControllerComponent_NoRegister();
KURISARONVR_API UScriptStruct* Z_Construct_UScriptStruct_FHandPose();
UPackage* Z_Construct_UPackage__Script_KurisaronVR();
// End Cross Module References

// Begin ScriptStruct FHandPose
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_HandPose;
class UScriptStruct* FHandPose::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_HandPose.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_HandPose.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FHandPose, (UObject*)Z_Construct_UPackage__Script_KurisaronVR(), TEXT("HandPose"));
	}
	return Z_Registration_Info_UScriptStruct_HandPose.OuterSingleton;
}
template<> KURISARONVR_API UScriptStruct* StaticStruct<FHandPose>()
{
	return FHandPose::StaticStruct();
}
struct Z_Construct_UScriptStruct_FHandPose_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/HandControllerComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Grasp_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "HandPose" },
		{ "ModuleRelativePath", "Public/HandControllerComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IndexCurl_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "HandPose" },
		{ "ModuleRelativePath", "Public/HandControllerComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Point_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "HandPose" },
		{ "ModuleRelativePath", "Public/HandControllerComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ThumbUp_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "HandPose" },
		{ "ModuleRelativePath", "Public/HandControllerComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Grasp;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_IndexCurl;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Point;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ThumbUp;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FHandPose>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FHandPose_Statics::NewProp_Grasp = { "Grasp", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHandPose, Grasp), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Grasp_MetaData), NewProp_Grasp_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FHandPose_Statics::NewProp_IndexCurl = { "IndexCurl", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHandPose, IndexCurl), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IndexCurl_MetaData), NewProp_IndexCurl_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FHandPose_Statics::NewProp_Point = { "Point", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHandPose, Point), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Point_MetaData), NewProp_Point_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FHandPose_Statics::NewProp_ThumbUp = { "ThumbUp", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHandPose, ThumbUp), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ThumbUp_MetaData), NewProp_ThumbUp_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FHandPose_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHandPose_Statics::NewProp_Grasp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHandPose_Statics::NewProp_IndexCurl,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHandPose_Statics::NewProp_Point,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHandPose_Statics::NewProp_ThumbUp,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHandPose_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FHandPose_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_KurisaronVR,
	nullptr,
	&NewStructOps,
	"HandPose",
	Z_Construct_UScriptStruct_FHandPose_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHandPose_Statics::PropPointers),
	sizeof(FHandPose),
	alignof(FHandPose),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHandPose_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FHandPose_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FHandPose()
{
	if (!Z_Registration_Info_UScriptStruct_HandPose.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_HandPose.InnerSingleton, Z_Construct_UScriptStruct_FHandPose_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_HandPose.InnerSingleton;
}
// End ScriptStruct FHandPose

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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GrabInput_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Hand|Input|Interaction" },
		{ "ModuleRelativePath", "Public/HandControllerComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FireInput_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Hand|Input|Interaction" },
		{ "ModuleRelativePath", "Public/HandControllerComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UseInput_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Hand|Input|Interaction" },
		{ "ModuleRelativePath", "Public/HandControllerComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AltUseInput_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Hand|Input|Interaction" },
		{ "ModuleRelativePath", "Public/HandControllerComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HandPose_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Hand|Input|Pose" },
		{ "ModuleRelativePath", "Public/HandControllerComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HapticBone_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Hand|Haptic Collision" },
		{ "ModuleRelativePath", "Public/HandControllerComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GrabRadius_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Hand|Grab" },
		{ "ModuleRelativePath", "Public/HandControllerComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GrabbedPrimitive_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Hand|Grab" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/HandControllerComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowDebug_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Hand|Debug" },
		{ "ModuleRelativePath", "Public/HandControllerComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDebugTransform_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Hand|Debug" },
		{ "EditCondition", "bShowDebug" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/HandControllerComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDebugGrabbing_MetaData[] = {
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
	static const UECodeGen_Private::FFloatPropertyParams NewProp_GrabInput;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FireInput;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_UseInput;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AltUseInput;
	static const UECodeGen_Private::FStructPropertyParams NewProp_HandPose;
	static const UECodeGen_Private::FNamePropertyParams NewProp_HapticBone;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_GrabRadius;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_GrabbedPrimitive;
	static void NewProp_bShowDebug_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowDebug;
	static void NewProp_bDebugTransform_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDebugTransform;
	static void NewProp_bDebugGrabbing_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDebugGrabbing;
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
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_GrabInput = { "GrabInput", nullptr, (EPropertyFlags)0x0040000000020015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHandControllerComponent, GrabInput), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GrabInput_MetaData), NewProp_GrabInput_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_FireInput = { "FireInput", nullptr, (EPropertyFlags)0x0040000000020015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHandControllerComponent, FireInput), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FireInput_MetaData), NewProp_FireInput_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_UseInput = { "UseInput", nullptr, (EPropertyFlags)0x0040000000020015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHandControllerComponent, UseInput), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UseInput_MetaData), NewProp_UseInput_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_AltUseInput = { "AltUseInput", nullptr, (EPropertyFlags)0x0040000000020015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHandControllerComponent, AltUseInput), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AltUseInput_MetaData), NewProp_AltUseInput_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_HandPose = { "HandPose", nullptr, (EPropertyFlags)0x0040000000020015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHandControllerComponent, HandPose), Z_Construct_UScriptStruct_FHandPose, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HandPose_MetaData), NewProp_HandPose_MetaData) }; // 2107881663
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_HapticBone = { "HapticBone", nullptr, (EPropertyFlags)0x0040000000000815, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHandControllerComponent, HapticBone), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HapticBone_MetaData), NewProp_HapticBone_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_GrabRadius = { "GrabRadius", nullptr, (EPropertyFlags)0x0040000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHandControllerComponent, GrabRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GrabRadius_MetaData), NewProp_GrabRadius_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_GrabbedPrimitive = { "GrabbedPrimitive", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHandControllerComponent, GrabbedPrimitive), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GrabbedPrimitive_MetaData), NewProp_GrabbedPrimitive_MetaData) };
void Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_bShowDebug_SetBit(void* Obj)
{
	((UHandControllerComponent*)Obj)->bShowDebug = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_bShowDebug = { "bShowDebug", nullptr, (EPropertyFlags)0x0040000000010015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UHandControllerComponent), &Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_bShowDebug_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowDebug_MetaData), NewProp_bShowDebug_MetaData) };
void Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_bDebugTransform_SetBit(void* Obj)
{
	((UHandControllerComponent*)Obj)->bDebugTransform = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_bDebugTransform = { "bDebugTransform", nullptr, (EPropertyFlags)0x0040000000010015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UHandControllerComponent), &Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_bDebugTransform_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDebugTransform_MetaData), NewProp_bDebugTransform_MetaData) };
void Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_bDebugGrabbing_SetBit(void* Obj)
{
	((UHandControllerComponent*)Obj)->bDebugGrabbing = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_bDebugGrabbing = { "bDebugGrabbing", nullptr, (EPropertyFlags)0x0040000000010015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UHandControllerComponent), &Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_bDebugGrabbing_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDebugGrabbing_MetaData), NewProp_bDebugGrabbing_MetaData) };
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
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_GrabInput,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_FireInput,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_UseInput,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_AltUseInput,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_HandPose,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_HapticBone,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_GrabRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_GrabbedPrimitive,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_bShowDebug,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_bDebugTransform,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHandControllerComponent_Statics::NewProp_bDebugGrabbing,
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
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FHandPose::StaticStruct, Z_Construct_UScriptStruct_FHandPose_Statics::NewStructOps, TEXT("HandPose"), &Z_Registration_Info_UScriptStruct_HandPose, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FHandPose), 2107881663U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UHandControllerComponent, UHandControllerComponent::StaticClass, TEXT("UHandControllerComponent"), &Z_Registration_Info_UClass_UHandControllerComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UHandControllerComponent), 1720006673U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_KurisaronVR_KurisaronVR_Source_KurisaronVR_Public_HandControllerComponent_h_1953638388(TEXT("/Script/KurisaronVR"),
	Z_CompiledInDeferFile_FID_Github_KurisaronVR_KurisaronVR_Source_KurisaronVR_Public_HandControllerComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_KurisaronVR_KurisaronVR_Source_KurisaronVR_Public_HandControllerComponent_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Github_KurisaronVR_KurisaronVR_Source_KurisaronVR_Public_HandControllerComponent_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_KurisaronVR_KurisaronVR_Source_KurisaronVR_Public_HandControllerComponent_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
