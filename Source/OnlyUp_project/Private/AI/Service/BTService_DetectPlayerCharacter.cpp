#include "AI/Service/BTService_DetectPlayerCharacter.h"

#include "Actor/GameCharacter/GameCharacter.h"

#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

#include "Kismet/KismetSystemLibrary.h"


UBTService_DetectPlayerCharacter::UBTService_DetectPlayerCharacter()
{
	IsAttackRequestedKey.AddBoolFilter(this, GET_MEMBER_NAME_CHECKED(ThisClass, IsAttackRequestedKey));

	IsDetected = false;
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

	static FVector currentLocation = ownerController->GetPawn()->GetActorLocation();

	// 충돌 타입 배열
	TArray<TEnumAsByte<EObjectTypeQuery>> objectTypeQuery;
	// IgnoreActorArray
	TArray<AActor*> actorsToIgnore;
	// ResultArray
	TArray<AActor*> detectedActors;


	// 구 반지름
	float radius = 1000.0f;


	if (UKismetSystemLibrary::SphereOverlapActors(ownerComponent.GetOwner(),
		currentLocation, radius,
		objectTypeQuery,
		AGameCharacter::StaticClass(),
		actorsToIgnore, detectedActors))
	{
		for (AActor* player : detectedActors)
		{
			IsDetected = true;

			// 공격 요청
			blackboardComponent->SetValueAsBool(IsAttackRequestedKey.SelectedKeyName, true);

			// 플레이어 위치 확인
			FVector playerLocation = player->GetActorLocation();
			
			playerLocation.Z = 0.0f;

			// 대포의 앞 방향 벡터 
			FVector cannonRightVec = ownerController->GetPawn()->GetActorRightVector();
			cannonRightVec.Z = 0.0f;
			//UE_LOG(LogTemp, Warning, TEXT("cannonRightVec.X = [%.2f]"), cannonForwardVec.X);
			//UE_LOG(LogTemp, Warning, TEXT("cannonRightVec.Y = [%.2f]"), cannonForwardVec.Y);

			// 대포에서 플레이어를 바라보는 방향 벡터
			FVector cannonToPlayerVec = playerLocation - currentLocation;
			cannonToPlayerVec.Z = 0.0f;
			cannonToPlayerVec = cannonToPlayerVec.GetSafeNormal();

			float angle = FMath::RadiansToDegrees(
				FMathf::ACos(FVector::DotProduct(cannonRightVec, cannonToPlayerVec)));

			
			 
		
			//UE_LOG(LogTemp, Warning, TEXT("angle is %.2f"), angle);

			if (IsDetected)
			{
				FRotator cannonRotation = ownerController->GetPawn()->GetActorRotation();
				UE_LOG(LogTemp, Warning, TEXT("cannonRotation is %.2f"), cannonRotation.Yaw);

				if (cannonRotation.Yaw < angle)
				{
					//while (true)
					//{
					//	cannonRotation.Yaw += 0.1f;
					//	//cannonRotation.Yaw = -angle;
					//	ownerController->GetPawn()->SetActorRotation(cannonRotation);
					//	IsDetected = false;
					//	if (angle == cannonRotation.Yaw)
					//		break;
					//}
				}
				
			}
			

			//UE_LOG(LogTemp, Warning, TEXT("Player is Detected!!"));

		}

	}


}
