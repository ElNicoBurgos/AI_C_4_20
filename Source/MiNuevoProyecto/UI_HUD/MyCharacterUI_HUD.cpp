// Fill out your copyright notice in the Description page of Project Settings.

#include "MyCharacterUI_HUD.h"
#include "MiNuevoProyectoGameModeBase.h"
#include "Engine/World.h"
#include "Components/ProgressBar.h"
#include "Character/MyCharacter.h"


void UMyCharacterUI_HUD::NativeConstruct() {
	Super::NativeConstruct();

	AGameModeBase* gameModeBase = GetWorld()->GetAuthGameMode();
	if (gameModeBase)
		myGameMode = Cast<AMiNuevoProyectoGameModeBase>(gameModeBase);
		
	APawn* me = myGameMode->GetWorld()->GetFirstPlayerController()->GetPawn();

	if (me)
		myCharacter = Cast<AMyCharacter>(me);
	

}

void UMyCharacterUI_HUD::NativeTick(const FGeometry& MyGeometry, float InDeltaTime){
	Super::NativeTick(MyGeometry,InDeltaTime);
	if (myCharacter) {
		float valueLifeBar = (myCharacter->lifeCharacterCurrent) / myCharacter->lifeCharacter;
		healtBar->SetPercent(valueLifeBar);
	}
}