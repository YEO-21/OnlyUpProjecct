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
		TEXT("VerticalMove"), this, & ThisClass::OnVerticalMovementInput);


	
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
