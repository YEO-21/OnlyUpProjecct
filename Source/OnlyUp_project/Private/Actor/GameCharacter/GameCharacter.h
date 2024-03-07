#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameCharacter.generated.h"

UCLASS()
class AGameCharacter : public ACharacter
{
	GENERATED_BODY()

private:


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

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	

};
