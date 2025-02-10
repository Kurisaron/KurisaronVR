// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/PrimitiveComponent.h"
#include "Haptics/HapticFeedbackEffect_Base.h"
#include "GripComponent.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType, Category = "VR", meta = (BlueprintSpawnableComponent))
class KURISARONVR_API UGripComponent : public UPrimitiveComponent
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Grip", meta = (AllowPrivateAccess = "true"))
	bool bCanGrab;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Grip", meta = (AllowPrivateAccess = "true", EditCondition = "bCanGrab", EditConditionHides))
	bool bSnapOnGrab;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Grip", meta = (AllowPrivateAccess = "true", EditCondition = "bCanGrab", EditConditionHides))
	UHapticFeedbackEffect_Base* GrabHapticEffect;
	
public:

	UGripComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	bool CanGrab();
	bool SnapOnGrab();
	UHapticFeedbackEffect_Base* GetGrabHapticEffect();

};
