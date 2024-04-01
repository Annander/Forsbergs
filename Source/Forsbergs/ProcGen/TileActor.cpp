// Fill out your copyright notice in the Description page of Project Settings.
#include "TileActor.h"

// Sets default values
ATileActor::ATileActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ATileActor::OnConstruction(const FTransform& Transform)
{
	/*
	auto ConnectionComponents = GetComponentsByClass(UTileActorConnection::StaticClass());
	
	for (int i = 0; i < ConnectionComponents.Num(); i++)
	{
		auto ConnectionCast = Cast<UTileActorConnection>(ConnectionComponents[i]);
		Connections.Add(ConnectionCast);
	}
	*/
}

// Called when the game starts or when spawned
void ATileActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATileActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}