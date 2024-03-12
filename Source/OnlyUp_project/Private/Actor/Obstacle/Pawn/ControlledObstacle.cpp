// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/Obstacle/Pawn/ControlledObstacle.h"

// Sets default values
AControlledObstacle::AControlledObstacle()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AControlledObstacle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AControlledObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AControlledObstacle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

