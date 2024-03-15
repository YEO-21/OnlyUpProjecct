
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "ControlledObstacle.generated.h"

UCLASS()
class AControlledObstacle : public APawn
{
	GENERATED_BODY()


protected:
	// 장애물 코드
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName ObstacleCode;

	// 장애물 정보 구조체를 나타냅니다.
	struct FObstacleData* ObstacleData;

	// 장애물 데이터 테이블을 나타냅니다.
	class UDataTable* ObstacleDataTable;



public:
	AControlledObstacle();

	virtual void BeginPlay() override;

	// 폰이 빙의가 되었을 때 호출되는 함수입니다.
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
