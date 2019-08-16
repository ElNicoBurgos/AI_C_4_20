// Fill out your copyright notice in the Description page of Project Settings.

#include "Coins.h"
#include "Character/MyCharacter.h"

// Sets default values
ACoins::ACoins()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACoins::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &ACoins::OnOverlap);
}

// Called every frame
void ACoins::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACoins::OnOverlap(AActor* me, AActor* other) {
	AMyCharacter* myCharacter = Cast<AMyCharacter>(other);
	if (myCharacter){
		me->Destroy();
	}
		
}