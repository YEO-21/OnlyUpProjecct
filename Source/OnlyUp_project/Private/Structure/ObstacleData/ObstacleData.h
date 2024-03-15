#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "ObstacleData.generated.h"



// 장애물 정보를 담는 구조체입니다.
USTRUCT()
struct FObstacleData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	// 장애물 이름
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText Name;

	// 행동 트리 에셋
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftObjectPtr<class UBehaviorTree> BehaviorTreeAsset;








};
