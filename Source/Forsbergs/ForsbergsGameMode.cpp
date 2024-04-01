// Copyright Epic Games, Inc. All Rights Reserved.

#include "ForsbergsGameMode.h"

void AForsbergsGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
	
	StatueManager = GetWorld()->SpawnActor<AStatueManager>();
	StatueManager->Initialize(StatueClass);
}

void AForsbergsGameMode::SpawnStatue(const FVector Location)
{
	StatueManager->SpawnStatue(Location);
}