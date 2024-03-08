#include "AI/Task/BTTask_SettingBlockLocation.h"

#include "Actor/Obstacle/Dynamic/MovingBlock/MovingBlockObstacle.h"

#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_SettingBlockLocation::UBTTask_SettingBlockLocation()
{
	TargetLocation_1.AddVectorFilter(this, GET_MEMBER_NAME_CHECKED(ThisClass, TargetLocation_1));
	TargetLocation_2.AddVectorFilter(this, GET_MEMBER_NAME_CHECKED(ThisClass, TargetLocation_2));
}

EBTNodeResult::Type UBTTask_SettingBlockLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// Get BlackboardComponent
	UBlackboardComponent* blackboardComponent = OwnerComp.GetBlackboardComponent();

	// movingBlock 객체를 얻습니다.
	AMovingBlockObstacle* movingBlock = Cast<AMovingBlockObstacle>(OwnerComp.GetOwner());

	FVector blocklocation = movingBlock->GetActorLocation();

	blackboardComponent->SetValueAsVector(TargetLocation_1.SelectedKeyName, blocklocation + FVector(0.0f, 100.0f, 0.0f));
	blackboardComponent->SetValueAsVector(TargetLocation_2.SelectedKeyName, blocklocation + FVector(0.0f, -100.0f, 0.0f));



	return EBTNodeResult::Type::Succeeded;
}
