// Fill out your copyright notice in the Description page of Project Settings.

#include "AimInteractor.h"
#include "../Statue/PickupInterface.h"
#include "../Statue/StatuePlayer.h"
#include <DrawDebugHelpers.h>

UAimInteractor::UAimInteractor()
{
	PrimaryComponentTick.bCanEverTick = bUseTick;
	CurrentTarget = nullptr;
}

void UAimInteractor::BeginPlay()
{
	Super::BeginPlay();
}

void UAimInteractor::TriggerInteractives()
{
	const auto Owner = Cast<AStatuePlayer>(GetOwner());

	TArray<FHitResult> CandidateActors;

	const auto CameraTransform = Owner->CameraTransform();

	const FVector Start = CameraTransform.GetLocation();
	const FVector End = Start + (CameraTransform.GetRotation().GetForwardVector() * InteractionRange);

	// Use line trace from camera
	GetWorld()->LineTraceMultiByChannel(CandidateActors, Start, End, ECollisionChannel::ECC_GameTraceChannel1);
	//{
	for (int i = 0; i < CandidateActors.Num(); i++)
	{
		// Call the interface on each collected actor
		AActor* ActorReference = CandidateActors[i].GetActor();

		DrawDebugPoint(GetWorld(), CandidateActors[i].ImpactPoint, 25.f, FColor::Red, false, 2.f);

		if (ActorReference->Implements<UPickupInterface>())
		{
			IPickupInterface::Execute_Pickup(ActorReference);
		}
	}
	//}
}

void UAimInteractor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	TriggerInteractives();
}

void UAimInteractor::Shoot()
{
	if (!bUseTick)
	{
		TriggerInteractives();
	}		
}