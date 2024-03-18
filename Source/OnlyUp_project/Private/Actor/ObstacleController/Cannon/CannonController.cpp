#include "Actor/ObstacleController/Cannon/CannonController.h"
#include "Actor/GameCharacter/GameCharacter.h"


#include "BehaviorTree/BlackboardComponent.h"

void ACannonController::SetPlayerCharacterKey(AGameCharacter* gameCharacter)
{
	BlackboardComponent->SetValueAsObject(TEXT("TargetActor"), gameCharacter);
}
