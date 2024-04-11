#include "AI/Task/BTTask_CannonAttack.h"

#include "Actor/Obstacle/Pawn/Static/Cannon/ControlledCannon.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_CannonAttack::UBTTask_CannonAttack()
{
	TargetActor.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(ThisClass, TargetActor), UObject::StaticClass());

	IsAttackRequested.AddBoolFilter(this, GET_MEMBER_NAME_CHECKED(ThisClass, IsAttackRequested));

	bNotifyTick = true;
}

void UBTTask_CannonAttack::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{

}

EBTNodeResult::Type UBTTask_CannonAttack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// Get BlackboardComponent
	UBlackboardComponent* blackboardComponent = OwnerComp.GetBlackboardComponent();

	// 공격 요청이 없다면 실패 결과 반환
	bool Attackrequested = blackboardComponent->GetValueAsBool(IsAttackRequested.SelectedKeyName);
	if(!Attackrequested) return EBTNodeResult::Failed;

	// Get Target(Player)
	UObject* targetObject = blackboardComponent->GetValueAsObject(TargetActor.SelectedKeyName);
	if (!IsValid(targetObject)) return EBTNodeResult::Failed;

	AActor* target = Cast<AActor>(targetObject);

	AController* ownerController = Cast<AController>(OwnerComp.GetOwner());
	if (!IsValid(ownerController))  return EBTNodeResult::Failed;

	// 컨트롤러가 조종하는 폰(Cannon)
	AControlledCannon* controlledPawn = Cast<AControlledCannon>(ownerController->GetPawn());

	FVector direction = (target->GetActorLocation() - controlledPawn->GetActorLocation());
	//direction.Z = 0.0f;
	direction = direction.GetSafeNormal();
	direction *= 500.0f;

	

	UStaticMeshComponent* cannonbomb = controlledPawn->GetCannonBomb();

	cannonbomb->SetSimulatePhysics(true);
	cannonbomb->AddImpulse(direction, NAME_None, true);
	//UE_LOG(LogTemp, Warning, TEXT("Cannon Attack!"));
	
	// 대포가 공격한 시간을 기록합니다.
	controlledPawn->CannonAttackTime = GetWorld()->GetTimeSeconds();

	//blackboardComponent->SetValueAsBool(TEXT("IsAttacking"), false);


	return EBTNodeResult::Type::Succeeded;
}
