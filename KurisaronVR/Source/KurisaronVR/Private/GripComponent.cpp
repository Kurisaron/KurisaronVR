// Fill out your copyright notice in the Description page of Project Settings.


#include "GripComponent.h"

UGripComponent::UGripComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	bCanGrab = true;
	bCanTelegrab = true;
}

bool UGripComponent::CanGrab()
{
	return bCanGrab;
}

bool UGripComponent::CanTelegrab()
{
	return bCanTelegrab;
}

UHapticFeedbackEffect_Base* UGripComponent::GetGrabHapticEffect()
{
	return GrabHapticEffect;
}