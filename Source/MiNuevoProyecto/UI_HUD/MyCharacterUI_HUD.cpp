// Fill out your copyright notice in the Description page of Project Settings.

#include "MyCharacterUI_HUD.h"
#include "MiNuevoProyectoGameModeBase.h"
#include "Engine/World.h"



void UMyCharacterUI_HUD::NativeConstruct() {
	Super::NativeConstruct();

	AGameModeBase* gameModeBase = GetWorld()->GetAuthGameMode();
	if (gameModeBase)
		myGameMode = Cast<AMiNuevoProyectoGameModeBase>(gameModeBase);
	
}

void UMyCharacterUI_HUD::NativeTick(const FGeometry& MyGeometry, float InDeltaTime){
	Super::NativeTick(MyGeometry,InDeltaTime);
}