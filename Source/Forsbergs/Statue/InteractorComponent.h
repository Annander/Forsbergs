// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractorComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FORSBERGS_API UInteractorComponent : public UActorComponent
{
	GENERATED_BODY()

	FCollisionShape TraceSphere;

public:	
	UInteractorComponent();

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float Radius = 500.f;

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};