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

	GameCharacter = Cast<AGameCharacter>(GetOwner());
}


void UPlayerCharacterMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


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
	float maxWalkspeed = gameCharacter->GetCharacterMovement()->MaxWalkSpeed;
	float jumpZvelocity = gameCharacter->GetCharacterMovement()->JumpZVelocity;

	if (maxWalkspeed > 300.0f) gameCharacter->GetCharacterMovement()->JumpZVelocity = 550.0f;
	else gameCharacter->GetCharacterMovement()->JumpZVelocity = 400.f;

	gameCharacter->Jump();
}

