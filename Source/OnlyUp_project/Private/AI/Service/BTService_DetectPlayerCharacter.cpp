#include "AI/Service/BTService_DetectPlayerCharacter.h"

#include "Actor/GameCharacter/GameCharacter.h"

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

	// ���� ����
	CheckArea(ownerComponent);
}

void UBTService_DetectPlayerCharacter::CheckArea(UBehaviorTreeComponent& ownerComponent)
{
	// Get Controller
	AController* ownerController = Cast<AController>(ownerComponent.GetOwner());
	// Get BlackboardComponent
	UBlackboardComponent* blackboardComponent = ownerComponent.GetBlackboardComponent();

	static FVector currentLocation = ownerController->GetPawn()->GetActorLocation();
	UE_LOG(LogTemp, Warning, TEXT("currentLocation is %.2f"), currentLocation.Y);

	// �浹 Ÿ�� �迭
	TArray<TEnumAsByte<EObjectTypeQuery>> objectTypeQuery;
	// IgnoreActorArray
	TArray<AActor*> actorsToIgnore;
	// ResultArray
	TArray<AActor*> detectedActors;


	// �� ������
	float radius = 100.0f;


	if (UKismetSystemLibrary::SphereOverlapActors(ownerComponent.GetOwner(),
		currentLocation, radius,
		objectTypeQuery,
		AGameCharacter::StaticClass(),
		actorsToIgnore, detectedActors))
	{
		for (AActor* player : detectedActors)
		{
			// ���� ��û
			blackboardComponent->SetValueAsBool(IsAttackRequestedKey.SelectedKeyName, true);

		}

	}


}
