// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StatueActor.h"
#include "GameFramework/Info.h"
#include "StatueManager.generated.h"

/**
 * 
 */
UCLASS()
class FORSBERGS_API AStatueManager : public AInfo
{
	GENERATED_BODY()
	
private:
	UPROPERTY()
	TArray<AStatueActor*> Instances;

	UPROPERTY()
	UClass* LoadedObject;

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSoftClassPtr<AStatueActor> StatueClass;

	UFUNCTION()
	void SpawnStatue(FVector Location);

	UFUNCTION()
	void Initialize();
};