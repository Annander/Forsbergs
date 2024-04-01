// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RandomMoveComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FORSBERGS_API URandomMoveComponent : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY()
	float Timer;

	UFUNCTION()
	void RandomMove();

	UFUNCTION()
	void RandomInterval();

	UPROPERTY()
	float Interval = 1.f;

public:
	URandomMoveComponent();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Radius = 1000.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector2D MaxMinInterval = FVector2D(1.f, 4.f);

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
