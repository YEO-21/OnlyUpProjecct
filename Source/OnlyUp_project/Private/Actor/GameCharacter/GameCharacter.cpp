#include "Actor/GameCharacter/GameCharacter.h"

#include "Components/PlayerCharacterMovementComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"

AGameCharacter::AGameCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	// �̵� ������Ʈ �߰�
	MovementComponent = CreateDefaultSubobject<UPlayerCharacterMovementComponent>(
		TEXT("MOVEMENT_COMP"));

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(
		TEXT("CAMERA_COMP"));

	// ��Ʈ�ѷ� Yaw ȸ�� ��� X
	bUseControllerRotationYaw = false;

	// �����Ʈ �������� ȸ�� ���
	GetCharacterMovement()->bOrientRotationToMovement = true;

	// ȸ�� �ӵ� ����
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 450.f, 0.0f);




}

void AGameCharacter::OnHorizontalInput(float axis)
{
	MovementComponent->HorizontalMove(axis);
}

void AGameCharacter::OnVerticalInput(float axis)
{
	MovementComponent->VerticalMove(axis);
}

void AGameCharacter::OnJumpInput()
{
	MovementComponent->OnJump();
}

void AGameCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGameCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGameCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

