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

	GrabRadius = 15.0f;

	bShowDebug = true;
	bDebugTransform = true;
	bDebugGrabbing = true;
}

void UHandControllerComponent::BeginPlay()
{
	if (HapticTarget && HapticCollider && HapticConstraint)
	{
		HapticConstraint->SetConstrainedComponents(HapticTarget, HapticBone, HapticCollider, HapticBone);
	}
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

			TArray<AActor*> IgnoredActors = { GetOwner() };
			TArray<TEnumAsByte<EObjectTypeQuery>> GrabObjectTypes = { UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_PhysicsBody)};
			TArray<FHitResult> TraceHits;
			
			const FVector GrabLocation = GrabConstraint->GetComponentLocation();
			EDrawDebugTrace::Type GrabDebugType = bDebugGrabbing ? EDrawDebugTrace::Type::ForDuration : EDrawDebugTrace::Type::None;

			if (UKismetSystemLibrary::SphereTraceMultiForObjects(World, GrabLocation, GrabLocation, GrabRadius, GrabObjectTypes, false, IgnoredActors, GrabDebugType, TraceHits, true))
			{
				// Filter out any hits on primitives that are not simulating physics
				TArray<FHitResult> ValidHits = TraceHits.FilterByPredicate([](const FHitResult& Hit) {
					if (UPrimitiveComponent* HitPrimitive = Hit.GetComponent())
					{
						return HitPrimitive->IsSimulatingPhysics() || HitPrimitive->BodyInstance.bSimulatePhysics;
					}
					else
						return false;
				});

				if (ValidHits.Num() > 0)
				{
					// Sort all valid hits by the primitive's distance from the hand
					ValidHits.Sort([GrabLocation](const FHitResult& A, const FHitResult& B) {
						UPrimitiveComponent* HitPrimitiveA = A.GetComponent();
						UPrimitiveComponent* HitPrimitiveB = B.GetComponent();

						return FVector::DistSquared(GrabLocation, HitPrimitiveA->GetComponentLocation()) < FVector::DistSquared(GrabLocation, HitPrimitiveB->GetComponentLocation());
					});

					// Start grabbing the closest primitive
					GrabbedPrimitive = ValidHits[0].GetComponent();
					// Check if the primitive being grabbed has child components
					TArray<USceneComponent*> PrimitiveChildren;
					GrabbedPrimitive->GetChildrenComponents(true, PrimitiveChildren);
					if (PrimitiveChildren.Num() > 0)
					{
						// Grabbed primitive has child components, filter for only child grip components that can be grabbed
						TArray<USceneComponent*> GripChildren = PrimitiveChildren.FilterByPredicate([](USceneComponent* Child) {
							if (UGripComponent* ChildGrip = Cast<UGripComponent>(Child))
							{
								return ChildGrip->CanGrab();
							}
							else return false;
						});

						if (GripChildren.Num() > 0)
						{
							// Grabbed primitive has grabbable grips, sort for the closest grip
							GripChildren.Sort([GrabLocation](const USceneComponent& A, const USceneComponent& B) {
								return FVector::DistSquared(GrabLocation, A.GetComponentLocation()) < FVector::DistSquared(GrabLocation, B.GetComponentLocation());
							});
							
							// Move hand to grab based on grip's location + rotation
							UGripComponent* TargetGrip = Cast<UGripComponent>(GripChildren[0]);
							HapticCollider->SetWorldRotation(TargetGrip->GetComponentRotation(), false, nullptr, ETeleportType::TeleportPhysics);
							FVector GrabDelta = TargetGrip->GetComponentLocation() - GrabConstraint->GetComponentLocation();
							HapticCollider->AddWorldOffset(GrabDelta, false, nullptr, ETeleportType::TeleportPhysics);
						}
					}
					GrabConstraint->SetConstrainedComponents(HapticCollider, HapticBone, GrabbedPrimitive, FName());
				}
				else
					UE_LOG(LogTemp, Warning, TEXT("No valid hits when attempting to grab"));
			}
		}
		else
		{
			// Grab input button has stopped being pressed
			if (GrabbedPrimitive)
			{
				GrabConstraint->BreakConstraint();
				GrabbedPrimitive = nullptr;
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

void UHandControllerComponent::SetHapticComponents(USkeletalMeshComponent* Target, USkeletalMeshComponent* Collider, UPhysicsConstraintComponent* Constraint)
{
	HapticTarget = Target;
	HapticCollider = Collider;
	HapticConstraint = Constraint;
}

void UHandControllerComponent::SetHapticBone(FName Bone)
{
	HapticBone = Bone;
}

void UHandControllerComponent::SetGrabConstraint(UPhysicsConstraintComponent* Constraint)
{
	GrabConstraint = Constraint;
}

USkeletalMeshComponent* UHandControllerComponent::GetHapticTarget() { return HapticTarget; }

USkeletalMeshComponent* UHandControllerComponent::GetHapticCollider() { return HapticCollider; }

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