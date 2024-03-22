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

	InitialLocation = StaticMeshComponent->GetSocketLocation(TEXT("Socket_CannonBomb"));
	UE_LOG(LogTemp, Warning, TEXT("InitialLocation.X = [%.2f]"), InitialLocation.X);
	UE_LOG(LogTemp, Warning, TEXT("InitialLocation.Y = [%.2f]"), InitialLocation.Y);
	UE_LOG(LogTemp, Warning, TEXT("InitialLocation.Z = [%.2f]"), InitialLocation.Z);



	if (SM_CANNON.Succeeded())
	{
		// ����ƽ �޽� ����
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

	
	for (int i = 0; i < 100; ++i)
	{
		Bombs.Add(CannonBomb);
	}



	// ��ֹ� ���� ������Ʈ �߰�
	ObstacleAttackComponent = CreateDefaultSubobject<UObstacleAttackComponent>(
		TEXT("ATTACK_COMP"));


	// �̵� ������Ʈ �߰�
	CannonMovementComponent = CreateDefaultSubobject<UCannonMovementComponent>(
		TEXT("MOVEMENT_COMP"));




	SetObstacleController(ACannonController::StaticClass());


	// ��ֹ� �ڵ� 
	ObstacleCode = TEXT("000001");

}

void AControlledCannon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	
}

void AControlledCannon::OnPlayerCharacterDetected(AGameCharacter* gameCharacter)
{
	ACannonController* cannonController = Cast<ACannonController>(GetController());
	cannonController->SetPlayerCharacterKey(gameCharacter);
	
}



void AControlledCannon::RechargeCannonBomb()
{
	Bombs[1] = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CANNON_BOMB"));
	Bombs[1]->SetupAttachment(StaticMeshComponent, TEXT("Socket_CannonBomb"));
	Bombs[1]->SetMobility(EComponentMobility::Movable);
}

void AControlledCannon::DestroyCannonBomb()
{
	Bombs[0]->DestroyComponent();

}

