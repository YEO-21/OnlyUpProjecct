#include "Components/CannonBombInteractComponent/CannonBombInteractComponent.h"

#include "Actor/GameCharacter/GameCharacter.h"


UCannonBombInteractComponent::UCannonBombInteractComponent()
{
	OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnBeginOverlap);


}

void UCannonBombInteractComponent::OnBeginOverlap(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	AGameCharacter* gameCharacter = Cast<AGameCharacter>(OtherActor);
	UE_LOG(LogTemp, Warning, TEXT("gameCharacter is valid %d"), IsValid(gameCharacter));

	if (!IsValid(gameCharacter)) return;


	UE_LOG(LogTemp, Warning, TEXT("BombAttack is called!"));
	FVector playerforwardvector = gameCharacter->GetActorForwardVector();
	playerforwardvector.Z = 0.0f;
	playerforwardvector *= 2000.0f;

	gameCharacter->LaunchCharacter(playerforwardvector, true, false);

}
