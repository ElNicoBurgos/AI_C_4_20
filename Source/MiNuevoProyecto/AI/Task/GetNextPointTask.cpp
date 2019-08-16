// Fill out your copyright notice in the Description page of Project Settings.

#include "GetNextPointTask.h"
#include "Interfaces/wayPointsInterfaces.h"
#include "AIController.h"
#include "Engine/TargetPoint.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UGetNextPointTask::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8* NodeMemory) {
	AAIController* aiController = Cast<AAIController>(OwnerComp.GetOwner());
	if (!aiController) return EBTNodeResult::Failed;
	IwayPointsInterfaces* patrolOBject = Cast<IwayPointsInterfaces>(aiController->GetPawn());
	if (!patrolOBject) return EBTNodeResult::Failed;

	TArray <ATargetPoint*> wayPoints = patrolOBject->getWayPoints();
	FNextPointData* data = (FNextPointData *)NodeMemory;
	data->currentIndex++;
	if (data->currentIndex < 0 || data->currentIndex >= wayPoints.Num())
		data->currentIndex = 0;
	ATargetPoint* currentWaypoint = wayPoints[data->currentIndex];
	UBlackboardComponent* blackboard = OwnerComp.GetBlackboardComponent();

	blackboard->SetValueAsVector(bbTargetPoint.SelectedKeyName, currentWaypoint->GetActorLocation());
	return EBTNodeResult::Succeeded;

}
uint16 UGetNextPointTask::GetInstanceMemorySize() const {
	return sizeof(FNextPointData);
}