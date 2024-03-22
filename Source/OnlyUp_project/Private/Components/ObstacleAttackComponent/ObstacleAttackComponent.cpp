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
	// ��ȿ�� �˻�
	if (!IsValid(ControlledCannon)) return;

	// ���� �ð��� ����մϴ�.
	float currentTime = GetWorld()->GetTimeSeconds();
	//UE_LOG(LogTemp, Warning, TEXT("currentTime = [%.2f]"), currentTime);

	// ������ �ð��� ����մϴ�.
	float attackTime = ControlledCannon->CannonAttackTime;
	//UE_LOG(LogTemp, Warning, TEXT("attackTime = [%.2f]"), attackTime);

	if (currentTime > attackTime + 10.0f)
	{
		// �������� ��ġ�� ó������ �����մϴ�.
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

