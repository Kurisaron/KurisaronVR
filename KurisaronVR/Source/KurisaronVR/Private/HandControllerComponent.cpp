// Fill out your copyright notice in the Description page of Project Settings.


#include "HandControllerComponent.h"
#include "GripComponent.h"

UHandControllerComponent::UHandControllerComponent(const FObjectInitializer& ObjectInitializer): Super(ObjectInitializer)
{
	PrimaryComponentTick.bCanEverTick = true;

	GrabRadius = 10.0f;
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
		//EnhancedInput->BindAction(GrabAction, ETriggerEvent::Triggered, this, &UHandControllerComponent::Grab_Triggered);
	}
}

void UHandControllerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	Debug();
}

void UHandControllerComponent::Grab_Started(const FInputActionValue& Value)
{
	float GrabInput = Value.Get<float>();

	Grab(true);
}

void UHandControllerComponent::Grab_Triggered(const FInputActionValue& Value)
{
	float GrabInput = Value.Get<float>();
}

void UHandControllerComponent::Grab_Completed(const FInputActionValue& Value)
{
	float GrabInput = Value.Get<float>();

	Grab(false);
}

void UHandControllerComponent::Grab(bool Pressed)
{
	UWorld* World = GetWorld();
	UBoxComponent* Collider = GetHapticCollider();
	UPhysicsConstraintComponent* GrabConstraint = GetGrabConstraint();

	if (World && Collider && GrabConstraint)
	{
		if (Pressed)
		{
			TArray<AActor*> IgnoredActors = { GetOwner() };
			TArray<UPrimitiveComponent*> FoundComponents;
			if (UKismetSystemLibrary::SphereOverlapComponents(World, GetComponentLocation(), GrabRadius, GrabObjectTypes, UGripComponent::StaticClass(), IgnoredActors, FoundComponents))
			{
				UGripComponent* ClosestGrip = nullptr;
				float ClosestDistance = GrabRadius;
				
				for (int i = 0; i < FoundComponents.Num(); i++)
				{
					if (UGripComponent* FoundGrip = Cast<UGripComponent>(FoundComponents[i]))
					{
						float GripDistance = FVector::Distance(GrabConstraint->GetComponentLocation(), FoundGrip->GetComponentLocation());
						if (GripDistance < ClosestDistance)
						{
							ClosestGrip = FoundGrip;
							ClosestDistance = GripDistance;
						}
					}
				}

				if (ClosestGrip)
				{
					if (ClosestGrip->GetSnapOnGrab())
					{
						FVector LocationDelta = ClosestGrip->GetComponentLocation() - Collider->GetComponentLocation();
						Collider->AddWorldOffset(LocationDelta, true);
					}

					GrabConstraint->SetConstrainedComponents(Collider, FName(), ClosestGrip, FName());
				}
			}
		}
		else
		{
			GrabConstraint->SetConstrainedComponents(Collider, FName(), nullptr, FName());
		}
	}
	else
	{
		if (!World)
			UE_LOG(LogTemp, Warning, TEXT("No world found for grab/release"));
		if (!Collider)
			UE_LOG(LogTemp, Warning, TEXT("No haptic collider found for grab/release"));
		if (!GrabConstraint)
			UE_LOG(LogTemp, Warning, TEXT("No grab constraint found for grab/release"));
	}
}

USphereComponent* UHandControllerComponent::GetHapticTarget()
{
	TArray<USceneComponent*> Children;
	GetChildrenComponents(true, Children);

	if (Children.Num() <= 0) return nullptr;
	for (USceneComponent* Child : Children)
	{
		if (Child->GetName().Contains(TEXT("HapticTarget")))
			return Cast<USphereComponent>(Child);
	}

	return nullptr;
}

UBoxComponent* UHandControllerComponent::GetHapticCollider()
{
	TArray<USceneComponent*> Children;
	GetChildrenComponents(true, Children);

	if (Children.Num() <= 0) return nullptr;
	for (USceneComponent* Child : Children)
	{
		if (Child->GetName().Contains(TEXT("HapticCollider")))
			return Cast<UBoxComponent>(Child);
	}

	return nullptr;
}

UPhysicsConstraintComponent* UHandControllerComponent::GetHapticConstraint()
{
	TArray<USceneComponent*> Children;
	GetChildrenComponents(true, Children);

	if (Children.Num() <= 0) return nullptr;
	for (USceneComponent* Child : Children)
	{
		if (Child->GetName().Contains(TEXT("HapticConstraint")))
			return Cast<UPhysicsConstraintComponent>(Child);
	}

	return nullptr;
}

UPhysicsConstraintComponent* UHandControllerComponent::GetGrabConstraint()
{
	TArray<USceneComponent*> Children;
	GetChildrenComponents(true, Children);

	if (Children.Num() <= 0) return nullptr;
	for (USceneComponent* Child : Children)
	{
		if (Child->GetName().Contains(TEXT("GrabConstraint")))
			return Cast<UPhysicsConstraintComponent>(Child);
	}

	return nullptr;
}

void UHandControllerComponent::Debug()
{
	if (!bShowDebug) return;

	UWorld* World = GetWorld();

	if (bShowTransform)
	{
		DrawDebugCoordinateSystem(World, GetComponentLocation(), GetComponentRotation(), 20.0f);
	}
}