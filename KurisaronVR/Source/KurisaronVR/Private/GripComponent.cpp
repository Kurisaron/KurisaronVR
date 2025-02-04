// Fill out your copyright notice in the Description page of Project Settings.


#include "GripComponent.h"

UGripComponent::UGripComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	bSnapOnGrab = true;
}

bool UGripComponent::GetSnapOnGrab()
{
	return bSnapOnGrab;
}