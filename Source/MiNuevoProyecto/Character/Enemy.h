// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Engine/TargetPoint.h"
#include "Interfaces/wayPointsInterfaces.h"
#include "Interfaces/TakeDamageable.h"
#include "ActorComponents/LifeComponent.h"
#include "Enemy.generated.h"

UCLASS()
class MINUEVOPROYECTO_API AEnemy : public ACharacter, public IwayPointsInterfaces, public ITakeDamageable
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere) TArray<class ATargetPoint*> wayPoints;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite) class ULifeComponent* lifeComponent;
	TArray<class ATargetPoint*> getWayPoints() override;
	
	//void hasDamageable(FName boneName, float currentDamage) override;
	void hasDamageable(float currentDamage) override;
};
