#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_CannonAttack.generated.h"

UCLASS()
class UBTTask_CannonAttack : public UBTTaskNode
{
	GENERATED_BODY()

private:
	// ��ǥ ����(�÷��̾�)
	UPROPERTY(EditAnywhere, category = Blackboard)
	FBlackboardKeySelector TargetActor;

	UPROPERTY(EditAnywhere, category = Blackboard)
	FBlackboardKeySelector IsAttackRequested;



public:
	UBTTask_CannonAttack();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
};
