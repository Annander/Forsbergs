// Fill out your copyright notice in the Description page of Project Settings.

#include "StatuePlayer.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AStatuePlayer::AStatuePlayer()
{
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleCollider"));
	CapsuleComponent->InitCapsuleSize(55.f, 96.f);
	CapsuleComponent->SetSimulatePhysics(true);

	SetRootComponent(CapsuleComponent);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(CapsuleComponent);
	CameraComponent->SetRelativeLocation(FVector(0,0,100.f));
}

void AStatuePlayer::Move(const FVector2D AxisInput)
{
	const auto MoveVector = FVector(AxisInput.Y, -AxisInput.X, 0.f);

	auto TransformedVector = UKismetMathLibrary::TransformDirection(
		GetActorTransform(),
		MoveVector
	);

	auto DeltaTime = GetWorld()->GetDeltaSeconds();

	TransformedVector *= MoveSpeed;

	SetActorLocation(
		GetActorLocation() + 
		TransformedVector * DeltaTime
	);
}

void AStatuePlayer::Look(const FVector2D AxisInput)
{
	// Rotate directly on the horizontal axis
	AddActorLocalRotation(
		FRotator(
			0.f, 
			AxisInput.X, 
			0.f)
	);

	// Clamp vertical axis
	CurrentLookRotation += AxisInput.Y;
	CurrentLookRotation = FMath::ClampAngle(
		CurrentLookRotation,
		-90.f,
		90.f
	);

	CameraComponent->SetWorldRotation(
		FRotator(
			CurrentLookRotation, 
			GetActorRotation().Yaw, 
			0.f)
	);
}