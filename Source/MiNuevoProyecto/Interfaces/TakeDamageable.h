// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "TakeDamageable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UTakeDamageable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MINUEVOPROYECTO_API ITakeDamageable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	
	//virtual void hasDamageable(FName boneName, float currentDamage) = 0;
	virtual void hasDamageable(float currentDamage) = 0;
};
