#pragma once

#include "CoreMinimal.h"
#include "Actor/ObstacleController/ObstacleController.h"
#include "CannonController.generated.h"

/**
 * 
 */
UCLASS()
class ACannonController : public AObstacleController
{
	GENERATED_BODY()

public:
	void SetPlayerCharacterKey(class AGameCharacter* gameCharacter);
	
};
