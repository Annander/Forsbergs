// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Die.generated.h"

UCLASS()
class FORSBERGS_API ADie : public AActor
{
	GENERATED_BODY()
	
private:
	UFUNCTION(BlueprintCallable)
	virtual void OnHit(UPrimitiveComponent* HitComoponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult &Hit);

	UFUNCTION(BlueprintCallable)
	virtual void OnSleep(UPrimitiveComponent* SleepingComponent, FName BoneName);

	UFUNCTION(BlueprintCallable)
	virtual void OnTimerFinished();

	UFUNCTION()
	bool DotCompare(float Dot, const int32 Positive, const int32 Negative, int32 &Result);

	FVector GroundNormal;

	FTimerHandle TimerHandle;

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float DotThreshold = .9f;

	UPROPERTY(BlueprintReadOnly)
	int32 DieResult;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	ADie();
	virtual void Tick(float DeltaTime) override;
};