#include "Actor/GameCharacter/GameCharacter.h"

#include "Components/PlayerCharacterMovementComponent/PlayerCharacterMovementComponent.h"
#include "Components/ZoomableSpringArmComponent/ZoomableSpringArmComponent.h"

#include "AnimInstance/PlayerCharacter/PlayerCharacterAnimInstance.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"

AGameCharacter::AGameCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_PLAYER_MESH(
		TEXT("/Script/Engine.SkeletalMesh'/Game/Resources/PlayerCharacter/Mesh/character.character'"));


	static ConstructorHelpers::FClassFinder<UPlayerCharacterAnimInstance> ANIMBP_PLAYER_CHARACTER(
		TEXT("/Script/Engine.AnimBlueprint'/Game/Blueprints/Anim/AnimBP_PlayerCharacter.AnimBP_PlayerCharacter_C'"));

	if (SK_PLAYER_MESH.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SK_PLAYER_MESH.Object);
		GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -88.0f),
			FRotator(0.0f, -90.f, 0.0f));
	}

	if (ANIMBP_PLAYER_CHARACTER.Succeeded())
	{
		GetMesh()->SetAnimClass(ANIMBP_PLAYER_CHARACTER.Class);
	}



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

	GetCharacterMovement()->MaxWalkSpeed = 300.0f;


}

void AGameCharacter::BeginPlay()
{
	Super::BeginPlay();

	

}

void AGameCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateAnimParams();
}

void AGameCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

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

void AGameCharacter::OnAccerlationInput()
{
	GetCharacterMovement()->MaxWalkSpeed = 600.0f;
}

void AGameCharacter::OnWalkInput()
{
	GetCharacterMovement()->MaxWalkSpeed = 300.0f;
}

void AGameCharacter::OnZoomCamera(float axis)
{
	SpringArmComponent->DoZoomInOut(axis);
}

void AGameCharacter::UpdateAnimParams()
{
	UPlayerCharacterAnimInstance* animInst = Cast<UPlayerCharacterAnimInstance>(GetMesh()->GetAnimInstance());
	if (!IsValid(animInst))
	{
		UE_LOG(LogTemp, Warning, TEXT("animInst is not valid"));
		return;
	}

	FVector Velocity = GetVelocity();
	Velocity.Z = 0.0f;
	float speed = Velocity.Length();
	UE_LOG(LogTemp, Warning, TEXT("speed = %f"), speed);
	animInst->SetCurrentSpeed(speed);

	bool IsOnGround = GetMovementComponent()->IsMovingOnGround();
	animInst->SetGroundState(IsOnGround);

	

}



