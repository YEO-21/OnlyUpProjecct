#include "Components/ObstacleMovementComponent/ObstacleMovementComponent.h"

#include "Actor/Obstacle/Dynamic/MovingBlock/MovingBlockObstacle.h"

// Sets default values for this component's properties
UObstacleMovementComponent::UObstacleMovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	IsIncreased = true;

	// ...
}


// Called when the game starts
void UObstacleMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	
	// ...
	
}


// Called every frame
void UObstacleMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	AMovingBlockObstacle* movingblock = Cast<AMovingBlockObstacle>(GetOwner());
	MoveLocation(movingblock->GetActorLocation());

	
}

void UObstacleMovementComponent::MoveLocation(FVector newLocation)
{
	AMovingBlockObstacle* movingblock = Cast<AMovingBlockObstacle>(GetOwner());
	FVector currentLocation = movingblock->GetActorLocation();
	FVector rightLocation = currentLocation + (0.0f, 100.0f, 0.0f);
	FVector leftLocation = currentLocation - (0.0f, 100.0f, 0.0f);

	if (currentLocation.Y < rightLocation.Y && IsIncreased)
	{
		currentLocation.Y += 0.01f;
	}
	else if (currentLocation.Y == rightLocation.Y)
	{
		IsIncreased = false;
	}
	else if (currentLocation.Y > leftLocation.Y && !IsIncreased)
	{
		currentLocation.Y -= 0.01f;
	}
	else if (currentLocation.Y == leftLocation.Y)
	{
		IsIncreased = true;
	}

	movingblock->SetActorLocation(currentLocation);


}

