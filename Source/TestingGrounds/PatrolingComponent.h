// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/Targetpoint.h"
#include "PatrolingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTINGGROUNDS_API UPatrolingComponent : public UActorComponent
{
	GENERATED_BODY()

public: 

	TArray<ATargetPoint*> GetPatrolPoints() const;

private:

	UPROPERTY(EditAnywhere, Category = "Patroling")
		TArray<ATargetPoint*> PatrolPoints;
};
