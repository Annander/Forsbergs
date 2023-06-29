// Fill out your copyright notice in the Description page of Project Settings.

#include "InteractorComponent.h"
#include "PickupInterface.h"

UInteractorComponent::UInteractorComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	TraceSphere = FCollisionShape::MakeSphere(Radius);
}

void UInteractorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	const AActor* Owner = GetOwner();

	TArray<FOverlapResult> CandidateActors;

	// Find nearby actors, by channel
	GetWorld()->OverlapMultiByChannel(CandidateActors,
		Owner->GetActorLocation(),
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel1,
		TraceSphere
	);

	// Loop through found actors
	for (int i = 0; i < CandidateActors.Num(); i++)
	{
		// Call the interface on each collected actor
		AActor* ActorReference = CandidateActors[i].GetActor();

		if (ActorReference->Implements<UPickupInterface>())
		{
			IPickupInterface::Execute_Pickup(ActorReference);
		}
	}
}