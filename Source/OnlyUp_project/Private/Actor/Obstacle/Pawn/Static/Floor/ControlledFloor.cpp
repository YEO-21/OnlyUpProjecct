#include "Actor/Obstacle/Pawn/Static/Floor/ControlledFloor.h"

#include "Components/FloorMovementComponent/FloorMovementComponent.h"

AControlledFloor::AControlledFloor()
{
	// 스태틱 메시 컴포넌트 추가
	Floor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("STATIC_MESH_COMP"));

	// 바닥 이동 컴포넌트 추가
	FloorMovementComponent = CreateDefaultSubobject<UFloorMovementComponent>(TEXT("FLOOR_MOVE_COMP"));


	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_FLOOR(
		TEXT("/Script/Engine.StaticMesh'/Game/FantasyBundle/Meshes/SM_Ceiling.SM_Ceiling'"));

	if (SM_FLOOR.Succeeded())
	{
		Floor->SetStaticMesh(SM_FLOOR.Object);
	}

}

void AControlledFloor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AControlledFloor::OpenFloor(float dt)
{
	FRotator floorRotator = Floor->GetRelativeRotation();

	// Pitch 값이 90이라면 회전 종료
	if (floorRotator.Pitch == -90.0f)
		return;

	floorRotator.Pitch -= 0.5f;

	Floor->SetRelativeRotation(floorRotator);

	

}

