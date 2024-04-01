// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "ScoreSubsystem.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FScoreTickSignature, int32, Score);

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class FORSBERGS_API UScoreSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
	
	int32 CurrentScore;

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UPROPERTY(BlueprintAssignable)
	FScoreTickSignature OnScoreTick;

	UFUNCTION(BlueprintCallable)
	void AddScore();

	UFUNCTION(BlueprintCallable)
	int32 GetScore() const
	{
		return CurrentScore;
	};
};