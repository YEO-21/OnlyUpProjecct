#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CannonMovementComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UCannonMovementComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY()
	class AControlledCannon* Cannon;

	UPROPERTY()
	bool IsYawTurning;

	// ��ǥ Yaw ȸ����
	UPROPERTY()
	float TargetYawAngle;



public:	
	UCannonMovementComponent();

protected:
	virtual void BeginPlay() override;

private:
	// ȸ���� �ڿ������� �ϵ��� �մϴ�.
	void TurnningSmooth(float dt);

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// ��ǥ Yaw ȸ������ �����մϴ�.
	void SetTargetYawAngle(float targetYawAngle);

	// ������ ��ǥ Yaw�� ȸ���մϴ�.
	void StartTurn();



		
};
