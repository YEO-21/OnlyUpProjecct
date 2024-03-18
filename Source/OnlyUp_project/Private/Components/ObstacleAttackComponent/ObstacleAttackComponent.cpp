#include "Components/ObstacleAttackComponent/ObstacleAttackComponent.h"

#include "BehaviorTree/BlackboardComponent.h"

UObstacleAttackComponent::UObstacleAttackComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	IsAttacking = false;

	ConstructorHelpers::FClassFinder<AActor> ACTOR_BOMB(
		TEXT("/Script/Engine.Blueprint'/Game/Blueprints/Actor/Obstacle/BP_Bomb.BP_Bomb_C'"));

	if (ACTOR_BOMB.Succeeded())
	{
		
	}



}


void UObstacleAttackComponent::BeginPlay()
{
	Super::BeginPlay();

	
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







}

void UObstacleAttackComponent::AttackFinished()
{
}

void UObstacleAttackComponent::SetAttackRequested(bool isAttackRequested)
{
	IsAttackRequested = isAttackRequested;
}

