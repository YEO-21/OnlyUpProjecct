// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ObstacleController.generated.h"

/**
 * 
 */
UCLASS()
class AObstacleController : public AAIController
{
	GENERATED_BODY()

	



protected:
	// 블랙보드를 나타낼 변수입니다.
	UPROPERTY(EditAnywhere, BluePrintReadOnly)
	class UBlackboardComponent* BlackboardComponent;

	


protected:
	virtual void OnPossess(APawn* InPawn) override;

public:
	virtual void InitializeEnemyController(struct FObstacleData* obstacleData);


	
};
