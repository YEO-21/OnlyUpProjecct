#include "Actor/Obstacle/StaticMesh/Static/Cannon/CannonObstacle.h"

#include "Components/StaticMeshComponent.h"
#include "Components/ObstacleAttackComponent/ObstacleAttackComponent.h"

ACannonObstacle::ACannonObstacle()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_CANNON(
		TEXT("/Script/Engine.StaticMesh'/Game/FantasyBundle/Meshes/SM_Cannon01.SM_Cannon01'"));


	UStaticMeshComponent* staticMeshComponent = GetStaticMeshComponent();
	
	if (SM_CANNON.Succeeded())
	{
		// ����ƽ �޽� ����
		staticMeshComponent->SetStaticMesh(SM_CANNON.Object);
	}

	// ��ֹ� ���� ������Ʈ �߰�
	ObstacleAttackComponent = CreateDefaultSubobject<UObstacleAttackComponent>(
		TEXT("ATTACK_COMP"));






}
