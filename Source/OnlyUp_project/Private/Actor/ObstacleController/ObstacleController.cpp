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

	// 데이터에 설정된 비헤이비어 트리 에셋을 동기 로드 합니다.
	UBehaviorTree* btAsset = Cast<UBehaviorTree>(streamableManager.LoadSynchronous(
		obstacleData->BehaviorTreeAsset.ToSoftObjectPath()));

	if (IsValid(btAsset))
	{
		RunBehaviorTree(btAsset);
		UE_LOG(LogTemp, Warning, TEXT("BehaviorTreeAsset is Running!"));
	}

}
