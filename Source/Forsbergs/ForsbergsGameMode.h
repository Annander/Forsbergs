// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "Statue/StatueManager.h"
#include "Statue/StatueActor.h"
#include "ForsbergsGameMode.generated.h"

/**
 * 
 */
UCLASS()
class FORSBERGS_API AForsbergsGameMode : public AGameMode
{
	GENERATED_BODY()

private:
	UPROPERTY()
	AStatueManager* StatueManager;

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSoftClassPtr<AStatueActor> StatueClass;

	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;

	UFUNCTION()
	void SpawnStatue(const FVector Location);
};