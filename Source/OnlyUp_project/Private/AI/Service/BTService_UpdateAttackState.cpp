#include "AI/Service/BTService_UpdateAttackState.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTService_UpdateAttackState::UBTService_UpdateAttackState()
{
	IsAttackingKey.AddBoolFilter(this, GET_MEMBER_NAME_CHECKED(ThisClass, IsAttackingKey));

	AttackTimes = 5.0f;
}

void UBTService_UpdateAttackState::TickNode(UBehaviorTreeComponent& ownerComponent, uint8* nodeMemory, float dt)
{
	Super::TickNode(ownerComponent, nodeMemory, dt);

	UpdateAttackState(ownerComponent, dt);

}

void UBTService_UpdateAttackState::UpdateAttackState(UBehaviorTreeComponent& ownerComponent, float dt)
{
	UBlackboardComponent* blackboardComponent = ownerComponent.GetBlackboardComponent();

	float currentTime = GetWorld()->GetTimeSeconds();

	// 5�� ���� ������ ������ �� �� �ֵ��� ������ Ű ���� �����մϴ�.
	if (currentTime > AttackTimes)
	{
		UE_LOG(LogTemp, Warning, TEXT("IsAttacking is true"));
		blackboardComponent->SetValueAsBool(TEXT("IsAttacking"), true);
		AttackTimes += 5.0f;
		
		ResetTime = GetWorld()->GetTimeSeconds();

	}
	// ���� �� ���� �ð��� ������ �ٽ� �÷��̾ �����ϵ��� ������ Ű���� �����մϴ�.
	if (currentTime > ResetTime + 0.5f)
	{
		blackboardComponent->SetValueAsBool(TEXT("IsAttacking"), false);
	}

}


