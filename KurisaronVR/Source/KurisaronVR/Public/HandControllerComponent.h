// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"
#include "MotionControllerComponent.h"
#include "HandControllerComponent.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType, Category = "VR", meta = (BlueprintSpawnableComponent))
class KURISARONVR_API UHandControllerComponent : public UMotionControllerComponent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|Interaction", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputMappingContext> InteractionInputMap;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|Pose", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputMappingContext> PoseInputMap;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|Interaction", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> GrabAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|Interaction", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> FireAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|Interaction", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> UseAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|Interaction", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> AltUseAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|Pose", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> GraspAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|Pose", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> IndexCurlAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|Pose", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> PointAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|Pose", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> ThumbUpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Debug", meta = (AllowPrivateAccess = "true"))
	bool bShowDebug = true;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Debug", meta = (AllowPrivateAccess = "true", EditCondition = "bShowDebug", EditConditionHides))
	bool bShowTransform = true;

public:

	UHandControllerComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	virtual void SetupPlayerInput(UEnhancedInputLocalPlayerSubsystem* Subsystem, UEnhancedInputComponent* EnhancedInput);

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:

	/**
	 * INPUT ACTION SUBSCRIBERS
	*/

	void Grab_Started(const FInputActionValue& Value);

	void Grab_Triggered(const FInputActionValue& Value);

	void Grab_Completed(const FInputActionValue& Value);

	/**
	 * INPUT ENCAPSULATES (Functions utilized by above subscribers to perform operations)
	*/

public:
	// PUBLIC GETTERS
	
	// Return the component used as target for haptic collision
	USphereComponent* GetHapticTarget();
	// Return the collider used for haptic collision
	UBoxComponent* GetHapticCollider();
	// Return the physics constraint used to drive forces for haptic collision
	UPhysicsConstraintComponent* GetHapticConstraint();
	// Return the physics constraint used for grabbing
	UPhysicsConstraintComponent* GetGrabConstraint();

protected:
	// DEBUG

	// Display debug elements in-game to more easily test features/mechanics
	virtual void Debug();

};
