
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
	// ���� ĳ���Ϳ� ����� ���� �ӵ��� ��Ÿ���ϴ�.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float CurrentSpeed;

	// ���� ĳ���Ͱ� ���� ���� ������ ��Ÿ���ϴ�.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool IsGrounded;



public:
	void SetCurrentSpeed(float speed);
	void SetGroundState(bool isground);
	
	
};
