#include "Actor/PlayerController/GamePlayerController.h"
#include "Actor/GameCharacter/GameCharacter.h"

AGamePlayerController::AGamePlayerController()
{
}

void AGamePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis(
		TEXT("HorizontalMove"), this, &ThisClass::OnHorizontalMovementInput);

	InputComponent->BindAxis(
		TEXT("VerticalMove"), this, &ThisClass::OnVerticalMovementInput);

	InputComponent->BindAxis(
		TEXT("MouseX"), this, &ThisClass::OnMouseXInput);

	InputComponent->BindAxis(
		TEXT("MouseX"), this, &ThisClass::OnMouseYInput);

	InputComponent->BindAxis(
		TEXT("MouseX"), this, &ThisClass::OnZoomInput);


	InputComponent->BindAction(
		TEXT("Jump"), EInputEvent::IE_Pressed, this, &ThisClass::OnJumpInput);


	
}

void AGamePlayerController::OnPossess(APawn* pawn)
{
	Super::OnPossess(pawn);


}

void AGamePlayerController::OnHorizontalMovementInput(float axis)
{
	AGameCharacter* gameCharacter = Cast<AGameCharacter>(GetPawn());
	gameCharacter->OnHorizontalInput(axis);
}

void AGamePlayerController::OnVerticalMovementInput(float axis)
{
	AGameCharacter* gameCharacter = Cast<AGameCharacter>(GetPawn());
	gameCharacter->OnVerticalInput(axis);
}

void AGamePlayerController::OnJumpInput()
{
	AGameCharacter* gameCharacter = Cast<AGameCharacter>(GetPawn());
	gameCharacter->OnJumpInput();
}

void AGamePlayerController::OnMouseXInput(float axis)
{
	// Yaw회전에 axis 값을 더합니다.
	AddYawInput(axis);
}

void AGamePlayerController::OnMouseYInput(float axis)
{
	// Pitch회전에 -axis 값을 더합니다.
	AddPitchInput(-axis);
}

void AGamePlayerController::OnZoomInput(float axis)
{
	AGameCharacter* gameCharacter = Cast<AGameCharacter>(GetPawn());
	gameCharacter->OnZoomCamera(axis);
}
