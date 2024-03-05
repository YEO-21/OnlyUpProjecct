#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GamePlayerController.generated.h"


UCLASS()
class AGamePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AGamePlayerController();

protected:
	virtual void SetupInputComponent() override;

	virtual void OnPossess(APawn* pawn) override;


private:
	// ���� �� �̵� �Է� �� ȣ��˴ϴ�.
	void OnHorizontalMovementInput(float axis);

	// ���� �� �̵� �Է� �� ȣ��˴ϴ�.
	void OnVerticalMovementInput(float axis);

	// ���� �Է� �� ȣ��˴ϴ�.
	void OnJumpInput();
	
};
