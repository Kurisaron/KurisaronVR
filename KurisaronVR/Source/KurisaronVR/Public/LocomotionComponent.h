// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "LocomotionComponent.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class KURISARONVR_API ULocomotionComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Locomotion|Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputMappingContext> LocomotionInputMap;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Locomotion|Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> MoveAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Locomotion|Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> TurnAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Locomotion|Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> JumpAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Locomotion|Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> DodgeAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Locomotion|Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> CalibrateAction;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Locomotion|Input", meta = (AllowPrivateAccess = "true"))
	FVector2D MoveInput = FVector2D::ZeroVector;

	// Current value for the player's max height. Used to evaluate standing/crouching/prone state based on head's current distance above the tracking origin
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Locomotion|Roomscale|Height", meta = (AllowPrivateAccess = "true"))
	float MaxHeight;
	// Height offset added so capsule accurately matches player's height (above the HMD) during roomscale tracking
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Locomotion|Roomscale|Height", meta = (AllowPrivateAccess = "true"))
	float HMD_HeightOffset;
	// Ratio to the player's max height that helps evaluate whether the player is crouching. If the current height is below the value equal to the given ratio multiplied against the max height, the player is considered crouching
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Locomotion|Roomscale|Height", meta = (AllowPrivateAccess = "true", ClampMin = "0.0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0"))
	float CrouchThresholdRatio;
	// Ratio to the player's max height that helps evaluate whether the player is prone. If the current height is below the value equal to the given ratio multiplied against the max height, the player is considered prone
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Locomotion|Roomscale|Height", meta = (AllowPrivateAccess = "true", ClampMin = "0.0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0"))
	float ProneThresholdRatio;
	// True = Display in-game debugging elements to more easily understand roomscale operations
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Locomotion|Roomscale|Debug", meta = (AllowPrivateAccess = "true"))
	bool bDebugRoomscale;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Locomotion|Dodging", meta = (AllowPrivateAccess = "true"))
	float DodgePower;

public:

	ULocomotionComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	virtual void SetupPlayerInput(UEnhancedInputLocalPlayerSubsystem* Subsystem, UEnhancedInputComponent* EnhancedInput);

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:

	virtual void TickRoomscaleTracking();

	/**
	 * INPUT ACTION SUBSCRIBERS
	*/
	
	// Subscribed to Move Input Action to perform locomotion-style movement
	void Move(const FInputActionValue& Value);
	// Subscribed to Turn Input Action to turn the player on the spot
	void Turn(const FInputActionValue& Value);
	// Subscribed to Jump Input Action to run when input is started
	void Jump_Started(const FInputActionValue& Value);
	// Subscribed to Jump Input Action to run when input is being triggered
	void Jump_Triggered(const FInputActionValue& Value);
	// Subscribed to Jump Input Action to run when input is ended
	void Jump_Completed(const FInputActionValue& Value);
	// Subscribed to Dodge Input Action to run when input is started
	void Dodge_Started(const FInputActionValue& Value);
	// Subscribed to Dodge Input Action to run when input is being triggered
	void Dodge_Triggered(const FInputActionValue& Value);
	// Subscribed to Dodge Input Action to run when input is ended
	void Dodge_Completed(const FInputActionValue& Value);
	// Subscribed to Calibrate Input Action to set the max height for the character
	void Calibrate(const FInputActionValue& Value);

	/**
	 * INPUT ENCAPSULATES (Functions utilized by above subscribers to perform operations)
	*/

	virtual void DefaultDodge(bool Started);

public:

	virtual float GetCurrentHeight(UCameraComponent* HMD = nullptr, USceneComponent* Floor = nullptr);

	virtual bool Standing();
	virtual bool Crouching();
	virtual bool Prone();

};
