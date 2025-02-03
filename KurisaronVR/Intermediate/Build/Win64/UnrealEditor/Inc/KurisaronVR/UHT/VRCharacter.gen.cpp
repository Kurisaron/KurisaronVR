// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "KurisaronVR/Public/VRCharacter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVRCharacter() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
ENGINE_API UClass* Z_Construct_UClass_UBoxComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UPhysicsConstraintComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USphereComponent_NoRegister();
KURISARONVR_API UClass* Z_Construct_UClass_AVRCharacter();
KURISARONVR_API UClass* Z_Construct_UClass_AVRCharacter_NoRegister();
KURISARONVR_API UClass* Z_Construct_UClass_UHandControllerComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_KurisaronVR();
// End Cross Module References

// Begin Class AVRCharacter
void AVRCharacter::StaticRegisterNativesAVRCharacter()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AVRCharacter);
UClass* Z_Construct_UClass_AVRCharacter_NoRegister()
{
	return AVRCharacter::StaticClass();
}
struct Z_Construct_UClass_AVRCharacter_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Category", "VR" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * A VR Character is the primary actor object that a VR player controls during gameplay\n */" },
#endif
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "VRCharacter.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/VRCharacter.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "A VR Character is the primary actor object that a VR player controls during gameplay" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VR_Origin_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "VR" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Scene component used as the parent origin for VR tracking\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/VRCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Scene component used as the parent origin for VR tracking" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HMD_Camera_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "VR" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Camera tracked to the VR head-mounted display\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/VRCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Camera tracked to the VR head-mounted display" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LeftHandController_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "VR|Hands" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Motion controller used to track the player's left hand\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/VRCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Motion controller used to track the player's left hand" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RightHandController_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "VR|Hands" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Motion controller used to track the player's right hand\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/VRCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Motion controller used to track the player's right hand" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LeftHandHapticTarget_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "VR|Hands|Haptic Collision" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Component used as target by the left hand's physics constraint that drives haptic collision\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/VRCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Component used as target by the left hand's physics constraint that drives haptic collision" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RightHandHapticTarget_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "VR|Hands|Haptic Collision" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Component used as target by the right hand's physics constraint that drives haptic collision\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/VRCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Component used as target by the right hand's physics constraint that drives haptic collision" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LeftHandHapticCollider_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "VR|Hands|Haptic Collision" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Collider used by the left hand to ensure haptic collision\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/VRCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Collider used by the left hand to ensure haptic collision" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RightHandHapticCollider_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "VR|Hands|Haptic Collision" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Collider used by the right hand to ensure haptic collision\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/VRCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Collider used by the right hand to ensure haptic collision" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LeftHandHapticConstraint_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "VR|Hands|Haptic Collision" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Physics constraint used to pull the left hand's haptic collider toward its target\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/VRCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Physics constraint used to pull the left hand's haptic collider toward its target" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RightHandHapticConstraint_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "VR|Hands|Haptic Collision" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Physics constraint used to pull the right hand's haptic collider toward its target\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/VRCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Physics constraint used to pull the right hand's haptic collider toward its target" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LeftHandGrabConstraint_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "VR|Hands|Grabbing" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Physics constraint used by the left hand to grab\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/VRCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Physics constraint used by the left hand to grab" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RightHandGrabConstraint_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "VR|Hands|Grabbing" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Physics constraint used by the right hand to grab\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/VRCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Physics constraint used by the right hand to grab" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_VR_Origin;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HMD_Camera;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LeftHandController;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RightHandController;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LeftHandHapticTarget;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RightHandHapticTarget;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LeftHandHapticCollider;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RightHandHapticCollider;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LeftHandHapticConstraint;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RightHandHapticConstraint;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LeftHandGrabConstraint;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RightHandGrabConstraint;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AVRCharacter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVRCharacter_Statics::NewProp_VR_Origin = { "VR_Origin", nullptr, (EPropertyFlags)0x014400000008001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVRCharacter, VR_Origin), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VR_Origin_MetaData), NewProp_VR_Origin_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVRCharacter_Statics::NewProp_HMD_Camera = { "HMD_Camera", nullptr, (EPropertyFlags)0x014400000008001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVRCharacter, HMD_Camera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HMD_Camera_MetaData), NewProp_HMD_Camera_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVRCharacter_Statics::NewProp_LeftHandController = { "LeftHandController", nullptr, (EPropertyFlags)0x014400000008001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVRCharacter, LeftHandController), Z_Construct_UClass_UHandControllerComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LeftHandController_MetaData), NewProp_LeftHandController_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVRCharacter_Statics::NewProp_RightHandController = { "RightHandController", nullptr, (EPropertyFlags)0x014400000008001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVRCharacter, RightHandController), Z_Construct_UClass_UHandControllerComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RightHandController_MetaData), NewProp_RightHandController_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVRCharacter_Statics::NewProp_LeftHandHapticTarget = { "LeftHandHapticTarget", nullptr, (EPropertyFlags)0x014400000008001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVRCharacter, LeftHandHapticTarget), Z_Construct_UClass_USphereComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LeftHandHapticTarget_MetaData), NewProp_LeftHandHapticTarget_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVRCharacter_Statics::NewProp_RightHandHapticTarget = { "RightHandHapticTarget", nullptr, (EPropertyFlags)0x014400000008001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVRCharacter, RightHandHapticTarget), Z_Construct_UClass_USphereComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RightHandHapticTarget_MetaData), NewProp_RightHandHapticTarget_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVRCharacter_Statics::NewProp_LeftHandHapticCollider = { "LeftHandHapticCollider", nullptr, (EPropertyFlags)0x014400000008001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVRCharacter, LeftHandHapticCollider), Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LeftHandHapticCollider_MetaData), NewProp_LeftHandHapticCollider_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVRCharacter_Statics::NewProp_RightHandHapticCollider = { "RightHandHapticCollider", nullptr, (EPropertyFlags)0x014400000008001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVRCharacter, RightHandHapticCollider), Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RightHandHapticCollider_MetaData), NewProp_RightHandHapticCollider_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVRCharacter_Statics::NewProp_LeftHandHapticConstraint = { "LeftHandHapticConstraint", nullptr, (EPropertyFlags)0x014400000008001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVRCharacter, LeftHandHapticConstraint), Z_Construct_UClass_UPhysicsConstraintComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LeftHandHapticConstraint_MetaData), NewProp_LeftHandHapticConstraint_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVRCharacter_Statics::NewProp_RightHandHapticConstraint = { "RightHandHapticConstraint", nullptr, (EPropertyFlags)0x014400000008001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVRCharacter, RightHandHapticConstraint), Z_Construct_UClass_UPhysicsConstraintComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RightHandHapticConstraint_MetaData), NewProp_RightHandHapticConstraint_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVRCharacter_Statics::NewProp_LeftHandGrabConstraint = { "LeftHandGrabConstraint", nullptr, (EPropertyFlags)0x014400000008001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVRCharacter, LeftHandGrabConstraint), Z_Construct_UClass_UPhysicsConstraintComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LeftHandGrabConstraint_MetaData), NewProp_LeftHandGrabConstraint_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVRCharacter_Statics::NewProp_RightHandGrabConstraint = { "RightHandGrabConstraint", nullptr, (EPropertyFlags)0x014400000008001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVRCharacter, RightHandGrabConstraint), Z_Construct_UClass_UPhysicsConstraintComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RightHandGrabConstraint_MetaData), NewProp_RightHandGrabConstraint_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AVRCharacter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVRCharacter_Statics::NewProp_VR_Origin,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVRCharacter_Statics::NewProp_HMD_Camera,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVRCharacter_Statics::NewProp_LeftHandController,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVRCharacter_Statics::NewProp_RightHandController,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVRCharacter_Statics::NewProp_LeftHandHapticTarget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVRCharacter_Statics::NewProp_RightHandHapticTarget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVRCharacter_Statics::NewProp_LeftHandHapticCollider,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVRCharacter_Statics::NewProp_RightHandHapticCollider,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVRCharacter_Statics::NewProp_LeftHandHapticConstraint,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVRCharacter_Statics::NewProp_RightHandHapticConstraint,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVRCharacter_Statics::NewProp_LeftHandGrabConstraint,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVRCharacter_Statics::NewProp_RightHandGrabConstraint,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AVRCharacter_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AVRCharacter_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_KurisaronVR,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AVRCharacter_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AVRCharacter_Statics::ClassParams = {
	&AVRCharacter::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AVRCharacter_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AVRCharacter_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVRCharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_AVRCharacter_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AVRCharacter()
{
	if (!Z_Registration_Info_UClass_AVRCharacter.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AVRCharacter.OuterSingleton, Z_Construct_UClass_AVRCharacter_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AVRCharacter.OuterSingleton;
}
template<> KURISARONVR_API UClass* StaticClass<AVRCharacter>()
{
	return AVRCharacter::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AVRCharacter);
AVRCharacter::~AVRCharacter() {}
// End Class AVRCharacter

// Begin Registration
struct Z_CompiledInDeferFile_FID_Github_KurisaronVR_KurisaronVR_Source_KurisaronVR_Public_VRCharacter_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AVRCharacter, AVRCharacter::StaticClass, TEXT("AVRCharacter"), &Z_Registration_Info_UClass_AVRCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AVRCharacter), 2605077214U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_KurisaronVR_KurisaronVR_Source_KurisaronVR_Public_VRCharacter_h_3910246535(TEXT("/Script/KurisaronVR"),
	Z_CompiledInDeferFile_FID_Github_KurisaronVR_KurisaronVR_Source_KurisaronVR_Public_VRCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_KurisaronVR_KurisaronVR_Source_KurisaronVR_Public_VRCharacter_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
