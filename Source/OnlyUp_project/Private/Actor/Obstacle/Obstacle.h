// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Obstacle.generated.h"

/**
 * 
 */
UCLASS()
class AObstacle : public AStaticMeshActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	class UObstacleMovementComponent* ObstacleMovementComponent;


public:
	AObstacle();

protected:
	virtual void BeginPlay() override;
	


};
