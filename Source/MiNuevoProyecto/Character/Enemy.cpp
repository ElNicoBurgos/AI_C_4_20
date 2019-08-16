// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemy.h"
#include "ActorComponents/LifeComponent.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	lifeComponent = CreateDefaultSubobject<ULifeComponent>("LifeComponent");
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
TArray<class ATargetPoint*> AEnemy::getWayPoints() {
	return wayPoints;
}

//void AEnemy::hasDamageable(FName boneName, float currentDamage) {
//	
//	lifeComponent->TakeDamage(boneName,currentDamage);
//}
void AEnemy::hasDamageable(float currentDamage) {

	lifeComponent->TakeDamage(currentDamage);
}

