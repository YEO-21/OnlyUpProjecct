#include "PlayerCharacterMovementComponent.h"

#include "Actor/GameCharacter/GameCharacter.h"

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

}

void UPlayerCharacterMovementComponent::HorizontalMove(float axis)
{
	UE_LOG(LogTemp, Warning, TEXT("HorizontalMove is called"));
	AGameCharacter* gameCharacter = Cast<AGameCharacter>(GetOwner());
	FRotator yawRotator = FRotator(0.0f, gameCharacter->GetControlRotation().Yaw, 0.0f);

	FVector rightvector = FRotationMatrix(yawRotator).GetUnitAxis(EAxis::Y);
	gameCharacter->AddMovementInput(rightvector, axis);

}

void UPlayerCharacterMovementComponent::VerticalMove(float axis)
{
	UE_LOG(LogTemp, Warning, TEXT("VerticalMove is called"));
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

