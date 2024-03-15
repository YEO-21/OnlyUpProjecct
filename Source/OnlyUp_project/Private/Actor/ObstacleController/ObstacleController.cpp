#include "Actor/ObstacleController/ObstacleController.h"

#include "Structure/ObstacleData/ObstacleData.h"

#include "Engine/AssetManager.h"
#include "Engine/StreamableManager.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"

void AObstacleController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	// Get BlackboardComponent;
	BlackboardComponent = GetBlackboardComponent();

}

void AObstacleController::InitializeEnemyController(FObstacleData* obstacleData)
{
	if (obstacleData == nullptr) return;

	// Get StreamableManager
	FStreamableManager& streamableManager = UAssetManager::GetStreamableManager();

	// �����Ϳ� ������ �����̺�� Ʈ�� ������ ���� �ε� �մϴ�.
	UBehaviorTree* btAsset = Cast<UBehaviorTree>(streamableManager.LoadSynchronous(
		obstacleData->BehaviorTreeAsset.ToSoftObjectPath()));

	if (IsValid(btAsset))
	{
		RunBehaviorTree(btAsset);
		UE_LOG(LogTemp, Warning, TEXT("BehaviorTreeAsset is Running!"));
	}

}
