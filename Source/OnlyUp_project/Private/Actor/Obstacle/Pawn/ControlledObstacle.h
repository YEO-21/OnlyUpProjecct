
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "ControlledObstacle.generated.h"

UCLASS()
class AControlledObstacle : public APawn
{
	GENERATED_BODY()


protected:
	// ��ֹ� �ڵ�
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName ObstacleCode;

	// ��ֹ� ���� ����ü�� ��Ÿ���ϴ�.
	struct FObstacleData* ObstacleData;

	// ��ֹ� ������ ���̺��� ��Ÿ���ϴ�.
	class UDataTable* ObstacleDataTable;



public:
	AControlledObstacle();

	virtual void BeginPlay() override;

	// ���� ���ǰ� �Ǿ��� �� ȣ��Ǵ� �Լ��Դϴ�.
	virtual void PossessedBy(AController* NewController) override;



public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


private:
	void InitializeObstacleData();

protected:
	virtual void SetObstacleController(TSubclassOf<class AObstacleController> controllerClass,
		EAutoPossessAI possessType = EAutoPossessAI::PlacedInWorldOrSpawned);

};
