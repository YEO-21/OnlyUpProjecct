// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/Obstacle/StaticMesh/Dynamic/DynamicObstacle.h"
#include "MovingBlockObstacle.generated.h"

/**
 * 
 */
UCLASS()
class AMovingBlockObstacle : public ADynamicObstacle
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere)
	class AStaticMeshActor* MovingBlock;

 


public:
	AMovingBlockObstacle();


	
};
