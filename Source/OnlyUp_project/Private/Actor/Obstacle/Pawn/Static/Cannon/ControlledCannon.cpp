#include "Actor/Obstacle/Pawn/Static/Cannon/ControlledCannon.h"
#include "Actor/ObstacleController/Cannon/CannonController.h"

#include "Components/StaticMeshComponent.h"
#include "Components/ObstacleAttackComponent/ObstacleAttackComponent.h"

AControlledCannon::AControlledCannon()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_CANNON(
		TEXT("/Script/Engine.StaticMesh'/Game/FantasyBundle/Meshes/SM_Cannon01.SM_Cannon01'"));

	static ConstructorHelpers::FObjectFinder<UDataTable> DT_OBSTACLE(
		TEXT("/Script/Engine.DataTable'/Game/Resources/DataTable/DT_Obstacle.DT_Obstacle'"));


	if (DT_OBSTACLE.Succeeded())
	{
		ObstacleDataTable = DT_OBSTACLE.Object;
	}
	

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("STATIC_MESH_COMP"));


	if (SM_CANNON.Succeeded())
	{
		// 스태틱 메시 적용
		StaticMeshComponent->SetStaticMesh(SM_CANNON.Object);
	}



	// 장애물 공격 컴폰넌트 추가
	ObstacleAttackComponent = CreateDefaultSubobject<UObstacleAttackComponent>(
		TEXT("ATTACK_COMP"));


	// 이동 컴포넌트 추가
	CannonMovementComponent = CreateDefaultSubobject<UCannonMovementComponent>(
		TEXT("MOVEMENT_COMP"));


	SetObstacleController(ACannonController::StaticClass());


	// 장애물 코드 
	ObstacleCode = TEXT("000001");

	
}

void AControlledCannon::OnPlayerCharacterDetected(AGameCharacter* gameCharacter)
{
	ACannonController* cannonController = Cast<ACannonController>(GetController());
	cannonController->SetPlayerCharacterKey(gameCharacter);
	
}
