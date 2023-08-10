// Fill out your copyright notice in the Description page of Project Settings.
#include "Die.h"

// Sets default values
ADie::ADie()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	StaticMeshComponent->SetSimulatePhysics(true);
	StaticMeshComponent->SetGenerateOverlapEvents(true);

	SetRootComponent(StaticMeshComponent);

	StaticMeshComponent->OnComponentHit.AddDynamic(this, &ADie::OnHit);
	StaticMeshComponent->OnComponentSleep.AddDynamic(this, &ADie::OnSleep);
}

void ADie::Tick(float DeltaTime)
{
	GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Blue, FString::FromInt(DieResult));
}

void ADie::OnHit(UPrimitiveComponent* HitComoponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	//GEngine->AddOnScreenDebugMessage(-1, .5f, FColor::Blue, FString("Hit!"));
	GroundNormal = Hit.ImpactNormal;
}

void ADie::OnSleep(UPrimitiveComponent* SleepingComponent, FName BoneName)
{
	// Check which side is up and make that the public result
	//GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Blue, FString("Fell asleep..."));

	// Z+ = 1
	// Z- = 6
	auto UpDot = FVector::DotProduct(GroundNormal, GetActorUpVector());
	if (DotCompare(UpDot, 1, 6, DieResult))
		return;

	// Y+ = 4
	// Y- = 3
	auto RightDot = FVector::DotProduct(GroundNormal, GetActorRightVector());
	if (DotCompare(RightDot, 4, 3, DieResult))
		return;

	// X+ = 2
	// X- = 5
	auto ForwardDot = FVector::DotProduct(GroundNormal, GetActorForwardVector());
	if (DotCompare(ForwardDot, 2, 5, DieResult))
		return;
}

void ADie::OnTimerFinished()
{
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Blue, FString("Timer finished!"));
}

bool ADie::DotCompare(float Dot, const int32 Positive, const int32 Negative, int32& Result)
{
	if (Dot >= DotThreshold)
	{
		Result = Positive;
		return true;
	}
	else if (Dot <= -DotThreshold)
	{
		Result = Negative;
		return true;
	}

	return false;
}

// Called when the game starts or when spawned
void ADie::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ADie::OnTimerFinished, 3.f, false);
}