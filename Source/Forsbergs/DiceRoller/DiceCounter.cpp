// Fill out your copyright notice in the Description page of Project Settings.
#include "DiceCounter.h"
#include "Die.h"
#include "Components/ShapeComponent.h"

ADiceCounter::ADiceCounter()
{
	PrimaryActorTick.bCanEverTick = true;
	
	auto Collision = GetCollisionComponent();
	Collision->OnComponentBeginOverlap.AddDynamic(this, &ADiceCounter::OnBeginOverlap);
	Collision->OnComponentEndOverlap.AddDynamic(this, &ADiceCounter::OnEndOverlap);
}

void ADiceCounter::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this))
	{
		auto DiceCast = Cast<ADie>(OtherActor);

		if (DiceCast)
		{
			DiceCast->OnDieResult.AddDynamic(this, &ADiceCounter::AddDieResult);
			DiceCast->ComeToStop(1.5f);
			GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Blue, FString::FromInt(TotalDiceValue));
		}
	}
}

void ADiceCounter::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	auto DiceCast = Cast<ADie>(OtherActor);

	if (DiceCast)
	{
		TotalDiceValue -= DiceCast->DieResult;
		DiceCast->OnDieResult.RemoveDynamic(this, &ADiceCounter::AddDieResult);
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Blue, FString::FromInt(TotalDiceValue));
	}
}

void ADiceCounter::AddDieResult(int32 DieResult)
{
	TotalDiceValue += DieResult;
}