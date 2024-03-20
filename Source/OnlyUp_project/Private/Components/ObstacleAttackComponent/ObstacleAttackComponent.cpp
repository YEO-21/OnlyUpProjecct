#include "Components/ObstacleAttackComponent/ObstacleAttackComponent.h"

#include "Actor/Obstacle/Pawn/Static/Cannon/ControlledCannon.h"

#include "BehaviorTree/BlackboardComponent.h"

UObstacleAttackComponent::UObstacleAttackComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	IsAttacking = false;

	



}


void UObstacleAttackComponent::BeginPlay()
{
	Super::BeginPlay();

	ControlledCannon = Cast<AControlledCannon>(GetOwner());
}


void UObstacleAttackComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (IsAttackRequested)
	{
		AttackStart();
	}

}

void UObstacleAttackComponent::AttackStart()
{
	// ��ȿ�� �˻�
	if (!IsValid(ControlledCannon)) return;

	// ���� �ð��� ����մϴ�.
	float currentTime = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("currentTime = [%.2f]"), currentTime);

	// ������ �ð��� ����մϴ�.
	float attackTime = ControlledCannon->CannonAttackTime;
	UE_LOG(LogTemp, Warning, TEXT("attackTime = [%.2f]"), attackTime);

	if (currentTime > attackTime + 20.0f)
	{
		// �������� ��ġ�� ó������ �����մϴ�.
		ControlledCannon->GetCannonBomb()->SetRelativeLocation(ControlledCannon->InitialLocation);
		UE_LOG(LogTemp, Warning, TEXT("Time is Gone"));
	}




}

void UObstacleAttackComponent::AttackFinished()
{

}

void UObstacleAttackComponent::SetAttackRequested(bool isAttackRequested)
{
	IsAttackRequested = isAttackRequested;
}

