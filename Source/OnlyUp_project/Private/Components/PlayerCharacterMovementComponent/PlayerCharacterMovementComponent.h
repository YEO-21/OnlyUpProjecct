#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerCharacterMovementComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UPlayerCharacterMovementComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UPlayerCharacterMovementComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void HorizontalMove(float axis);
	void VerticalMove(float axis);
	void OnJump();

		
};
