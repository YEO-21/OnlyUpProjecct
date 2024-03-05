#include "Components/ZoomableSpringArmComponent/ZoomableSpringArmComponent.h"

UZoomableSpringArmComponent::UZoomableSpringArmComponent()
{
	ZoomMultiplier = 20.0f;

	ZoomLengthMin = 200.0f;
	ZoomLengthMax = 600.0f;
}

void UZoomableSpringArmComponent::DoZoomInOut(float axis)
{
	TargetArmLength -= axis * ZoomMultiplier;
	TargetArmLength = FMath::Clamp(TargetArmLength, ZoomLengthMin, ZoomLengthMax);
}
