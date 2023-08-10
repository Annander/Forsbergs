// Fill out your copyright notice in the Description page of Project Settings.


#include "QuiltingExample.h"

// Sets default values
AQuiltingExample::AQuiltingExample()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AQuiltingExample::BeginPlay()
{
	Super::BeginPlay();
	GenerateQuilt();
}

void AQuiltingExample::GenerateQuilt()
{
	/*

	// For each tile
	// Spawn a random TileCandidate
	for (int i = 0; i < Tiles.Num(); i++)
	{

	}

	*/

	// Create Tile Instance
	// auto NewInstance = GetWorld()->SpawnActor<AStatueActor>(LoadedObject);
	// NewInstance->SetActorLocation(Location);

	int32 Index = FMath::RandRange(0, CandidateTiles.Num() -1);
	auto TileCandidate = CandidateTiles[Index];
	auto Instance = GetWorld()->SpawnActor<ATileActor>(ATileActor::StaticClass());

	CandidateInstances.Add(Instance);
}

void AQuiltingExample::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
}

// Called every frame
void AQuiltingExample::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}