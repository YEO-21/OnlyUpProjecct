#include "PlayerCharacterMovementComponent.h"

#include "Actor/GameCharacter/GameCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"

UPlayerCharacterMovementComponent::UPlayerCharacterMovementComponent()
{
	PrimaryComponentTick.bCanEverTick = true;


}


void UPlayerCharacterMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	
}


void UPlayerCharacterMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	UpdateJumpVelocity();

}

void UPlayerCharacterMovementComponent::HorizontalMove(float axis)
{
	AGameCharacter* gameCharacter = Cast<AGameCharacter>(GetOwner());
	FRotator yawRotator = FRotator(0.0f, gameCharacter->GetControlRotation().Yaw, 0.0f);

	FVector rightvector = FRotationMatrix(yawRotator).GetUnitAxis(EAxis::Y);
	gameCharacter->AddMovementInput(rightvector, axis);

}

void UPlayerCharacterMovementComponent::VerticalMove(float axis)
{
	AGameCharacter* gameCharacter = Cast<AGameCharacter>(GetOwner());
	FRotator yawRotator = FRotator(0.0f, gameCharacter->GetControlRotation().Yaw, 0.0f);

	FVector forwardvector = FRotationMatrix(yawRotator).GetUnitAxis(EAxis::X);
	gameCharacter->AddMovementInput(forwardvector, axis);
}

void UPlayerCharacterMovementComponent::OnJump()
{
	AGameCharacter* gameCharacter = Cast<AGameCharacter>(GetOwner());
	gameCharacter->Jump();
}

void UPlayerCharacterMovementComponent::UpdateJumpVelocity()
{
	AGameCharacter* gameCharacter = Cast<AGameCharacter>(GetOwner());
	float walkspeed = gameCharacter->GetCharacterMovement()->MaxWalkSpeed;

	
	if (walkspeed > 300.0f)
	{
		UE_LOG(LogTemp, Warning, TEXT("JumpZVelocity is [%.2f]"), gameCharacter->GetCharacterMovement()->JumpZVelocity);
		gameCharacter->GetCharacterMovement()->JumpZVelocity = 550.0f;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("JumpZVelocity is [%.2f]"), gameCharacter->GetCharacterMovement()->JumpZVelocity);
		gameCharacter->GetCharacterMovement()->JumpZVelocity = 450.0f;
	}
}

