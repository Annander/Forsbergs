// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "StatuePlayer.generated.h"

UCLASS()
class FORSBERGS_API AStatuePlayer : public APawn
{
	GENERATED_BODY()

	float CurrentLookRotation;

protected:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	UCameraComponent* CameraComponent;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	UCapsuleComponent* CapsuleComponent;

public:
	AStatuePlayer();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MoveSpeed = 1000.f;

	UFUNCTION(BlueprintCallable)
	void Move(const FVector2D AxisInput);

	UFUNCTION(BlueprintCallable)
	void Look(const FVector2D AxisInput);

	UFUNCTION(BlueprintCallable)
	FTransform CameraTransform() const
	{
		return CameraComponent->GetComponentTransform();
	};
};