#include "Components/ObstacleAttackComponent/ObstacleAttackComponent.h"

#include "Actor/Obstacle/Pawn/Static/Cannon/ControlledCannon.h"

#include "BehaviorTree/BlackboardComponent.h"

UObstacleAttackComponent::UObstacleAttackComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	IsAttacking = true;
}


void UObstacleAttackComponent::BeginPlay()
{
	Super::BeginPlay();

	ControlledCannon = Cast<AControlledCannon>(GetOwner());

}


void UObstacleAttackComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	float currentTime = GetWorld()->GetTimeSeconds();

	if (IsAttacking)
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

	if (!IsTimeToResetBomb)
	{
		TargetTime = currentTime + 5.0f;
		IsTimeToResetBomb = true;
	}
	UE_LOG(LogTemp, Warning, TEXT("currentTime is %.2f"), currentTime);
	UE_LOG(LogTemp, Warning, TEXT("TargetTime is %.2f"), TargetTime);



	if (currentTime > TargetTime)
	{
		IsTimeToResetBomb = false;
		UE_LOG(LogTemp, Warning, TEXT("Attack!"));
		ControlledCannon->ResetCannonBombLocation();
	}


}

void UObstacleAttackComponent::AttackFinished()
{

}


void UObstacleAttackComponent::SetAttackRequested(bool isAttackRequested)
{
	IsAttackRequested = isAttackRequested;
}

