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


	// 스태틱 메시 컴포넌트 추가
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("STATIC_MESH_COMP"));
	StaticMeshComponent->SetMobility(EComponentMobility::Movable);

	// 씬 컴포넌트 추가
	SampleComp = CreateDefaultSubobject<USceneComponent>(TEXT("SAMPLE_COMP"));
	SampleComp->SetupAttachment(StaticMeshComponent, TEXT("Socket_CannonBomb"));
	SetRootComponent(SampleComp);

	// 캐논밤 컴포넌트 추가
	CannonBomb = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CANNON_BOMB"));
	CannonBomb->SetupAttachment(StaticMeshComponent, TEXT("Socket_CannonBomb"));
	CannonBomb->SetMobility(EComponentMobility::Movable);

	// 캐논밤 공격 상호작용 컴포넌트 추가
	BombInteractComp = CreateDefaultSubobject<UCannonBombInteractComponent>(TEXT("BOMB_INTERACT_COMP"));
	BombInteractComp->SetupAttachment(CannonBomb);
	//BombInteractComp->SetSimulatePhysics(true);
	BombInteractComp->SetCollisionProfileName(TEXT("OverlapAll"));

	
	//InitialLocation = SampleComp->GetComponentLocation(); // WORLD
	//InitialLocation = SampleComp->GetRelativeLocation(); // LOCAL



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




