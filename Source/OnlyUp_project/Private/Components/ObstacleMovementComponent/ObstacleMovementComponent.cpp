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
	// ����� ��ġ�� �����մϴ�.
	if (IsIncreased)
	{
		FVector newLocation = blocklocation + FVector(0.0f, 5.0f, 0.0f);
		MovingBlock->SetActorLocation(newLocation);
	}
	
	// RightVector ��ġ�� �����ϸ� ������ ����ϴ�.
	if (MovingBlock->GetActorLocation() == RightLocation)
	{
		IsIncreased = false;
	}

	// ����� ��ġ�� ���ҽ�ŵ�ϴ�.
	if (!IsIncreased)
	{

		FVector newLocation = blocklocation - FVector(0.0f, 5.0f, 0.0f);
		MovingBlock->SetActorLocation(newLocation);
	}

	// LeftVector ��ġ�� �����ϸ� ���Ҹ� ����ϴ�.
	if (MovingBlock->GetActorLocation() == LeftLocation)
	{
		IsIncreased = true;
	}

}

