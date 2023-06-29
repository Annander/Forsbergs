// Fill out your copyright notice in the Description page of Project Settings.

#include "StatueActor.h"

// Sets default values
AStatueActor::AStatueActor()
{
	PrimaryActorTick.bCanEverTick = true;
	RandomMoveComponent = CreateDefaultSubobject<URandomMoveComponent>(TEXT("Random Move Component"));
}

void AStatueActor::BeginPlay()
{
	Super::BeginPlay();
	ScoreSubsystem = GetWorld()->GetSubsystem<UScoreSubsystem>();
}

void AStatueActor::Pickup_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, FString("Wohoo, used the interface!"));
	ScoreSubsystem->AddScore();
	Destroy();
}