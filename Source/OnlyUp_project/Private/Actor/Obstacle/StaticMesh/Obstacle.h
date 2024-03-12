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



public:
	AObstacle();

protected:
	virtual void BeginPlay() override;
	


};
