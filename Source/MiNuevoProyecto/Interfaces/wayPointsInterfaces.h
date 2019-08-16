// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Engine/TargetPoint.h"
#include "wayPointsInterfaces.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UwayPointsInterfaces : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MINUEVOPROYECTO_API IwayPointsInterfaces
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	
	virtual TArray<class ATargetPoint*> getWayPoints() = 0;
};
