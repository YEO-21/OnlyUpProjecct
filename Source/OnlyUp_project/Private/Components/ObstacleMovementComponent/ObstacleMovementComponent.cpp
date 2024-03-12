#include "Components/ObstacleMovementComponent/ObstacleMovementComponent.h"

#include "Actor/Obstacle/StaticMesh/Dynamic/MovingBlock/MovingBlockObstacle.h"

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

	MovingBlock= Cast<AMovingBlockObstacle>(GetOwner());

	MiddleLocation = MovingBlock->GetActorLocation();
	RightLocation = MiddleLocation + FVector(0.0f, 150.0f, 0.0f);
	LeftLocation = MiddleLocation - FVector(0.0f, 150.0f, 0.0f);


	// ...
	
}


// Called every frame
void UObstacleMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//UE_LOG(LogTemp, Warning, TEXT("%.2f"), MovingBlock->GetActorLocation().Y);
	MoveBlock(MovingBlock->GetActorLocation());
	

	
}

void UObstacleMovementComponent::MoveBlock(FVector blocklocation)
{
	// 블록의 위치가 증가합니다.
	if (IsIncreased)
	{
		FVector newLocation = blocklocation + FVector(0.0f, 5.0f, 0.0f);
		MovingBlock->SetActorLocation(newLocation);
	}
	
	// RightVector 위치에 도달하면 증가를 멈춥니다.
	if (MovingBlock->GetActorLocation() == RightLocation)
	{
		IsIncreased = false;
	}

	// 블록의 위치를 감소시킵니다.
	if (!IsIncreased)
	{

		FVector newLocation = blocklocation - FVector(0.0f, 5.0f, 0.0f);
		MovingBlock->SetActorLocation(newLocation);
	}

	// LeftVector 위치에 도달하면 감소를 멈춥니다.
	if (MovingBlock->GetActorLocation() == LeftLocation)
	{
		IsIncreased = true;
	}

}

