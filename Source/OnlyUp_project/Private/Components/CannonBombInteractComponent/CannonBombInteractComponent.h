// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "CannonBombInteractComponent.generated.h"

/**
 * 
 */
#define MAXHITCOUNT				3

UCLASS()
class UCannonBombInteractComponent : public USphereComponent
{
	GENERATED_BODY()

private:
	UPROPERTY()
	int HitCount;

	UPROPERTY()
	TArray<class AGameCharacter*> HitPlayers;

	

public:
	UCannonBombInteractComponent();


private:
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

	UFUNCTION()
	void OnEndOverlap(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);


	
};
