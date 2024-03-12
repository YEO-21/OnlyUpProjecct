#include "Actor/Obstacle/StaticMesh/Dynamic/DynamicObstacle.h"

#include "Components/ObstacleMovementComponent/ObstacleMovementComponent.h"

ADynamicObstacle::ADynamicObstacle()
{
	ObstacleMovementComponent = CreateDefaultSubobject<UObstacleMovementComponent>(
		TEXT("OB_MOVE_COMP"));
}
