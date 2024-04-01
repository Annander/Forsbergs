// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PickupInterface.h"
#include "ScoreSubsystem.h"
#include "RandomMoveComponent.h"
#include "GameFramework/Actor.h"
#include "StatueActor.generated.h"

UCLASS()
class FORSBERGS_API AStatueActor : public AActor,
	public IPickupInterface
{
	GENERATED_BODY()

	UScoreSubsystem* ScoreSubsystem;

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	URandomMoveComponent* RandomMoveComponent;

	virtual void BeginPlay() override;
	
public:	
	AStatueActor();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Pickup(); virtual void Pickup_Implementation() override;
};