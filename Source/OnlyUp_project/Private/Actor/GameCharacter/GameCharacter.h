#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameCharacter.generated.h"

UCLASS()
class AGameCharacter : public ACharacter
{
	GENERATED_BODY()


private:
	// 플레이어 스타트 위치
	UPROPERTY()
	FVector InitializedPlayerLocation;

	UPROPERTY(VisibleAnywhere, meta  = (AllowrprivateAccess = "true"))
	class UPlayerCharacterMovementComponent* MovementComponent;

	UPROPERTY(VisibleAnywhere, meta = (AllowrprivateAccess = "true"))
	class UCameraComponent* CameraComponent;

	UPROPERTY(VisibleAnywhere, meta = (AllowrprivateAccess = "true"))
	class UZoomableSpringArmComponent* SpringArmComponent;



public:
	AGameCharacter();

	void OnHorizontalInput(float axis);
	void OnVerticalInput(float axis);
	void OnJumpInput();
	void OnAccerlationInput();
	void OnWalkInput();

	void OnZoomCamera(float axis);

	void UpdateAnimParams();



protected:
	virtual void BeginPlay() override;

	virtual void Destroyed() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void PlayRagDoll();
	

};
