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
	// 수평 축 이동 입력 시 호출됩니다.
	void OnHorizontalMovementInput(float axis);

	// 수직 축 이동 입력 시 호출됩니다.
	void OnVerticalMovementInput(float axis);

	// 점프 입력 시 호출됩니다.
	void OnJumpInput();
	
};
