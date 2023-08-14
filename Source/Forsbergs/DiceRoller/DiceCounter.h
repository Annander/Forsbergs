// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "DiceCounter.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class FORSBERGS_API ADiceCounter : public ATriggerBox
{
	GENERATED_BODY()

public:
	ADiceCounter();
	
private:
	UFUNCTION(BlueprintCallable)
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintCallable)
	void OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
	void AddDieResult(int32 DieResult);

protected:
	UPROPERTY(BlueprintReadOnly)
	int32 TotalDiceValue;
};
