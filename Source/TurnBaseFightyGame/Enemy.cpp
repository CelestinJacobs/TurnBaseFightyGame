// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemy.h"


// Sets default values
AEnemy::AEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	FirstCharacterAMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FirstCharacterAMesh"));
	FirstCharacterAMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);

	Health = 50;
	Damage = 5;
	IsTargeted = false;
	AmDead = false;
	EnemyTurn = false;
	EnemyAttackFinished = true;
	EnemyTurnFinished = true;
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();

	//we want to know when a player has clicked on us!
	this->OnClicked.AddDynamic(this, &AEnemy::Targeted); 
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEnemy::Targeted(AActor* TouchedActor, FKey ButtonPressed)
{
	UE_LOG(LogTemp, Log, TEXT("Targeted me!"));
	IsTargeted = true;
}

void AEnemy::EnemyAttack()
{
	UE_LOG(LogTemp, Log, TEXT("before %d"), player->Health);
	player->Health -= this->Damage;
	UE_LOG(LogTemp, Log, TEXT("after %d"), player->Health);
	EnemyAttackFinished = true;
}

void AEnemy::EnemyEndTurn()
{

	if (EnemyAttackFinished == true)
	{
		EnemyTurnFinished = true;
	}
}








/*
void AEnemy::Dead(AFirstCharacter * Attack)//(&AFirstCharacter::Attack)
{
	if (Health != 0)
	{
		AmDead = true;
		UE_LOG(LogTemp, Log, TEXT("Target Eliminated!"));
		current_target->Destroy();
		
	}
}*/
