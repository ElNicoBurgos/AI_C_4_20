// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActorComponents/LifeComponent.h"
#include "GameFramework/Character.h"
#include "Components/CapsuleComponent.h"
#include "MyCharacter.generated.h"

UCLASS()
class MINUEVOPROYECTO_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	//, BlueprintReadWrite
	//UPROPERTY(VisibleAnywhere) class UArrowComponent* arrowComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite) class ULifeComponent* lifeComponent;

	UPROPERTY(VisibleAnywhere) class USpringArmComponent* cameraBoom;
	UPROPERTY(VisibleAnywhere) class UCameraComponent* followCamera;
	UPROPERTY(VisibleAnywhere) class USkeletalMeshComponent* character;
	UPROPERTY(VisibleAnywhere) class UStaticMeshComponent* sword;
	UPROPERTY(VisibleAnywhere) class UStaticMeshComponent* shield;
	UPROPERTY(VisibleAnywhere) class UCapsuleComponent* myCapsuleComponent;
	
	UPROPERTY(EditAnyWhere) float currentDamage = 30.f;
	/*FTimerHandle handleHit;
	void StartHitTimer();*/
	UPROPERTY(EditAnyWhere, BlueprintReadWrite) float lifeCharacter = 100.f;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite) float lifeCharacterCurrent = 100.f;

	AActor *hitActor;
	void MoveFoward(float value);
	void MoveRight(float value);
	/*void RotatePitch(float value);
	void RotateYaw(float value);*/
	void StartJump();
	void StopJump();
	void StartHit();
	void StopHit();

	UFUNCTION()
	void OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UPROPERTY(EditAnywhere, BlueprintReadWrite) bool isHit;
		
};
