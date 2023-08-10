// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tile.h"
#include "TileActor.h"

#include "QuiltingExample.generated.h"

UCLASS()
class FORSBERGS_API AQuiltingExample : public AActor
{
	GENERATED_BODY()
	
public:	
	AQuiltingExample();

private:
	TArray<ATileActor*> CandidateInstances;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	int32 SpawnCount = 10;

	UFUNCTION()
	void GenerateQuilt();

public:	
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<ATileActor*> CandidateTiles;
};
