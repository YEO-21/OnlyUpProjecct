// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/Obstacle/Pawn/Static/ControlledStaticObstacle.h"
#include "ControlledFloor.generated.h"

/**
 * 
 */
UCLASS()
class AControlledFloor : public AControlledStaticObstacle
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* Floor;

	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	class UFloorMovementComponent* FloorMovementComponent;

public:
	AControlledFloor();

protected:
	virtual void Tick(float DeltaTime) override;

public:
	void OpenFloor(float dt);
};
