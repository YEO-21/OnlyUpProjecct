#include "Actor/Obstacle/Pawn/Static/Floor/ControlledFloor.h"

#include "Components/FloorMovementComponent/FloorMovementComponent.h"

AControlledFloor::AControlledFloor()
{
	// ����ƽ �޽� ������Ʈ �߰�
	Floor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("STATIC_MESH_COMP"));

	// �ٴ� �̵� ������Ʈ �߰�
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

	// Pitch ���� 90�̶�� ȸ�� ����
	if (floorRotator.Pitch == -90.0f)
		return;

	floorRotator.Pitch -= 0.5f;

	Floor->SetRelativeRotation(floorRotator);

	

}

