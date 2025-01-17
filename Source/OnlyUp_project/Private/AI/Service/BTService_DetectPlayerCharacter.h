// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BTService_DetectPlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class UBTService_DetectPlayerCharacter : public UBTService
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere)
	bool IsDetected;

protected:
	UPROPERTY(EditAnywhere, Category = Blackboard)
	FBlackboardKeySelector IsAttackRequestedKey;

public:
	UBTService_DetectPlayerCharacter();

protected:
	virtual void TickNode(UBehaviorTreeComponent& ownerComponent,
		uint8* nodeMemory, float dt) override;

private:
	void CheckArea(UBehaviorTreeComponent& ownerComponent);
	
};
