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

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_BOMB(
		TEXT("/Script/Engine.StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));


	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("STATIC_MESH_COMP"));
	StaticMeshComponent->SetMobility(EComponentMobility::Movable);

	CannonBomb = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CANNON_BOMB"));
	CannonBomb->SetupAttachment(StaticMeshComponent, TEXT("Socket_CannonBomb"));
	CannonBomb->SetMobility(EComponentMobility::Movable);

	InitialLocation = CannonBomb->GetRelativeLocation();
	//UE_LOG(LogTemp, Warning, TEXT("InitialLocation.X = [%.2f]"), InitialLocation.X);
	//UE_LOG(LogTemp, Warning, TEXT("InitialLocation.Y = [%.2f]"), InitialLocation.Y);
	//UE_LOG(LogTemp, Warning, TEXT("InitialLocation.Z = [%.2f]"), InitialLocation.Z);
	//CannonBomb->SetSimulatePhysics(true);


	if (SM_CANNON.Succeeded())
	{
		// 스태틱 메시 적용
		StaticMeshComponent->SetStaticMesh(SM_CANNON.Object);
	}

	if (DT_OBSTACLE.Succeeded())
	{
		ObstacleDataTable = DT_OBSTACLE.Object;
	}

	if (SM_BOMB.Succeeded())
	{
		CannonBomb->SetStaticMesh(SM_BOMB.Object);
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
