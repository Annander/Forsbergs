// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TileActorConnection.h"
#include "TileActor.generated.h"

UCLASS(BlueprintType,Blueprintable)
class FORSBERGS_API ATileActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATileActor();

	UPROPERTY(EditAnywhere)
	TArray<UTileActorConnection*> Connections;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	virtual void OnConstruction(const FTransform& Transform) override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/*
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<> RequiredDirections;
	*/
};