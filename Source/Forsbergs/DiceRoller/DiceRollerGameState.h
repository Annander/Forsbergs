// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "DiceRollerGameState.generated.h"

UCLASS()
class FORSBERGS_API ADiceRollerGameState : public AGameState
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
public:
	ADiceRollerGameState();

	virtual void AddPlayerState(APlayerState* PlayerState);
	virtual void Tick(float DeltaTime) override;
};