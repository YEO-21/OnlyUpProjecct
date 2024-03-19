// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/Obstacle/Pawn/Static/ControlledStaticObstacle.h"
#include "ControlledCannon.generated.h"

/**
 * 
 */
UCLASS()
class AControlledCannon : public AControlledStaticObstacle
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	class UObstacleAttackComponent* ObstacleAttackComponent;

	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	class UCannonMovementComponent* CannonMovementComponent;

	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* CannonBomb;


public:
	AControlledCannon();


	FORCEINLINE class UCannonMovementComponent* GetCannonMovementComponent() const
	{
		return CannonMovementComponent;
	}

	FORCEINLINE class UObstacleAttackComponent* GetObstacleAttackComponent() const
	{
		return ObstacleAttackComponent;
	}

	FORCEINLINE class UStaticMeshComponent* GetCannonBomb() const
	{
		return CannonBomb;
	}


	
	void OnPlayerCharacterDetected(class AGameCharacter* gameCharacter);

};
