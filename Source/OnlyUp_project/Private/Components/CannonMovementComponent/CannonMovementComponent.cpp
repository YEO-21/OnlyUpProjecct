#include "Components/CannonMovementComponent/CannonMovementComponent.h"

#include "Actor/Obstacle/Pawn/Static/Cannon/ControlledCannon.h"

UCannonMovementComponent::UCannonMovementComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}


void UCannonMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	// Get Cannon
	Cannon = Cast<AControlledCannon>(GetOwner());
}

void UCannonMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	TurnningSmooth(DeltaTime);

}

void UCannonMovementComponent::TurnningSmooth(float dt)
{
	// 현재 회전값
	FRotator currentRotation = Cannon->GetActorRotation();
	//UE_LOG(LogTemp, Warning, TEXT("currentRotation.yaw is [%.2f]"), currentRotation.Yaw);

	// 목표 회전값
	FRotator targetRotation = FRotator(0.0f, TargetYawAngle, 0.0f);


	if (currentRotation.Equals(targetRotation, 5.0f))
	{
		TargetYawAngle = targetRotation.Yaw;
		Cannon->SetActorRotation(targetRotation);

		IsYawTurning = false;
	}
	else
	{
		FRotator newRotation = FMath::RInterpTo(currentRotation, targetRotation, dt, 50.0f);

		Cannon->SetActorRotation(newRotation);
	}
}


void UCannonMovementComponent::SetTargetYawAngle(float targetYawAngle)
{
	TargetYawAngle = targetYawAngle;
}

void UCannonMovementComponent::StartTurn()
{
	IsYawTurning = true;
}

