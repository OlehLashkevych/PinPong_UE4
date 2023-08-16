// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformPawn.h"

// Sets default values
APlatformPawn::APlatformPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//SetActorTransform(FTransform(FVector(2.f, 5.f, 2.f)), true);
}

// Called when the game starts or when spawned
void APlatformPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlatformPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!MovementDirection.IsZero())
	{
		FVector NewLocation = GetActorLocation() + (MovementDirection * DeltaTime * MovementSpeed);
		SetActorLocation(NewLocation, true);
	}
}

// Called to bind functionality to input
void APlatformPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis(TEXT("MoveRight"), this, &APlatformPawn::MoveRight);
}

// Moves Pawn to the left and to whe right from keybord input
void APlatformPawn::MoveRight(float Value)
{
	
	MovementDirection.Y = FMath::Clamp(Value, -1.f, 1.f);
	
}

