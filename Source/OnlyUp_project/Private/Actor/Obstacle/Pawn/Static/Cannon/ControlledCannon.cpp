#include "Actor/Obstacle/Pawn/Static/Cannon/ControlledCannon.h"
#include "Actor/ObstacleController/Cannon/CannonController.h"

#include "Components/StaticMeshComponent.h"
#include "Components/ObstacleAttackComponent/ObstacleAttackComponent.h"
#include "Components/CannonBombInteractComponent/CannonBombInteractComponent.h"
#include "Components/SphereComponent.h"

AControlledCannon::AControlledCannon()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_CANNON(
		TEXT("/Script/Engine.StaticMesh'/Game/FantasyBundle/Meshes/SM_Cannon01.SM_Cannon01'"));

	static ConstructorHelpers::FObjectFinder<UDataTable> DT_OBSTACLE(
		TEXT("/Script/Engine.DataTable'/Game/Resources/DataTable/DT_Obstacle.DT_Obstacle'"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_BOMB(
		TEXT("/Script/Engine.StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));


	// ����ƽ �޽� ������Ʈ �߰�
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("STATIC_MESH_COMP"));
	StaticMeshComponent->SetMobility(EComponentMobility::Movable);

	// �� ������Ʈ �߰�
	SampleComp = CreateDefaultSubobject<USceneComponent>(TEXT("SAMPLE_COMP"));
	SampleComp->SetupAttachment(StaticMeshComponent, TEXT("Socket_CannonBomb"));
	SetRootComponent(SampleComp);

	// ĳ��� ������Ʈ �߰�
	CannonBomb = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CANNON_BOMB"));
	CannonBomb->SetupAttachment(StaticMeshComponent, TEXT("Socket_CannonBomb"));
	CannonBomb->SetMobility(EComponentMobility::Movable);

	// ĳ��� ���� ��ȣ�ۿ� ������Ʈ �߰�
	BombInteractComp = CreateDefaultSubobject<UCannonBombInteractComponent>(TEXT("BOMB_INTERACT_COMP"));
	BombInteractComp->SetupAttachment(CannonBomb);
	//BombInteractComp->SetSimulatePhysics(true);
	BombInteractComp->SetCollisionProfileName(TEXT("OverlapAll"));

	
	//InitialLocation = SampleComp->GetComponentLocation(); // WORLD
	//InitialLocation = SampleComp->GetRelativeLocation(); // LOCAL



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

void AControlledCannon::ResetCannonBombLocation()
{
	FVector socketLocation = StaticMeshComponent->GetSocketLocation(TEXT("Socket_CannonBomb"));
	UE_LOG(LogTemp, Warning, TEXT("socketLocation.X = [%.2f]"), socketLocation.X);
	UE_LOG(LogTemp, Warning, TEXT("socketLocation.Y = [%.2f]"), socketLocation.Y);
	UE_LOG(LogTemp, Warning, TEXT("socketLocation.Z = [%.2f]"), socketLocation.Z);


	CannonBomb->SetWorldLocation(socketLocation);
	CannonBomb->SetSimulatePhysics(false);

}

void AControlledCannon::OnPlayerCharacterDetected(AGameCharacter* gameCharacter)
{
	ACannonController* cannonController = Cast<ACannonController>(GetController());
	cannonController->SetPlayerCharacterKey(gameCharacter);
	
}




