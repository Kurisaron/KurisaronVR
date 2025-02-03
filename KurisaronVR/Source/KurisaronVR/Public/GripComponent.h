// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/PrimitiveComponent.h"
#include "GripComponent.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType, Category = "VR", meta = (BlueprintSpawnableComponent))
class KURISARONVR_API UGripComponent : public UPrimitiveComponent
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Grip", meta = (AllowPrivateAccess = "true"))
	bool bSnapOnGrab;
	
public:

	UGripComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
};
