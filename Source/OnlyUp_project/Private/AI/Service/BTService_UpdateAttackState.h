// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BTService_UpdateAttackState.generated.h"

/**
 * 
 */
UCLASS()
class UBTService_UpdateAttackState : public UBTService
{
	GENERATED_BODY()
	

protected:
	UPROPERTY(EditAnywhere, Category = Blackboard)
	FBlackboardKeySelector IsAttackingKey;

	// 공격을 설정하기 위한 시간
	UPROPERTY()
	float AttackTimes;

	// 다시 회전하도록 설정하기 위해 필요한 시간
	UPROPERTY()
	float ResetTime;


public:
	UBTService_UpdateAttackState();

protected:
	virtual void TickNode(UBehaviorTreeComponent& ownerComponent,
		uint8* nodeMemory, float dt) override;

private:
	void UpdateAttackState(UBehaviorTreeComponent& ownerComponent, float dt);


};
