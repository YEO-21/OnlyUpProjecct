#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_CannonAttack.generated.h"

UCLASS()
class UBTTask_CannonAttack : public UBTTaskNode
{
	GENERATED_BODY()

private:
	// 목표 액터(플레이어)
	UPROPERTY(EditAnywhere, category = Blackboard)
	FBlackboardKeySelector TargetActor;

	UPROPERTY(EditAnywhere, category = Blackboard)
	FBlackboardKeySelector IsAttackRequested;



public:
	UBTTask_CannonAttack();

	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
};
