// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/Obstacle/StaticMesh/Obstacle.h"
#include "DynamicObstacle.generated.h"

/**
 * 
 */
UCLASS()
class ADynamicObstacle : public AObstacle
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	class UObstacleMovementComponent* ObstacleMovementComponent;

	
public:
	ADynamicObstacle();

};
