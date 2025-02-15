// Fill out your copyright notice in the Description page of Project Settings.


#include "HandControllerComponent.h"
#include "GripComponent.h"
#include "Item.h"

UHandControllerComponent::UHandControllerComponent(const FObjectInitializer& ObjectInitializer): Super(ObjectInitializer)
{
	PrimaryComponentTick.bCanEverTick = true;

	GrabInput = 0.0f;
	FireInput = 0.0f;
	UseInput = 0.0f;
	AltUseInput = 0.0f;

	GrabRadius = 10.0f;

	bShowDebug = true;
	bDebugTransform = true;
	bDebugGrabbing = true;
}

void UHandControllerComponent::SetupPlayerInput(UEnhancedInputLocalPlayerSubsystem* Subsystem, UEnhancedInputComponent* EnhancedInput)
{
	if (Subsystem)
	{
		Subsystem->AddMappingContext(InteractionInputMap, 0);
		Subsystem->AddMappingContext(PoseInputMap, 0);
	}

	if (EnhancedInput)
	{
		EnhancedInput->BindAction(GrabAction, ETriggerEvent::Started, this, &UHandControllerComponent::Grab_Started);
		EnhancedInput->BindAction(GrabAction, ETriggerEvent::Triggered, this, &UHandControllerComponent::Grab_Triggered);
		EnhancedInput->BindAction(GrabAction, ETriggerEvent::Completed, this, &UHandControllerComponent::Grab_Completed);
	}
}

void UHandControllerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	Debug();
}

void UHandControllerComponent::Grab_Started(const FInputActionValue& Value)
{
	GrabInput = Value.Get<float>();

	Grab(true);
}

void UHandControllerComponent::Grab_Triggered(const FInputActionValue& Value)
{
	GrabInput = Value.Get<float>();
}

void UHandControllerComponent::Grab_Completed(const FInputActionValue& Value)
{
	GrabInput = Value.Get<float>();

	Grab(false);
}

void UHandControllerComponent::Fire_Started(const FInputActionValue& Value)
{
	FireInput = Value.Get<float>();
}

void UHandControllerComponent::Fire_Triggered(const FInputActionValue& Value)
{
	FireInput = Value.Get<float>();
}

void UHandControllerComponent::Fire_Completed(const FInputActionValue& Value)
{
	FireInput = Value.Get<float>();
}

void UHandControllerComponent::Use_Started(const FInputActionValue& Value)
{
	UseInput = Value.Get<float>();
}

void UHandControllerComponent::Use_Triggered(const FInputActionValue& Value)
{
	UseInput = Value.Get<float>();
}

void UHandControllerComponent::Use_Completed(const FInputActionValue& Value)
{
	UseInput = Value.Get<float>();
}

void UHandControllerComponent::AltUse_Started(const FInputActionValue& Value)
{
	AltUseInput = Value.Get<float>();
}

void UHandControllerComponent::AltUse_Triggered(const FInputActionValue& Value)
{
	AltUseInput = Value.Get<float>();
}

void UHandControllerComponent::AltUse_Completed(const FInputActionValue& Value)
{
	AltUseInput = Value.Get<float>();
}

void UHandControllerComponent::Grab(bool Pressed)
{
	UWorld* World = GetWorld();

	if (World && HapticCollider && GrabConstraint)
	{
		if (Pressed)
		{
			// Grab input button has started being pressed

			// Check for nearby grip components. These take precedence on hands grabbing objects to ensure any specific behaviour such as snapping to a point is adhered
			TArray<AActor*> IgnoredActors = { GetOwner() };
			TArray<TEnumAsByte<EObjectTypeQuery>> GrabObjectTypes = { UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_PhysicsBody)};
			TArray<FHitResult> TraceHits;

			if (UKismetSystemLibrary::SphereTraceMultiForObjects(World, GrabConstraint->GetComponentLocation(), GrabConstraint->GetComponentLocation(), GrabRadius, GrabObjectTypes, false, TArray<AActor*>(), EDrawDebugTrace::Type::None, TraceHits, true))
			{
				UGripComponent* ClosestGrip = nullptr;
				float ClosestDistance = GrabRadius;

				for (int i = 0; i < TraceHits.Num(); i++)
				{
					FHitResult Hit = TraceHits[i];
					if (AActor* HitActor = Hit.GetActor())
					{
						TArray<UGripComponent*> HitActorGrips;
						HitActor->GetComponents(HitActorGrips);
						if (HitActorGrips.Num() > 0)
						{
							for (int j = 0; j < HitActorGrips.Num(); j++)
							{
								UGripComponent* HitGrip = HitActorGrips[j];
								if (!HitGrip || !HitGrip->CanGrab()) continue;

								DrawDebugCoordinateSystem(World, HitGrip->GetComponentLocation(), HitGrip->GetComponentRotation(), 10.0f, false, 3.0f);

								float GripDistance = FVector::Distance(GrabConstraint->GetComponentLocation(), HitGrip->GetComponentLocation());
								if (GripDistance < ClosestDistance)
								{
									ClosestGrip = HitGrip;
									ClosestDistance = GripDistance;
								}
							}
						}
					}
				}
				
				if (ClosestGrip)
				{
					
					if (ClosestGrip->SnapOnGrab())
					{
						FVector LocationDelta = ClosestGrip->GetComponentLocation() - HapticCollider->GetComponentLocation();
						//HapticCollider->AddWorldOffset(LocationDelta, true);
					}

					GrabbedGrip = ClosestGrip;
					GrabbedGrip->WakeRigidBody();
					GrabConstraint->SetConstrainedComponents(HapticCollider, FName(), GrabbedGrip, FName());
					if (APawn* OwnerPawn = Cast<APawn>(GetOwner()))
					{
						if (AController* Controller = OwnerPawn->GetController())
						{
							if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
							{
								UHapticFeedbackEffect_Base* HapticEffect = GrabbedGrip->GetGrabHapticEffect();

								PlayerController->PlayHapticEffect(HapticEffect, GetTrackingSource());
							}
						}
					}
				}
			}

		}
		else
		{
			// Grab input button has stopped being pressed

			if (GrabbedGrip)
			{
				GrabbedGrip = nullptr;
				GrabConstraint->BreakConstraint();
			}
		}
	}
	else
	{
		if (!World)
			UE_LOG(LogTemp, Warning, TEXT("No world found for grab/release"));
		if (!HapticCollider)
			UE_LOG(LogTemp, Warning, TEXT("No haptic collider found for grab/release"));
		if (!GrabConstraint)
			UE_LOG(LogTemp, Warning, TEXT("No grab constraint found for grab/release"));
	}
}

void UHandControllerComponent::SetHapticComponents(USphereComponent* Target, UBoxComponent* Collider, UPhysicsConstraintComponent* Constraint)
{
	HapticTarget = Target;
	HapticCollider = Collider;
	HapticConstraint = Constraint;
}

void UHandControllerComponent::SetGrabConstraint(UPhysicsConstraintComponent* Constraint)
{
	GrabConstraint = Constraint;
}

USphereComponent* UHandControllerComponent::GetHapticTarget() { return HapticTarget; }

UBoxComponent* UHandControllerComponent::GetHapticCollider() { return HapticCollider; }

UPhysicsConstraintComponent* UHandControllerComponent::GetHapticConstraint() { return HapticConstraint; }

UPhysicsConstraintComponent* UHandControllerComponent::GetGrabConstraint() { return GrabConstraint; }

void UHandControllerComponent::Debug()
{
	if (!bShowDebug) return;

	UWorld* World = GetWorld();

	if (bDebugTransform)
	{
		DrawDebugCoordinateSystem(World, GetComponentLocation(), GetComponentRotation(), 20.0f);
	}

	if (bDebugGrabbing)
	{
		if (GrabConstraint)
		{
			FColor GrabbedColor(FColor::Green), ReleasedColor(FColor::Emerald);
			FColor SphereColor(
				FMath::Lerp(ReleasedColor.R, GrabbedColor.R, GrabInput),
				FMath::Lerp(ReleasedColor.G, GrabbedColor.G, GrabInput),
				FMath::Lerp(ReleasedColor.B, GrabbedColor.B, GrabInput),
				FMath::Lerp(ReleasedColor.A, GrabbedColor.A, GrabInput)
			);
			DrawDebugSphere(World, GrabConstraint->GetComponentLocation(), GrabRadius, 16, SphereColor);
		}
		else if (HapticCollider)
		{
			DrawDebugSphere(World, HapticCollider->GetComponentLocation(), GrabRadius, 16, FColor::Magenta);
		}
		else
		{
			DrawDebugSphere(World, GetComponentLocation(), GrabRadius, 16, FColor::Red);
		}
		
	}
}