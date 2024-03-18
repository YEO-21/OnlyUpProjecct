#include "Actor/Obstacle/Pawn/ControlledObstacle.h"
#include "Actor/ObstacleController/ObstacleController.h"


#include "Structure/ObstacleData/ObstacleData.h"

AControlledObstacle::AControlledObstacle()
{
	PrimaryActorTick.bCanEverTick = true;

	SetObstacleController(AObstacleController::StaticClass());
}

void AControlledObstacle::BeginPlay()
{
	Super::BeginPlay();

	

}

void AControlledObstacle::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	InitializeObstacleData();


	if (ObstacleData == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("ObstacleCode : [%s] is not valid"), *ObstacleCode.ToString());
		return;
	}
	else
	{
		AObstacleController* obstacleController = Cast<AObstacleController>(NewController);
		obstacleController->InitializeEnemyController(ObstacleData);
	}
	


}

void AControlledObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AControlledObstacle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AControlledObstacle::InitializeObstacleData()
{
	if (ObstacleCode.IsNone()) return;

	FString contextstring;

	ObstacleData = ObstacleDataTable->FindRow<FObstacleData>(ObstacleCode, contextstring);
	if (ObstacleData)
	{
		UE_LOG(LogTemp, Warning, TEXT("Obstacle Code is %s"), *ObstacleCode.ToString());
	}




}

void AControlledObstacle::SetObstacleController(TSubclassOf<class AObstacleController> controllerClass, EAutoPossessAI possessType)
{
	AIControllerClass = controllerClass;
	AutoPossessAI = possessType;
}

