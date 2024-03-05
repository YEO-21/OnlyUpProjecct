#include "Actor/GameCharacter/GameCharacter.h"

#include "Components/PlayerCharacterMovementComponent/PlayerCharacterMovementComponent.h"
#include "Components/ZoomableSpringArmComponent/ZoomableSpringArmComponent.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"

AGameCharacter::AGameCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	// 이동 컴포넌트 추가
	MovementComponent = CreateDefaultSubobject<UPlayerCharacterMovementComponent>(
		TEXT("MOVEMENT_COMP"));

	SpringArmComponent = CreateDefaultSubobject<UZoomableSpringArmComponent>(
		TEXT("SPRINGARM_COMP"));

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(
		TEXT("CAMERA_COMP"));

	
	SpringArmComponent->SetupAttachment(GetRootComponent());
	CameraComponent->SetupAttachment(SpringArmComponent);



	// 컨트롤러 Yaw 회전 사용 X
	bUseControllerRotationYaw = false;

	// 무브먼트 방향으로 회전 사용
	GetCharacterMovement()->bOrientRotationToMovement = true;

	// 회전 속도 설정
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 450.f, 0.0f);

	SpringArmComponent->bUsePawnControlRotation = true;


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

void AGameCharacter::OnZoomCamera(float axis)
{
	SpringArmComponent->DoZoomInOut(axis);
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

