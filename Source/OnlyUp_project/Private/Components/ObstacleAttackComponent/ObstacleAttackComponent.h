#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ObstacleAttackComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UObstacleAttackComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY()
	bool IsAttackRequested;


	UPROPERTY()
	bool IsAttacking;

	UPROPERTY()
	bool IsReadyToRecharge;


	UPROPERTY()
	class AActor* CannonBomb;


	class AControlledCannon* ControlledCannon;








public:	
	UObstacleAttackComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void AttackStart();
	void AttackFinished();

	void DestroyBomb();
	void RechargeBomb();


	FORCEINLINE bool GetAttackState() const
	{
		return IsAttacking;
	}

	void SetAttackRequested(bool isAttackRequested);


};
