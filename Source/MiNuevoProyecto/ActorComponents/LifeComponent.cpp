// Fill out your copyright notice in the Description page of Project Settings.

#include "LifeComponent.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
ULifeComponent::ULifeComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void ULifeComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void ULifeComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

//void ULifeComponent::TakeDamage(FName boneName, float currentDamage) {
//	if (listDamage.Contains(boneName)) {
//		float damagePercent = listDamage[boneName];
//		float totalDamage = damagePercent * currentDamage;
//		if ((lifeCurrent - totalDamage) < 0)
//			GetOwner()->Destroy();
//		else
//			lifeCurrent -= totalDamage;
//	}
//}
void ULifeComponent::TakeDamage( float currentDamage) {
	
	
		if ((lifeCurrent - currentDamage) < 0)
			GetOwner()->Destroy();
		else
			lifeCurrent -= currentDamage;
	
}