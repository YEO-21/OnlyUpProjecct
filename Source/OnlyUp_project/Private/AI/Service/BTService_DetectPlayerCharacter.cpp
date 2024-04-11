#include "AI/Service/BTService_DetectPlayerCharacter.h"

#include "Actor/GameCharacter/GameCharacter.h"
#include "Actor/ObstacleController/Cannon/CannonController.h"
#include "Actor/Obstacle/Pawn/Static/Cannon/ControlledCannon.h"

#include "Components/ObstacleAttackComponent/ObstacleAttackComponent.h"

#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

#include "Kismet/KismetSystemLibrary.h"


UBTService_DetectPlayerCharacter::UBTService_DetectPlayerCharacter()
{
	IsAttackRequestedKey.AddBoolFilter(this, GET_MEMBER_NAME_CHECKED(ThisClass, IsAttackRequestedKey));
}

void UBTService_DetectPlayerCharacter::TickNode(
	UBehaviorTreeComponent& ownerComponent,
	uint8* nodeMemory, float dt)
{
	Super::TickNode(ownerComponent, nodeMemory, dt);

	// 영역 감지
	CheckArea(ownerComponent);
}

void UBTService_DetectPlayerCharacter::CheckArea(UBehaviorTreeComponent& ownerComponent)
{
	// Get Controller
	AController* ownerController = Cast<AController>(ownerComponent.GetOwner());
	// Get BlackboardComponent
	UBlackboardComponent* blackboardComponent = ownerComponent.GetBlackboardComponent();

	AControlledCannon* controlledPawn = Cast<AControlledCannon>(ownerController->GetPawn());

	FVector currentLocation = ownerController->GetPawn()->GetActorLocation();

	// 충돌 타입 배열
	TArray<TEnumAsByte<EObjectTypeQuery>> objectTypeQuery;
	// IgnoreActorArray
	TArray<AActor*> actorsToIgnore;
	// ResultArray
	TArray<AActor*> detectedActors;


	// 구 반지름
	float radius = 8000.0f;


	if (UKismetSystemLibrary::SphereOverlapActors(ownerComponent.GetOwner(),
		currentLocation, radius,
		objectTypeQuery,
		AGameCharacter::StaticClass(),
		actorsToIgnore, detectedActors))
	{
		for (AActor* player : detectedActors)
		{

			// 공격 요청
			blackboardComponent->SetValueAsBool(IsAttackRequestedKey.SelectedKeyName, true);

			AGameCharacter* playercharacter = Cast<AGameCharacter>(player);

			// 감지된 객체가 플레이어로 인식함
			controlledPawn->OnPlayerCharacterDetected(playercharacter);

			controlledPawn->GetObstacleAttackComponent()->SetAttackRequested(true);

			//UE_LOG(LogTemp, Warning, TEXT("Player is Detected!"));
		}

	}
	else
	{
		blackboardComponent->SetValueAsBool(IsAttackRequestedKey.SelectedKeyName, false);
		//UE_LOG(LogTemp, Warning, TEXT("Player is not Detected!"));

	}


}
