// Fill out your copyright notice in the Description page of Project Settings.

#include "MyCharacter.h"
#include "ActorComponents/LifeComponent.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Interfaces/TakeDamageable.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "Components/CapsuleComponent.h"
#include "Engine/World.h"
#include "TimerManager.h"
// Sets default values
AMyCharacter::AMyCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0, 0, 540);
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	/*
	character->SetupAttachment(RootComponent);*/

	cameraBoom = CreateDefaultSubobject<USpringArmComponent>("CameraBoom");
	//cameraBoom->SetupAttachment(character);
	cameraBoom->SetupAttachment(RootComponent);
	cameraBoom->TargetArmLength = 350.f;
	cameraBoom->bUsePawnControlRotation = true;

	followCamera = CreateDefaultSubobject<UCameraComponent>("FollowCamera");
	followCamera->SetupAttachment(cameraBoom, USpringArmComponent::SocketName);
	followCamera->bUsePawnControlRotation = false;

	lifeComponent = CreateDefaultSubobject<ULifeComponent>("LifeComponent");

	character = CreateDefaultSubobject<USkeletalMeshComponent>("MyCharacter");
	character->SetupAttachment(RootComponent);


	sword = CreateDefaultSubobject<UStaticMeshComponent>("Sword");
	sword->SetupAttachment(character, "RightWeaponShield");

	myCapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>("MyCapsuleComponent");
	myCapsuleComponent->SetupAttachment(sword);

	shield = CreateDefaultSubobject<UStaticMeshComponent>("Shield");
	shield->SetupAttachment(character, "LeftWeaponShield");



}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();

	myCapsuleComponent->OnComponentHit.AddDynamic(this, &AMyCharacter::OnCompHit);
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Foward", this, &AMyCharacter::MoveFoward);
	PlayerInputComponent->BindAxis("Right", this, &AMyCharacter::MoveRight);
	PlayerInputComponent->BindAxis("LookUp", this, &AMyCharacter::AddControllerPitchInput);
	//PlayerInputComponent->BindAxis("LookUp", this, &AMyCharacter::RotatePitch);
	PlayerInputComponent->BindAxis("Turn", this, &AMyCharacter::AddControllerYawInput);
	//PlayerInputComponent->BindAxis("Turn", this, &AMyCharacter::RotateYaw);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMyCharacter::StartJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AMyCharacter::StopJump);
	PlayerInputComponent->BindAction("Hit", IE_Released, this, &AMyCharacter::StartHit);
	PlayerInputComponent->BindAction("Hit", IE_Released, this, &AMyCharacter::StopHit);
}

void AMyCharacter::MoveFoward(float value) {
	const FRotator rotation = GetControlRotation();
	const FRotator YawRotation(0, rotation.Yaw, 0);
	const FVector direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	AddMovementInput(direction, value);

}
void AMyCharacter::MoveRight(float value) {

	const FRotator rotation = GetControlRotation();
	const FRotator YawRotation(0, rotation.Yaw, 0);
	const FVector direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	AddMovementInput(direction, value);
	//AddMovementInput(GetActorRightVector(), value);		
}
//void AMyCharacter::RotatePitch(float value) {
//	AddControllerPitchInput(value);
//	//AddControllerPitchInput(value * GetWorld()->GetDeltaSeconds());
//}
//void AMyCharacter::RotateYaw(float value) {
//	AddControllerYawInput(value);
//	//AddControllerYawInput(value * GetWorld()->GetDeltaSeconds());
//}
void AMyCharacter::StartJump() {
	Jump();
}
void AMyCharacter::StopJump() {
	StopJumping();
}
void AMyCharacter::StartHit() {
	//GetWorldTimerManager().SetTimer(handleHit, this, &AMyCharacter::StartHitTimer, 1, true);
	UE_LOG(LogTemp, Warning, TEXT("Golpie"));
	isHit = true;
	//ITakeDamageable* isDamageable = Cast<ITakeDamageable>(hitActor);
	//if (isDamageable)
	//	isDamageable->hasDamageable(currentDamage);
}
void AMyCharacter::StopHit() {
	//GetWorldTimerManager().ClearTimer(handleHit);
	UE_LOG(LogTemp, Warning, TEXT("Termine de golpear"));
	//isHit = false;
}

//void AMyCharacter::StartHitTimer() {
//	isHit = true;
//	//UE_LOG(LogTemp, Warning, TEXT("Golpie"));
//	//isHit = true;
//	/*ITakeDamageable* isDamageable = Cast<ITakeDamageable>(hitActor);
//	if (isDamageable)
//		isDamageable->hasDamageable(currentDamage);*/
//}

void AMyCharacter::OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL) && isHit)
	{
		UE_LOG(LogTemp, Warning, TEXT("OtherActor is: %s"), *OtherActor->GetName());
		UE_LOG(LogTemp, Warning, TEXT("HitComp is: %s"), *HitComp->GetName());
		hitActor = OtherActor;
		ITakeDamageable* isDamageable = Cast<ITakeDamageable>(hitActor);
		if (isDamageable)
			isDamageable->hasDamageable(currentDamage);
		isHit = false;
	}
}