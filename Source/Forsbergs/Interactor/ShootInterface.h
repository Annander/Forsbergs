// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ShootInterface.generated.h"

UINTERFACE(MinimalAPI, BlueprintType)
class UShootInterface : public UInterface
{
	GENERATED_BODY()
};

class FORSBERGS_API IShootInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Shoot();
};