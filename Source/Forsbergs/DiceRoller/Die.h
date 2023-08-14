// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Die.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDieResultSignature, int32, DieResult);

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

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const;

	FVector GroundNormal;

	FVector StartingVelocity;

	FTimerHandle TimerHandle;

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated)
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float DotThreshold = .9f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float StopTime = .5f;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	ADie();
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void ComeToStop(float Time);

	UPROPERTY(BlueprintReadOnly)
	int32 DieResult;

	UPROPERTY(BlueprintAssignable)
	FDieResultSignature OnDieResult;
};