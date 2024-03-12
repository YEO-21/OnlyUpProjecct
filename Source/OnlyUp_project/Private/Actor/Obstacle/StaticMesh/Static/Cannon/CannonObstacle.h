// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/Obstacle/StaticMesh/Static/StaticObstacle.h"
#include "CannonObstacle.generated.h"

/**
 * 
 */
UCLASS()
class ACannonObstacle : public AStaticObstacle
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	class UObstacleAttackComponent* ObstacleAttackComponent;



public:
	ACannonObstacle();
	
};
