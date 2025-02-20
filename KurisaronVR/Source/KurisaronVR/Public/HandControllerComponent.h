// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/KismetSystemLibrary.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"
#include "MotionControllerComponent.h"
#include "HandControllerComponent.generated.h"

class UGripComponent;

USTRUCT(BlueprintType)
struct KURISARONVR_API FHandPose
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float Grasp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float IndexCurl;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float Point;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float ThumbUp;

	FHandPose()
	{
		Grasp = IndexCurl = Point = ThumbUp = 0.0;
	}
};

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType, Category = "VR", meta = (BlueprintSpawnableComponent))
class KURISARONVR_API UHandControllerComponent : public UMotionControllerComponent
{
	GENERATED_BODY()

	USkeletalMeshComponent* HapticTarget;
	USkeletalMeshComponent* HapticCollider;
	UPhysicsConstraintComponent* HapticConstraint;
	UPhysicsConstraintComponent* GrabConstraint;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Hand|Input|Interaction", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputMappingContext> InteractionInputMap;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Hand|Input|Pose", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputMappingContext> PoseInputMap;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Hand|Input|Interaction", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> GrabAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Hand|Input|Interaction", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> FireAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Hand|Input|Interaction", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> UseAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Hand|Input|Interaction", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> AltUseAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Hand|Input|Pose", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> GraspAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Hand|Input|Pose", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> IndexCurlAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Hand|Input|Pose", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> PointAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Hand|Input|Pose", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> ThumbUpAction;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Hand|Input|Interaction", meta = (AllowPrivateAccess = "true"))
	float GrabInput;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Hand|Input|Interaction", meta = (AllowPrivateAccess = "true"))
	float FireInput;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Hand|Input|Interaction", meta = (AllowPrivateAccess = "true"))
	float UseInput;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Hand|Input|Interaction", meta = (AllowPrivateAccess = "true"))
	float AltUseInput;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Hand|Input|Pose", meta = (AllowPrivateAccess = "true"))
	FHandPose HandPose;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Hand|Haptic Collision", meta = (AllowPrivateAccess = "true"))
	FName HapticBone;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Hand|Grab", meta = (AllowPrivateAccess = "true"))
	float GrabRadius;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Hand|Grab", meta = (AllowPrivateAccess = "true"))
	UPrimitiveComponent* GrabbedPrimitive;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Hand|Debug", meta = (AllowPrivateAccess = "true"))
	bool bShowDebug;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Hand|Debug", meta = (AllowPrivateAccess = "true", EditCondition = "bShowDebug", EditConditionHides))
	bool bDebugTransform;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Hand|Debug", meta = (AllowPrivateAccess = "true", EditCondition = "bShowDebug", EditConditionHides))
	bool bDebugGrabbing;

public:

	UHandControllerComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:

	virtual void BeginPlay() override;

public:

	virtual void SetupPlayerInput(UEnhancedInputLocalPlayerSubsystem* Subsystem, UEnhancedInputComponent* EnhancedInput);

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:

	/**
	 * INPUT ACTION SUBSCRIBERS
	*/

	void Grab_Started(const FInputActionValue& Value);

	void Grab_Triggered(const FInputActionValue& Value);

	void Grab_Completed(const FInputActionValue& Value);

	void Fire_Started(const FInputActionValue& Value);

	void Fire_Triggered(const FInputActionValue& Value);

	void Fire_Completed(const FInputActionValue& Value);

	void Use_Started(const FInputActionValue& Value);

	void Use_Triggered(const FInputActionValue& Value);

	void Use_Completed(const FInputActionValue& Value);

	void AltUse_Started(const FInputActionValue& Value);

	void AltUse_Triggered(const FInputActionValue& Value);

	void AltUse_Completed(const FInputActionValue& Value);

	void Pose_Grasp(const FInputActionValue& Value);

	void Pose_IndexCurl(const FInputActionValue& Value);

	void Pose_Point(const FInputActionValue& Value);

	void Pose_ThumbUp(const FInputActionValue& Value);


	/**
	 * INPUT ENCAPSULATES (Functions utilized by above subscribers to perform operations)
	*/

	virtual void Grab(bool Pressed);

public:
	// PUBLIC GETTERS/SETTERS

	void SetHapticComponents(USkeletalMeshComponent* Target, USkeletalMeshComponent* Collider, UPhysicsConstraintComponent* Constraint);
	void SetHapticBone(FName Bone);
	void SetGrabConstraint(UPhysicsConstraintComponent* Constraint);
	
	// Return the component used as target for haptic collision
	USkeletalMeshComponent* GetHapticTarget();
	// Return the collider used for haptic collision
	USkeletalMeshComponent* GetHapticCollider();
	// Return the physics constraint used to drive forces for haptic collision
	UPhysicsConstraintComponent* GetHapticConstraint();
	// Return the physics constraint used for grabbing
	UPhysicsConstraintComponent* GetGrabConstraint();

protected:
	// DEBUG

	// Display debug elements in-game to more easily test features/mechanics
	virtual void Debug();

};
