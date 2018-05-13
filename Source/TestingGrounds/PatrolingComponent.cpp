// Fill out your copyright notice in the Description page of Project Settings.

#include "PatrolingComponent.h"

TArray<ATargetPoint*> UPatrolingComponent::GetPatrolPoints() const 
{
	return PatrolPoints;
}