// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "DiceRollerPlayerState.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class FORSBERGS_API ADiceRollerPlayerState : public APlayerState
{
	GENERATED_BODY()
	
public:
	ADiceRollerPlayerState();

	UPROPERTY(Replicated, BlueprintReadOnly)
	FLinearColor Color;

	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const;
};