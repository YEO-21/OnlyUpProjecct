#include "Components/CannonBombInteractComponent/CannonBombInteractComponent.h"

#include "Actor/GameCharacter/GameCharacter.h"


UCannonBombInteractComponent::UCannonBombInteractComponent()
{
	OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnBeginOverlap);
	OnComponentEndOverlap.AddDynamic(this, &ThisClass::OnEndOverlap);


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

	
	if (HitPlayers.Num() == 0)
	{
		HitPlayers.Add(gameCharacter);
		

		++HitCount;
		UE_LOG(LogTemp, Warning, TEXT("HitCount = %d"), HitCount);

		FVector playerforwardvector = gameCharacter->GetActorForwardVector();
		playerforwardvector.Z = 0.0f;
		playerforwardvector *= 2000.0f;
		gameCharacter->LaunchCharacter(playerforwardvector * -1.0f, true, false);

		if (HitCount == MAXHITCOUNT)
			gameCharacter->PlayRagDoll();
		
	}

	

	
}

void UCannonBombInteractComponent::OnEndOverlap(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
	AGameCharacter* gameCharacter = Cast<AGameCharacter>(OtherActor);
	UE_LOG(LogTemp, Warning, TEXT("gameCharacter is valid %d"), IsValid(gameCharacter));

	if (!IsValid(gameCharacter)) return;

	if (HitPlayers.Num() != 0)
		HitPlayers.Empty();

}
