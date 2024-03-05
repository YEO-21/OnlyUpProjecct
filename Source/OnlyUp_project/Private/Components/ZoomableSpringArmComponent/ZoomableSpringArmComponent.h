#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SpringArmComponent.h"
#include "ZoomableSpringArmComponent.generated.h"

/**
 * 
 */
UCLASS()
class UZoomableSpringArmComponent : public USpringArmComponent
{
	GENERATED_BODY()

private:
	// �ܿ� ������ �¼��Դϴ�.
	float ZoomMultiplier;

	// �� �ּ�, �ִ� �Ÿ��� ��Ÿ���ϴ�.
	float ZoomLengthMin;
	float ZoomLengthMax;

public:
	UZoomableSpringArmComponent();

	void DoZoomInOut(float axis);
	
};
