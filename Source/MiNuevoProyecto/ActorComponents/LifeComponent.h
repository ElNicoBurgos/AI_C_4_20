// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LifeComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MINUEVOPROYECTO_API ULifeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ULifeComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float lifeMax = 100.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float lifeCurrent = 100.f;
	UPROPERTY(EditAnywhere) TMap<FName, float> listDamage;
//	void TakeDamage(FName boneName, float currentDamage);
	void TakeDamage(float currentDamage);
};
