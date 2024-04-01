// Fill out your copyright notice in the Description page of Project Settings.
#include "DiceRollerGameState.h"

#include "DiceRollerPlayerState.h"
#include "Net/UnrealNetwork.h"

// Sets default values
ADiceRollerGameState::ADiceRollerGameState()
{
	bReplicates = true;
}

void ADiceRollerGameState::AddPlayerState(APlayerState* PlayerState)
{
	Super::AddPlayerState(PlayerState);

	if(HasAuthority())
	{
		auto DiceRollerPlayerState = Cast<ADiceRollerPlayerState>(PlayerState);
		DiceRollerPlayerState->Color = FLinearColor::MakeRandomColor();
	}
}

// Called when the game starts or when spawned
void ADiceRollerGameState::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ADiceRollerGameState::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}