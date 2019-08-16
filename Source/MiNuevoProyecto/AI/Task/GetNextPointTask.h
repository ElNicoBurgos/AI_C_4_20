// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "GetNextPointTask.generated.h"

/**
 * 
 */
struct FNextPointData {
	int currentIndex = -1;
};
UCLASS()
class MINUEVOPROYECTO_API UGetNextPointTask : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
protected:

	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8* NodeMemory) override;
	
public:
	UPROPERTY(EditAnywhere) FBlackboardKeySelector bbTargetPoint;
	uint16 GetInstanceMemorySize() const override;

	
};
