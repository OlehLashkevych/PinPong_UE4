// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
//#include "Vector.h"
#include "PlatformPawn.generated.h"


UCLASS()
class APlatformPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlatformPawn();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void MoveRight(float Value);

private:	
	FVector MovementDirection;
	UPROPERTY(EditAnywhere, Category="Movement")
	float MovementSpeed = 500.f;

	

};
