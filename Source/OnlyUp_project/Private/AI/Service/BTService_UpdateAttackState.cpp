#include "AI/Service/BTService_UpdateAttackState.h"

UBTService_UpdateAttackState::UBTService_UpdateAttackState()
{
	IsAttackingKey.AddBoolFilter(this, GET_MEMBER_NAME_CHECKED(ThisClass, IsAttackingKey));
}

void UBTService_UpdateAttackState::TickNode(UBehaviorTreeComponent& ownerComponent, uint8* nodeMemory, float dt)
{
	Super::TickNode(ownerComponent, nodeMemory, dt);

}

void UBTService_UpdateAttackState::UpdateAttackState(UBehaviorTreeComponent& ownerComponent)
{
	UBlackboardComponent* blackboardComponent = ownerComponent.GetBlackboardComponent();
}
