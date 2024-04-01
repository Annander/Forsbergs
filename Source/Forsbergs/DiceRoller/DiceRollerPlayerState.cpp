// Fill out your copyright notice in the Description page of Project Settings.

#include "DiceRollerPlayerState.h"
#include "Net/UnrealNetwork.h"

ADiceRollerPlayerState::ADiceRollerPlayerState()
{
	bReplicates = true;
}

void ADiceRollerPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ADiceRollerPlayerState, Color);
}