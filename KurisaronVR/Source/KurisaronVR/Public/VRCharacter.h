// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/KismetSystemLibrary.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SphereComponent.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"
#include "HeadMountedDisplayTypes.h"
#include "IXRTrackingSystem.h"
#include "VRCharacter.generated.h"

class UHandControllerComponent;
class ULocomotionComponent;

/**
 * A VR Character is the primary actor object that a VR player controls during gameplay
 */
UCLASS(Blueprintable, BlueprintType, Category = "VR")
class KURISARONVR_API AVRCharacter : public ACharacter
{
	GENERATED_BODY()

	// Scene component used as the parent origin for VR tracking
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "VR", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USceneComponent> VR_Origin;
	// Camera tracked to the VR head-mounted display
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "VR", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> HMD_Camera;

	// Motion controller used to track the player's left hand
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "VR|Hands", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UHandControllerComponent> LeftHandController;
	// Motion controller used to track the player's right hand
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "VR|Hands", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UHandControllerComponent> RightHandController;

	// Component used as target by the left hand's physics constraint that drives haptic collision
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "VR|Hands|Haptic Collision", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USphereComponent> LeftHandHapticTarget;
	// Component used as target by the right hand's physics constraint that drives haptic collision
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "VR|Hands|Haptic Collision", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USphereComponent> RightHandHapticTarget;

	// Collider used by the left hand to ensure haptic collision
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "VR|Hands|Haptic Collision", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UBoxComponent> LeftHandHapticCollider;
	// Collider used by the right hand to ensure haptic collision
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "VR|Hands|Haptic Collision", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UBoxComponent> RightHandHapticCollider;

	// Physics constraint used to pull the left hand's haptic collider toward its target
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "VR|Hands|Haptic Collision", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UPhysicsConstraintComponent> LeftHandHapticConstraint;
	// Physics constraint used to pull the right hand's haptic collider toward its target
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "VR|Hands|Haptic Collision", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UPhysicsConstraintComponent> RightHandHapticConstraint;

	// Physics constraint used by the left hand to grab
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "VR|Hands|Grabbing", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UPhysicsConstraintComponent> LeftHandGrabConstraint;
	// Physics constraint used by the right hand to grab
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "VR|Hands|Grabbing", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UPhysicsConstraintComponent> RightHandGrabConstraint;

protected:

	const FName VR_OriginComponentName = TEXT("VROrigin");
	const FName HMD_CameraComponentName = TEXT("Camera");
	const FName HandControllerComponentNames[2] = { TEXT("LeftHand"), TEXT("RightHand")};
	const FName HandHapticTargetComponentNames[2] = { TEXT("LH_HapticTarget"), TEXT("RH_HapticTarget") };
	const FName HandHapticColliderComponentNames[2] = { TEXT("LH_HapticCollider"), TEXT("RH_HapticCollider") };
	const FName HandHapticConstraintComponentNames[2] = { TEXT("LH_HapticConstraint"), TEXT("RH_HapticConstraint") };
	const FName HandGrabConstraintComponentNames[2] = { TEXT("LH_GrabConstraint"), TEXT("RH_GrabConstraint") };

public:
	
	// Sets default values for this character's properties
	AVRCharacter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void BeginVR();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void Crouch(bool bClientSimulation = false) override { /* Overriden to prevent ACharacter::Crouch from breaking locomotion */ }
	virtual void UnCrouch(bool bClientSimulation = false) override { /* Overriden to prevent ACharacter::UnCrouch from breaking locomotion */ }

public:

	virtual USceneComponent* GetVROrigin();
	virtual UCameraComponent* GetHMDCamera();
	virtual ULocomotionComponent* GetLocomotion();
	virtual UHandControllerComponent* GetLeftHand();
	virtual UHandControllerComponent* GetRightHand();

};
