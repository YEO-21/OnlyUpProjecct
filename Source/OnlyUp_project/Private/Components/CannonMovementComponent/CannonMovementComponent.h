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

	// 목표 Yaw 회전값
	UPROPERTY()
	float TargetYawAngle;



public:	
	UCannonMovementComponent();

protected:
	virtual void BeginPlay() override;

private:
	// 회전을 자연스럽게 하도록 합니다.
	void TurnningSmooth(float dt);

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// 목표 Yaw 회전값을 설정합니다.
	void SetTargetYawAngle(float targetYawAngle);

	// 설정된 목표 Yaw로 회전합니다.
	void StartTurn();



		
};
