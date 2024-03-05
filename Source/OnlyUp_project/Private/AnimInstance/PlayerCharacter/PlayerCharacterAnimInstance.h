
#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "PlayerCharacterAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class UPlayerCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

protected:
	// 현재 캐릭터에 적용된 현재 속도를 나타냅니다.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float CurrentSpeed;

	// 현재 캐릭터가 지상 위에 있음을 나타냅니다.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool IsGrounded;



public:
	void SetCurrentSpeed(float speed);
	void SetGroundState(bool isground);
	
	
};
