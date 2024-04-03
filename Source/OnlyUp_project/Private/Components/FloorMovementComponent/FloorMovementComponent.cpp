#include "Components/FloorMovementComponent/FloorMovementComponent.h"

#include "Actor/Obstacle/Pawn/Static/Floor/ControlledFloor.h"

UFloorMovementComponent::UFloorMovementComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	IsMoveRequested = true;
}


void UFloorMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	
}


void UFloorMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ¸Å Æ½¸¶´Ù ¹Ù´Ú ¿òÁ÷ÀÓ ¼³Á¤
	OnMoveFloor(DeltaTime);

}

void UFloorMovementComponent::OnMoveFloor(float dt)
{
	// Get Floor °´Ã¼
	AControlledFloor* floor = Cast<AControlledFloor>(GetOwner());

	if (IsMoveRequested)
		floor->OpenFloor(dt);
	else return;

}

