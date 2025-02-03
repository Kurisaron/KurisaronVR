// Fill out your copyright notice in the Description page of Project Settings.


#include "LocomotionComponent.h"
#include "VRCharacter.h"

ULocomotionComponent::ULocomotionComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	bOrientRotationToMovement = false;
	JumpZVelocity = 800.f;
	AirControl = 0.35f;
	MaxWalkSpeed = 600.f;
	MinAnalogWalkSpeed = 20.f;
	BrakingDecelerationWalking = 2000.f;
	BrakingDecelerationFalling = 1500.0f;

	MaxHeight = 180.0f;
	HMD_HeightOffset = 10.0f;
	CrouchThresholdRatio = 0.6f;
	ProneThresholdRatio = 0.4f;
	bDebugRoomscale = true;

	DodgePower = 10000.0f;
}

void ULocomotionComponent::SetupPlayerInput(UEnhancedInputLocalPlayerSubsystem* Subsystem, UEnhancedInputComponent* EnhancedInput)
{
	if (Subsystem)
	{
		// Add keybinding maps to input
		Subsystem->AddMappingContext(LocomotionInputMap, 0);
	}

	if (EnhancedInput)
	{
		// Bind subscriber to Move Action
		EnhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ULocomotionComponent::Move);
		// Bind subscriber to Turn Action
		EnhancedInput->BindAction(TurnAction, ETriggerEvent::Triggered, this, &ULocomotionComponent::Turn);
		// Bind subscribers to Jump Action
		EnhancedInput->BindAction(JumpAction, ETriggerEvent::Started, this, &ULocomotionComponent::Jump_Started);
		EnhancedInput->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ULocomotionComponent::Jump_Triggered);
		EnhancedInput->BindAction(JumpAction, ETriggerEvent::Completed, this, &ULocomotionComponent::Jump_Completed);
		// Bind subscribers to Dodge Action
		EnhancedInput->BindAction(DodgeAction, ETriggerEvent::Started, this, &ULocomotionComponent::Dodge_Started);
		EnhancedInput->BindAction(DodgeAction, ETriggerEvent::Triggered, this, &ULocomotionComponent::Dodge_Triggered);
		EnhancedInput->BindAction(DodgeAction, ETriggerEvent::Completed, this, &ULocomotionComponent::Dodge_Completed);
		// Bind subscriber to Calibrate Action
		EnhancedInput->BindAction(CalibrateAction, ETriggerEvent::Triggered, this, &ULocomotionComponent::Calibrate);
		
	}
}

void ULocomotionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	TickRoomscaleTracking();
}

void ULocomotionComponent::TickRoomscaleTracking()
{
	if (AVRCharacter* VR_Character = Cast<AVRCharacter>(GetOwner()))
	{
		// Collect pointers to necessary components from the owner VRCharacter
		USceneComponent* VR_Origin = VR_Character->GetVROrigin();
		UCameraComponent* HMD_Camera = VR_Character->GetHMDCamera();
		UCapsuleComponent* LocomotionCapsule = VR_Character->GetCapsuleComponent();

		// Fetch transform-related data for determining necessary changes
		FTransform OriginTransform = VR_Origin->GetComponentTransform();
		FTransform CameraTransform = HMD_Camera->GetComponentTransform();
		FTransform CapsuleTransform = LocomotionCapsule->GetComponentTransform();

		// Update roomscale translation
		FVector LocationDelta = CameraTransform.GetLocation() - CapsuleTransform.GetLocation();
		LocationDelta.Z = 0;
		LocomotionCapsule->AddWorldOffset(LocationDelta, true);
		VR_Origin->AddWorldOffset(-LocationDelta);

		// Update height scaling
		float HeightDelta = GetCurrentHeight();
		float NewHalfHeight = HeightDelta / 2;
		LocomotionCapsule->SetCapsuleHalfHeight(NewHalfHeight, true);
		VR_Origin->SetRelativeLocation(FVector(VR_Origin->GetRelativeLocation().X, VR_Origin->GetRelativeLocation().Y, -NewHalfHeight));

		// Perform in-game debug operations if enabled
		if (bDebugRoomscale)
		{
			// Display the VR origin component-wise
			FColor ComponentOriginColor = FColor::Blue;
			float ComponentOriginRadius = 25.0f;
			DrawDebugSphere(GetWorld(), OriginTransform.GetLocation(), ComponentOriginRadius, 16, ComponentOriginColor);

			// Display the VR origin system-wise
			FColor SystemOriginColor = FColor::Cyan;
			float SystemOriginRadius = ComponentOriginRadius + 5.0f;
			if (GEngine && GEngine->XRSystem)
			{
				EHMDTrackingOrigin::Type TrackingOriginType = GEngine->XRSystem->GetTrackingOrigin();
				FTransform SystemOriginTransform;
				if (GEngine->XRSystem->GetTrackingOriginTransform(TrackingOriginType, SystemOriginTransform))
				{
					DrawDebugSphere(GetWorld(), SystemOriginTransform.GetLocation(), SystemOriginRadius, 16, SystemOriginColor);
				}
			}

			// Display the locomotion capsule's location
			FColor CapsuleLocationColor = FColor::Yellow;
			float CapsuleLocationRadius = LocomotionCapsule->GetScaledCapsuleRadius();
			DrawDebugSphere(GetWorld(), LocomotionCapsule->GetComponentLocation(), CapsuleLocationRadius, 16, CapsuleLocationColor);

		}
	}
	else
		UE_LOG(LogTemp, Warning, TEXT("Locomotion component attempted to update roomscale translation, but it is not attached to a VR Character"));
		
}

void ULocomotionComponent::Move(const FInputActionValue& Value)
{
	MoveInput = Value.Get<FVector2D>();

	if (AVRCharacter* VR_Character = Cast<AVRCharacter>(GetOwner()))
	{
		if (AController* Controller = VR_Character->GetController())
		{
			if (UCameraComponent* HMD = VR_Character->GetHMDCamera())
			{
				FVector ForwardDirection = HMD->GetForwardVector();
				ForwardDirection.Z = 0;
				FVector RightDirection = HMD->GetRightVector();
				RightDirection.Z = 0;

				AddInputVector((ForwardDirection * MoveInput.Y) + (RightDirection * MoveInput.X));
			}
			else
				UE_LOG(LogTemp, Warning, TEXT("Locomotion component attempted to move, but its owner VR Character does not have a HMD camera"));
		}
		else
			UE_LOG(LogTemp, Warning, TEXT("Locomotion component attempted to move, but its owning VR Character does not have a controller"));
	}
	else
		UE_LOG(LogTemp, Warning, TEXT("Locomotion component attempted to move, but it is not attached to a VR Character"));
}

void ULocomotionComponent::Turn(const FInputActionValue& Value)
{
	float TurnInput = Value.Get<float>();

	if (AVRCharacter* VR_Character = Cast<AVRCharacter>(GetOwner()))
	{
		if (APlayerController* Controller = Cast<APlayerController>(VR_Character->GetController()))
		{
			if (TurnInput != 0.0f && Controller->IsLocalPlayerController())
			{
				// Add yaw input to controller
				Controller->AddYawInput(TurnInput);
			}
		}
		else
			UE_LOG(LogTemp, Warning, TEXT("Locomotion component attempted to turn, but its owner VR Character does not have a controller"));
	}
	else
		UE_LOG(LogTemp, Warning, TEXT("Locomotion component attempted to turn, but it is not attached to a VR Character"));
}

void ULocomotionComponent::Jump_Started(const FInputActionValue& Value)
{
	float JumpInput = Value.Get<float>();

	if (AVRCharacter* VR_Character = Cast<AVRCharacter>(GetOwner()))
	{
		if (!Prone())
			VR_Character->Jump();
	}
}

void ULocomotionComponent::Jump_Triggered(const FInputActionValue& Value)
{
	float JumpInput = Value.Get<float>();
}

void ULocomotionComponent::Jump_Completed(const FInputActionValue& Value)
{
	float JumpInput = Value.Get<float>();

	if (AVRCharacter* VR_Character = Cast<AVRCharacter>(GetOwner()))
	{
		VR_Character->StopJumping();
	}
}

void ULocomotionComponent::Dodge_Started(const FInputActionValue& Value)
{
	float DodgeInput = Value.Get<float>();

	DefaultDodge(true);
}

void ULocomotionComponent::Dodge_Triggered(const FInputActionValue& Value)
{
	float DodgeInput = Value.Get<float>();
}

void ULocomotionComponent::Dodge_Completed(const FInputActionValue& Value)
{
	float DodgeInput = Value.Get<float>();

	DefaultDodge(false);
}

void ULocomotionComponent::Calibrate(const FInputActionValue& Value)
{
	bool CalibrateInput = Value.Get<bool>();

	if (AVRCharacter* VR_Character = Cast<AVRCharacter>(GetOwner()))
	{
		if (CalibrateInput)
		{
			MaxHeight = VR_Character->GetHMDCamera()->GetComponentLocation().Z - VR_Character->GetVROrigin()->GetComponentLocation().Z;
		}
	}
}

void ULocomotionComponent::DefaultDodge(bool Started)
{
	if (Started)
	{
		if (AVRCharacter* VR_Character = Cast<AVRCharacter>(GetOwner()))
		{
			if (AController* Controller = VR_Character->GetController())
			{
				if (UCameraComponent* HMD = VR_Character->GetHMDCamera())
				{
					FVector ForwardDirection = HMD->GetForwardVector();
					ForwardDirection.Z = 0;
					FVector RightDirection = HMD->GetRightVector();
					RightDirection.Z = 0;

					FVector2D DodgeInput = MoveInput != FVector2D::ZeroVector ? MoveInput : FVector2D(0, -1);
					FVector DodgeVector = (ForwardDirection * DodgeInput.Y) + (RightDirection * DodgeInput.X);
					AddImpulse(DodgeVector * DodgePower, true);
				}
				else
					UE_LOG(LogTemp, Warning, TEXT("Locomotion component attempted to dodge, but its owner VR Character does not have a HMD camera"));
			}
			else
				UE_LOG(LogTemp, Warning, TEXT("Locomotion component attempted to dodge, but its owning VR Character does not have a controller"));
		}
		else
			UE_LOG(LogTemp, Warning, TEXT("Locomotion component attempted to dodge, but it is not attached to a VR Character"));
	}
}

float ULocomotionComponent::GetCurrentHeight(UCameraComponent* HMD, USceneComponent* Floor)
{
	if (AVRCharacter* VR_Character = Cast<AVRCharacter>(GetOwner()))
	{
		HMD = HMD != nullptr ? HMD : VR_Character->GetHMDCamera();
		Floor = Floor != nullptr ? Floor : VR_Character->GetVROrigin();

		return HMD->GetComponentLocation().Z + HMD_HeightOffset - Floor->GetComponentLocation().Z;
	}
	else
		return 0.0f;
}

bool ULocomotionComponent::Standing()
{
	return (CrouchThresholdRatio * MaxHeight) < GetCurrentHeight();
}

bool ULocomotionComponent::Crouching()
{
	float CurrentHeight = GetCurrentHeight();
	return (ProneThresholdRatio * MaxHeight) < CurrentHeight && CurrentHeight < (CrouchThresholdRatio * MaxHeight);
}

bool ULocomotionComponent::Prone()
{
	return GetCurrentHeight() < (ProneThresholdRatio * MaxHeight);
}