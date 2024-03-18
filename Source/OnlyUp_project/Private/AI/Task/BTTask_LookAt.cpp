#include "BTTask_LookAt.h"

#include "Actor/Obstacle/Pawn/Static/Cannon/ControlledCannon.h"

#include "Components/CannonMovementComponent/CannonMovementComponent.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_LookAt::UBTTask_LookAt()
{
	TargetActor.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(ThisClass, TargetActor), UObject::StaticClass());
}

EBTNodeResult::Type UBTTask_LookAt::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// Get BlackboardComponent
	UBlackboardComponent* blackboardComponent = OwnerComp.GetBlackboardComponent();

	// Get Target(Player)
	UObject* targetObject = blackboardComponent->GetValueAsObject(TargetActor.SelectedKeyName);
	if (!IsValid(targetObject)) return EBTNodeResult::Failed;

	AActor* targetActor = Cast<AActor>(targetObject);

	AController* ownerController = Cast<AController>(OwnerComp.GetOwner());
	if(!IsValid(ownerController))  return EBTNodeResult::Failed;

	// ��Ʈ�ѷ��� �����ϴ� ��(Cannon)
	AControlledCannon* controlledPawn = Cast<AControlledCannon>(ownerController->GetPawn());

	// �÷��̾ �ٶ󺸴� ������ ����ϴ�.
	FVector direction = targetActor->GetActorLocation() - controlledPawn->GetActorLocation();
	direction.Z = 0.0f;
	direction = direction.GetSafeNormal();

	float yawAngle = FMath::RadiansToDegrees(FMath::Atan2(direction.Y, direction.X));

	controlledPawn->GetCannonMovementComponent()->SetTargetYawAngle(yawAngle-90.0f);



	return EBTNodeResult::Type::Succeeded;
}
