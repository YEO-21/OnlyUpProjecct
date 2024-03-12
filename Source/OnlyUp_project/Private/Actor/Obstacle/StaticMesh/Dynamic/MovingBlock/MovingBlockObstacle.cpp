#include "Actor/Obstacle/StaticMesh/Dynamic/MovingBlock/MovingBlockObstacle.h"
#include "Components/StaticMeshComponent.h"

AMovingBlockObstacle::AMovingBlockObstacle()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_MOVINGBLOCK(
		TEXT("/Script/Engine.StaticMesh'/Game/FantasyBundle/Meshes/SM_StairsBox02.SM_StairsBox02'"));


	UStaticMeshComponent* staticmeshComponent = GetStaticMeshComponent();
	staticmeshComponent->SetMobility(EComponentMobility::Movable);

	if (SM_MOVINGBLOCK.Succeeded())
	{
		staticmeshComponent->SetStaticMesh(SM_MOVINGBLOCK.Object);
	}



		
}
