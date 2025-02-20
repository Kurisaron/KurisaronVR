// Fill out your copyright notice in the Description page of Project Settings.


#include "VRCharacter.h"
#include "HandControllerComponent.h"
#include "LocomotionComponent.h"

// Sets default values
AVRCharacter::AVRCharacter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer.SetDefaultSubobjectClass<ULocomotionComponent>(ACharacter::CharacterMovementComponentName))
{
 	// Set this character to call Tick() every frame
	PrimaryActorTick.bCanEverTick = true;

	// Only allow the controller's yaw input to influence this character's rotation
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = true;
	bUseControllerRotationRoll = false;

	// Set the movement capsule size to allow for effective movement
	UCapsuleComponent* Capsule = GetCapsuleComponent();
	Capsule->InitCapsuleSize(10.0f, 90.0f);
	Capsule->SetHiddenInGame(false);
	Capsule->SetLineThickness(0.5f);

	USkeletalMeshComponent* CharacterMesh = GetMesh();
	CharacterMesh->SetRelativeLocation(FVector(
		0.0,
		0.0,
		-90.0));
	CharacterMesh->SetRelativeRotation(FRotator(
		0.0,
		-90.0,
		0.0
	));
	CharacterMesh->SetHiddenInGame(true);

	// VR TRACKING ORIGIN
	VR_Origin = CreateDefaultSubobject<USceneComponent>(VR_OriginComponentName);
	VR_Origin->SetupAttachment(Capsule);
	VR_Origin->SetRelativeLocation(FVector(
		0.0,
		0.0,
		-90.0));

	// HEAD-MOUNTED DISPLAY CAMERA
	HMD_Camera = CreateDefaultSubobject<UCameraComponent>(HMD_CameraComponentName);
	HMD_Camera->SetupAttachment(VR_Origin);
	HMD_Camera->bLockToHmd = true;

	// HANDS 
	// Create components
	LeftHandController = CreateDefaultSubobject<UHandControllerComponent>(HandControllerComponentNames[0]);
	RightHandController = CreateDefaultSubobject<UHandControllerComponent>(HandControllerComponentNames[1]);
	LeftHandHapticTarget = CreateDefaultSubobject<USkeletalMeshComponent>(HandHapticTargetComponentNames[0]);
	RightHandHapticTarget = CreateDefaultSubobject<USkeletalMeshComponent>(HandHapticTargetComponentNames[1]);
	LeftHandHapticCollider = CreateDefaultSubobject<USkeletalMeshComponent>(HandHapticColliderComponentNames[0]);
	RightHandHapticCollider = CreateDefaultSubobject<USkeletalMeshComponent>(HandHapticColliderComponentNames[1]);
	LeftHandHapticConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(HandHapticConstraintComponentNames[0]);
	RightHandHapticConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(HandHapticConstraintComponentNames[1]);
	LeftHandGrabConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(HandGrabConstraintComponentNames[0]);
	RightHandGrabConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(HandGrabConstraintComponentNames[1]);
	
	// Perform setup operations on hand components
	UHandControllerComponent* Hands[2] = { LeftHandController, RightHandController };
	USkeletalMeshComponent* HapticTargets[2] = { LeftHandHapticTarget, RightHandHapticTarget };
	USkeletalMeshComponent* HapticColliders[2] = { LeftHandHapticCollider, RightHandHapticCollider };
	UPhysicsConstraintComponent* HapticConstraints[2] = { LeftHandHapticConstraint, RightHandHapticConstraint };
	UPhysicsConstraintComponent* GrabConstraints[2] = { LeftHandGrabConstraint, RightHandGrabConstraint };
	for (int i = 0; i < 2; i++)
	{
		UHandControllerComponent* Hand = Hands[i];
		USkeletalMeshComponent* Target = HapticTargets[i];
		USkeletalMeshComponent* Collider = HapticColliders[i];
		UPhysicsConstraintComponent* HapticConstraint = HapticConstraints[i];
		UPhysicsConstraintComponent* GrabConstraint = GrabConstraints[i];

		if (Hand)
		{
			// Perform hand controller setup
			Hand->SetupAttachment(VR_Origin);
			Hand->SetTrackingSource(i == 0 ? EControllerHand::Left : EControllerHand::Right);

			if (Target)
			{
				// Perform haptic collision target setup
				Target->SetupAttachment(Hand);
				Target->SetRelativeLocation(FVector(
					0.0,
					i == 0 ? -3.5 : 3.5,
					7.5));
				Target->SetRelativeRotation(FRotator(
					0.0,
					i == 0 ? 180.0 : 0.0,
					90.0));
				Target->SetHiddenInGame(false);
				Target->SetCollisionEnabled(ECollisionEnabled::Type::QueryOnly);
				Target->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);

				if (Collider)
				{
					// Perform haptic collider setup
					Collider->SetupAttachment(Target);
					Collider->SetHiddenInGame(false);
					Collider->SetSimulatePhysics(true);
					Collider->SetNotifyRigidBodyCollision(true);
					Collider->SetGenerateOverlapEvents(true);
					Collider->SetCollisionEnabled(ECollisionEnabled::Type::QueryAndPhysics);
					Collider->SetCollisionObjectType(ECollisionChannel::ECC_PhysicsBody);
					Collider->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);
					Collider->SetUseCCD(true);
					Collider->bMultiBodyOverlap = true;

					if (HapticConstraint)
					{
						// Perform haptic collision physics constraint setup
						HapticConstraint->SetupAttachment(Target);
						HapticConstraint->SetRelativeRotation(FRotator(
							0.0,
							90.0,
							90.0));
						HapticConstraint->SetUsingAbsoluteScale(true);
						HapticConstraint->SetDisableCollision(true);
						HapticConstraint->SetLinearXLimit(ELinearConstraintMotion::LCM_Limited, 90.0f);
						HapticConstraint->SetLinearYLimit(ELinearConstraintMotion::LCM_Limited, 90.0f);
						HapticConstraint->SetLinearZLimit(ELinearConstraintMotion::LCM_Limited, 90.0f);
						HapticConstraint->SetAngularSwing1Limit(EAngularConstraintMotion::ACM_Locked, 0.0f);
						HapticConstraint->SetAngularSwing2Limit(EAngularConstraintMotion::ACM_Locked, 0.0f);
						HapticConstraint->SetAngularTwistLimit(EAngularConstraintMotion::ACM_Locked, 0.0f);
						FConstraintInstance* ConstraintInstance = &HapticConstraint->ConstraintInstance;
						ConstraintInstance->SetLinearPositionDrive(true, true, true);
						ConstraintInstance->SetLinearVelocityDrive(true, true, true);
						ConstraintInstance->SetLinearDriveParams(20000.0f, 200.0f, 0.0f);
						FName HandBone = HandHapticComponentsBoneNames[i];

						Hand->SetHapticComponents(Target, Collider, HapticConstraint);
						Hand->SetHapticBone(HandBone);
					}

					if (GrabConstraint)
					{
						// Perform grab physics constraint setup
						GrabConstraint->SetupAttachment(Collider);
						GrabConstraint->SetRelativeLocation(FVector(0.0, 7.5, -1.75));
						GrabConstraint->SetRelativeRotation(FRotator(-90.0, 0.0, 0.0));
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

			/*
			if (UPhysicsConstraintComponent* GrabConstraint = GrabConstraints[i])
			{
				
			}
			*/
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
