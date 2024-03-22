#include "Components/ObstacleAttackComponent/ObstacleAttackComponent.h"

#include "Actor/Obstacle/Pawn/Static/Cannon/ControlledCannon.h"

#include "BehaviorTree/BlackboardComponent.h"

UObstacleAttackComponent::UObstacleAttackComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	IsAttacking = true;

	IsReadyToRecharge =  false;
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

	if ((currentTime > ControlledCannon->CannonAttackTime + 20.0f) && IsAttacking)
	{
		UE_LOG(LogTemp, Warning, TEXT("Bomb is destroyed."));
		DestroyBomb();
	}	

	if (IsReadyToRecharge)
	{
		RechargeBomb();
	}

}

void UObstacleAttackComponent::AttackStart()
{
	// 유효성 검사
	if (!IsValid(ControlledCannon)) return;

	// 현재 시간을 기록합니다.
	float currentTime = GetWorld()->GetTimeSeconds();
	//UE_LOG(LogTemp, Warning, TEXT("currentTime = [%.2f]"), currentTime);

	// 공격한 시간을 기록합니다.
	float attackTime = ControlledCannon->CannonAttackTime;
	//UE_LOG(LogTemp, Warning, TEXT("attackTime = [%.2f]"), attackTime);

	if (currentTime > attackTime + 10.0f)
	{
		// 대포알의 위치를 처음으로 설정합니다.
		ControlledCannon->GetCannonBomb()->SetRelativeLocation
		(ControlledCannon->InitialLocation);
		attackTime = 0.0f;
	}




}

void UObstacleAttackComponent::AttackFinished()
{

}

void UObstacleAttackComponent::DestroyBomb()
{
	AControlledCannon* cannon = Cast<AControlledCannon>(GetOwner());

	cannon->DestroyCannonBomb();

	IsAttacking = false;
	
	IsReadyToRecharge = true;
}

void UObstacleAttackComponent::RechargeBomb()
{
	AControlledCannon* cannon = Cast<AControlledCannon>(GetOwner());

	cannon->RechargeCannonBomb();
	IsReadyToRecharge = false;
}

void UObstacleAttackComponent::SetAttackRequested(bool isAttackRequested)
{
	IsAttackRequested = isAttackRequested;
}

