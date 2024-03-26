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
	// 유효성 검사
	if (!IsValid(ControlledCannon)) return;

	// 현재 시간을 기록합니다.
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

