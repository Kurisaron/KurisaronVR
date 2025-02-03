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

void UHandControllerComponent::Grab_Started(const FInputActionValue& Value)
{
	float GrabInput = Value.Get<float>();

	if (UPhysicsConstraintComponent* GrabConstraint = GetGrabConstraint())
	{
		
	}
}

void UHandControllerComponent::Grab_Triggered(const FInputActionValue& Value)
{
	float GrabInput = Value.Get<float>();
}

void UHandControllerComponent::Grab_Completed(const FInputActionValue& Value)
{
	float GrabInput = Value.Get<float>();

	if (UPhysicsConstraintComponent* GrabConstraint = GetGrabConstraint())
	{

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