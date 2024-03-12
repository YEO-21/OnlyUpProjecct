// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ObstacleMovementComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UObstacleMovementComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY()
	class AMovingBlockObstacle* MovingBlock;

	UPROPERTY()
	bool IsIncreased;


	FVector RightLocation;
	FVector LeftLocation;
	FVector MiddleLocation;

	


public:	
	// Sets default values for this component's properties
	UObstacleMovementComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	void MoveBlock(FVector blocklocation);
		
};
