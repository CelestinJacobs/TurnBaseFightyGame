// Fill out your copyright notice in the Description page of Project Settings.

#include "FirstCharacter.h"
#include "Components/StaticMeshComponent.h"
#include "Components/WidgetComponent.h"


// Sets default values
AFirstCharacter::AFirstCharacter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FirstCharacterAMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FirstCharacterAMesh"));
	FirstCharacterAMesh->AttachTo(Root);
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;
	Health = 50;
	Damage = 5;
}

// Called when the game starts or when spawned
void AFirstCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFirstCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFirstCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AFirstCharacter::Attack()
{
	if(AttackButton.event.OnClicked == true)
}