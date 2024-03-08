#include "Actor/Obstacle/Obstacle.h"\

#include "Components/ObstacleMovementComponent/ObstacleMovementComponent.h"

#include "AIController.h"

#include "BehaviorTree/BlackboardComponent.h"

AObstacle::AObstacle()
{
	ObstacleMovementComponent = CreateDefaultSubobject<UObstacleMovementComponent>(
		TEXT("OB_MOVE_COMP"));


}

void AObstacle::BeginPlay()
{
	Super::BeginPlay();

	

}


