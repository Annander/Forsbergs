// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AimInteractor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FORSBERGS_API UAimInteractor : public UActorComponent
{
	GENERATED_BODY()

private:	
	UPROPERTY()
	AActor* CurrentTarget;

protected:
	virtual void BeginPlay() override;

	void TriggerInteractives();

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bUseTick;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float InteractionRange = 500.f;

	UAimInteractor();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void Shoot();

	const AActor* GetCurrentTarget()
	{
		return CurrentTarget;
	};

	bool HasTarget()
	{
		return CurrentTarget != nullptr;
	};
};