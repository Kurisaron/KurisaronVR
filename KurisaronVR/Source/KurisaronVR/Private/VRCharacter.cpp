// Fill out your copyright notice in the Description page of Project Settings.


#include "VRCharacter.h"
#include "HandControllerComponent.h"
#include "LocomotionComponent.h"

// Sets default values
AVRCharacter::AVRCharacter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer.SetDefaultSubobjectClass<ULocomotionComponent>(ACharacter::CharacterMovementComponentName))
{
 	// Set this character to call Tick() every frame
	PrimaryActorTick.bCanEverTick = true;

	// Set the movement capsule size to allow for effective movement
	UCapsuleComponent* Capsule = GetCapsuleComponent();
	Capsule->InitCapsuleSize(10.0f, 90.0f);
	Capsule->SetHiddenInGame(false);
	Capsule->SetLineThickness(0.5f);

	// Only allow the controller's yaw input to influence this character's rotation
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = true;
	bUseControllerRotationRoll = false;

	// VR TRACKING ORIGIN
	VR_Origin = CreateDefaultSubobject<USceneComponent>(VR_OriginComponentName);
	VR_Origin->SetupAttachment(Capsule);
	VR_Origin->SetRelativeLocation(FVector(0.0, 0.0, -90.0));

	// HEAD-MOUNTED DISPLAY CAMERA
	HMD_Camera = CreateDefaultSubobject<UCameraComponent>(HMD_CameraComponentName);
	HMD_Camera->SetupAttachment(VR_Origin);
	HMD_Camera->bLockToHmd = true;

	// HANDS 
	// Create components
	LeftHandController = CreateDefaultSubobject<UHandControllerComponent>(HandControllerComponentNames[0]);
	RightHandController = CreateDefaultSubobject<UHandControllerComponent>(HandControllerComponentNames[1]);
	LeftHandHapticTarget = CreateDefaultSubobject<USphereComponent>(HandHapticTargetComponentNames[0]);
	RightHandHapticTarget = CreateDefaultSubobject<USphereComponent>(HandHapticTargetComponentNames[1]);
	LeftHandHapticCollider = CreateDefaultSubobject<UBoxComponent>(HandHapticColliderComponentNames[0]);
	RightHandHapticCollider = CreateDefaultSubobject<UBoxComponent>(HandHapticColliderComponentNames[1]);
	LeftHandHapticConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(HandHapticConstraintComponentNames[0]);
	RightHandHapticConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(HandHapticConstraintComponentNames[1]);
	LeftHandGrabConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(HandGrabConstraintComponentNames[0]);
	RightHandGrabConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(HandGrabConstraintComponentNames[1]);
	// Perform setup operations on hand components
	UHandControllerComponent* Hands[2] = { LeftHandController, RightHandController };
	USphereComponent* HapticTargets[2] = { LeftHandHapticTarget, RightHandHapticTarget };
	UBoxComponent* HapticColliders[2] = { LeftHandHapticCollider, RightHandHapticCollider };
	UPhysicsConstraintComponent* HapticConstraints[2] = { LeftHandHapticConstraint, RightHandHapticConstraint };
	UPhysicsConstraintComponent* GrabConstraints[2] = { LeftHandGrabConstraint, RightHandGrabConstraint };
	for (int i = 0; i < 2; i++)
	{
		if (UHandControllerComponent* Hand = Hands[i])
		{
			// Perform hand controller setup
			Hand->SetupAttachment(VR_Origin);
			Hand->SetTrackingSource(i == 0 ? EControllerHand::Left : EControllerHand::Right);

			if (USphereComponent* Target = HapticTargets[i])
			{
				// Perform haptic collision target setup
				Target->SetupAttachment(Hand);
				Target->SetSphereRadius(4.0f);
				Target->SetHiddenInGame(false);
				Target->SetLineThickness(0.5f);

				if (UBoxComponent* Collider = HapticColliders[i])
				{
					// Perform haptic collider setup
					Collider->SetupAttachment(Target);
					Collider->SetBoxExtent(FVector::OneVector * 4.0f);
					Collider->SetSimulatePhysics(true);
					Collider->SetHiddenInGame(false);
					Collider->SetLineThickness(0.5f);

					if (UPhysicsConstraintComponent* HapticConstraint = HapticConstraints[i])
					{
						// Perform haptic collision physics constraint setup
						HapticConstraint->SetupAttachment(Target);
						HapticConstraint->SetRelativeRotation(FRotator(-90.0, 0.0, 0.0));
						HapticConstraint->SetUsingAbsoluteScale(true);
						HapticConstraint->SetDisableCollision(true);
						HapticConstraint->SetLinearXLimit(ELinearConstraintMotion::LCM_Free, 0.0f);
						HapticConstraint->SetLinearYLimit(ELinearConstraintMotion::LCM_Free, 0.0f);
						HapticConstraint->SetLinearZLimit(ELinearConstraintMotion::LCM_Free, 0.0f);
						HapticConstraint->SetAngularSwing1Limit(EAngularConstraintMotion::ACM_Locked, 0.0f);
						HapticConstraint->SetAngularSwing2Limit(EAngularConstraintMotion::ACM_Locked, 0.0f);
						HapticConstraint->SetAngularTwistLimit(EAngularConstraintMotion::ACM_Locked, 0.0f);
						FConstraintInstance* ConstraintInstance = &HapticConstraint->ConstraintInstance;
						ConstraintInstance->SetLinearPositionDrive(true, true, true);
						ConstraintInstance->SetLinearVelocityDrive(true, true, true);
						ConstraintInstance->SetLinearDriveParams(10000.0f, 100.0f, 0.0f);
						HapticConstraint->SetConstrainedComponents(Target, FName(), Collider, FName());

						Hand->SetHapticComponents(Target, Collider, HapticConstraint);
					}

					if (UPhysicsConstraintComponent* GrabConstraint = GrabConstraints[i])
					{
						// Perform grab physics constraint setup
						GrabConstraint->SetupAttachment(Collider);
						GrabConstraint->SetRelativeRotation(FRotator(0.0, i == 0 ? 90.0 : -90.0, 0.0));
						GrabConstraint->SetUsingAbsoluteScale(true);
						GrabConstraint->SetDisableCollision(true);
						GrabConstraint->SetLinearXLimit(ELinearConstraintMotion::LCM_Locked, 0.0f);
						GrabConstraint->SetLinearYLimit(ELinearConstraintMotion::LCM_Locked, 0.0f);
						GrabConstraint->SetLinearZLimit(ELinearConstraintMotion::LCM_Locked, 0.0f);
						GrabConstraint->SetAngularSwing1Limit(EAngularConstraintMotion::ACM_Locked, 0.0f);
						GrabConstraint->SetAngularSwing2Limit(EAngularConstraintMotion::ACM_Locked, 0.0f);
						GrabConstraint->SetAngularTwistLimit(EAngularConstraintMotion::ACM_Locked, 0.0f);

						Hand->SetGrabConstraint(GrabConstraint);
					}
				}
			}
		}
	}

}

// Called when the game starts or when spawned
void AVRCharacter::BeginPlay()
{
	Super::BeginPlay();

	BeginVR();

}

void AVRCharacter::BeginVR()
{
	if (GEngine && GEngine->XRSystem)
		GEngine->XRSystem->SetTrackingOrigin(EHMDTrackingOrigin::Stage);

	if (UWorld* World = GetWorld())
		UKismetSystemLibrary::ExecuteConsoleCommand(World, TEXT("vr.PixelDensity 1.0"));
}

// Called every frame
void AVRCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AVRCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
		UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent);

		if (!Subsystem || !EnhancedInput)
		{
			UE_LOG(LogTemp, Warning, TEXT("Enhanced Input subsystem or component is null, cannot complete input setup"));
			return;
		}

		if (LeftHandController)
			LeftHandController->SetupPlayerInput(Subsystem, EnhancedInput);
		else
			UE_LOG(LogTemp, Warning, TEXT("Left hand controller is null, cannot setup input"));

		if (RightHandController)
			RightHandController->SetupPlayerInput(Subsystem, EnhancedInput);
		else
			UE_LOG(LogTemp, Warning, TEXT("Right hand controller is null, cannot setup input"));

		if (ULocomotionComponent* Locomotion = Cast<ULocomotionComponent>(GetCharacterMovement()))
			Locomotion->SetupPlayerInput(Subsystem, EnhancedInput);
		else
			UE_LOG(LogTemp, Warning, TEXT("Locomotion is null, cannot setup input"));
	}
}


USceneComponent* AVRCharacter::GetVROrigin()
{
	return VR_Origin;
}

UCameraComponent* AVRCharacter::GetHMDCamera()
{
	return HMD_Camera;
}

ULocomotionComponent* AVRCharacter::GetLocomotion()
{
	return Cast<ULocomotionComponent>(GetCharacterMovement());
}

UHandControllerComponent* AVRCharacter::GetLeftHand()
{
	return LeftHandController;
}

UHandControllerComponent* AVRCharacter::GetRightHand()
{
	return RightHandController;
}
