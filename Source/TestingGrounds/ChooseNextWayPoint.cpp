// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWayPoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrolingComponent.h"

EBTNodeResult::Type UChooseNextWayPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) 
{
	auto AIController = OwnerComp.GetAIOwner();
	auto ControlledPawn = AIController->GetPawn();
	auto PatrollingComponent = ControlledPawn->FindComponentByClass<UPatrolingComponent>();
	if (!ensure(PatrollingComponent)) { return EBTNodeResult::Failed; }

	auto PatrolPoints = PatrollingComponent->GetPatrolPoints();
	if (PatrolPoints.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("No PartrolPoints"));
		return EBTNodeResult::Failed;
	}

	auto BlackboardComponent = OwnerComp.GetBlackboardComponent();
	auto index = BlackboardComponent->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackboardComponent->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[index]);

	auto NextWaypoint = (index + 1) % PatrolPoints.Num();
	BlackboardComponent->SetValueAsInt(IndexKey.SelectedKeyName, NextWaypoint);

	return EBTNodeResult::Succeeded;
}