// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "VRCharacter.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef KURISARONVR_VRCharacter_generated_h
#error "VRCharacter.generated.h already included, missing '#pragma once' in VRCharacter.h"
#endif
#define KURISARONVR_VRCharacter_generated_h

#define FID_Github_KurisaronVR_KurisaronVR_Source_KurisaronVR_Public_VRCharacter_h_26_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAVRCharacter(); \
	friend struct Z_Construct_UClass_AVRCharacter_Statics; \
public: \
	DECLARE_CLASS(AVRCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/KurisaronVR"), NO_API) \
	DECLARE_SERIALIZER(AVRCharacter)


#define FID_Github_KurisaronVR_KurisaronVR_Source_KurisaronVR_Public_VRCharacter_h_26_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AVRCharacter(AVRCharacter&&); \
	AVRCharacter(const AVRCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVRCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVRCharacter); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AVRCharacter) \
	NO_API virtual ~AVRCharacter();


#define FID_Github_KurisaronVR_KurisaronVR_Source_KurisaronVR_Public_VRCharacter_h_23_PROLOG
#define FID_Github_KurisaronVR_KurisaronVR_Source_KurisaronVR_Public_VRCharacter_h_26_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Github_KurisaronVR_KurisaronVR_Source_KurisaronVR_Public_VRCharacter_h_26_INCLASS_NO_PURE_DECLS \
	FID_Github_KurisaronVR_KurisaronVR_Source_KurisaronVR_Public_VRCharacter_h_26_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> KURISARONVR_API UClass* StaticClass<class AVRCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Github_KurisaronVR_KurisaronVR_Source_KurisaronVR_Public_VRCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
