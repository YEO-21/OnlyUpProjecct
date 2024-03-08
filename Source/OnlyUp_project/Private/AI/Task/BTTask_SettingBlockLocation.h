// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_SettingBlockLocation.generated.h"

/**
 * 
 */
UCLASS()
class UBTTask_SettingBlockLocation : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, Category = Blackboard)
	FBlackboardKeySelector TargetLocation_1;

	UPROPERTY(EditAnywhere, Category = Blackboard)
	FBlackboardKeySelector TargetLocation_2;

public:
	UBTTask_SettingBlockLocation();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;


};
