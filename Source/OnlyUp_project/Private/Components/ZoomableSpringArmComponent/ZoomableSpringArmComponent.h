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
	// 줌에 곱해질 승수입니다.
	float ZoomMultiplier;

	// 줌 최소, 최대 거리를 나타냅니다.
	float ZoomLengthMin;
	float ZoomLengthMax;

public:
	UZoomableSpringArmComponent();

	void DoZoomInOut(float axis);
	
};
