// Fill out your copyright notice in the Description page of Project Settings.


#include "HandControllerComponent.h"

UHandControllerComponent::UHandControllerComponent(const FObjectInitializer& ObjectInitializer): Super(ObjectInitializer)
{
	PrimaryComponentTick.bCanEverTick = true;
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

USphereComponent* UHandControllerComponent::GetHapticTarget()
{
	return HapticTarget;
}

UBoxComponent* UHandControllerComponent::GetHapticCollider()
{
	return HapticCollider;
}

UPhysicsConstraintComponent* UHandControllerComponent::GetHapticConstraint()
{
	return HapticConstraint;
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