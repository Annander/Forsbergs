// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PickupInterface.generated.h"

UINTERFACE(MinimalAPI, BlueprintType)
class UPickupInterface : public UInterface
{
	GENERATED_BODY()
};

class FORSBERGS_API IPickupInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Pickup();
};