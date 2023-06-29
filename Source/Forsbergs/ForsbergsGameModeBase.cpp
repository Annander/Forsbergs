// Copyright Epic Games, Inc. All Rights Reserved.

#include "ForsbergsGameModeBase.h"

void AForsbergsGameModeBase::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
	StatueManager = GetWorld()->SpawnActor<AStatueManager>();
	StatueManager->StatueClass = StatueClass;
	StatueManager->Initialize();
}

void AForsbergsGameModeBase::SpawnStatue(const FVector Location)
{
	StatueManager->SpawnStatue(Location);
}