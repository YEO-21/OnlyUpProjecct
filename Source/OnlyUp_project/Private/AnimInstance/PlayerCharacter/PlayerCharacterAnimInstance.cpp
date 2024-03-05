// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstance/PlayerCharacter/PlayerCharacterAnimInstance.h"

void UPlayerCharacterAnimInstance::SetCurrentSpeed(float speed)
{
	CurrentSpeed = speed;
}

void UPlayerCharacterAnimInstance::SetGroundState(bool isgrounded)
{
	IsGrounded = isgrounded;
}
