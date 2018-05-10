// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWayPoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrollingGuard.h"

EBTNodeResult::Type UChooseNextWayPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) 
{
	auto AIController = OwnerComp.GetAIOwner();
	auto ControlledPawn = AIController->GetPawn();
	auto PatrollingGuard = Cast <APatrollingGuard>(ControlledPawn);
	auto PatrolPoints = PatrollingGuard->PatrolPoints;

	auto BlackboardComponent = OwnerComp.GetBlackboardComponent();
	auto index = BlackboardComponent->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackboardComponent->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[index]);

	auto NextWaypoint = (index + 1) % PatrolPoints.Num();
	BlackboardComponent->SetValueAsInt(IndexKey.SelectedKeyName, NextWaypoint);


	//UE_LOG(LogTemp, Warning, TEXT("Index: %i"), index);

	return EBTNodeResult::Succeeded;
}

void UChooseNextWayPoint::GetPatrolPoints()
{
}

void UChooseNextWayPoint::SetNextWaypoint()
{
}

void UChooseNextWayPoint::CycleWaypoints()
{
}
