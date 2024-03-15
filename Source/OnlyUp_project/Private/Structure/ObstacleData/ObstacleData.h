#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "ObstacleData.generated.h"



// ��ֹ� ������ ��� ����ü�Դϴ�.
USTRUCT()
struct FObstacleData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	// ��ֹ� �̸�
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText Name;

	// �ൿ Ʈ�� ����
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftObjectPtr<class UBehaviorTree> BehaviorTreeAsset;








};
