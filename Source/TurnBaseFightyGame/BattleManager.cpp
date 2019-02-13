// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleManager.h"


// Sets default values
ABattleManager::ABattleManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TurnCount = 0;
}

// Called when the game starts or when spawned
void ABattleManager::BeginPlay()
{
	Super::BeginPlay();
	

	StartTurn();
}

// Called every frame
void ABattleManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (this->Player->PlayerTurn == false) {
		NextTurn();
		UE_LOG(LogTemp, Log, TEXT("Next Turn"));
	}
	
	//play a countdown or start animation?!?!?!
}

void ABattleManager::StartTurn()
{
	if (TurnCount % 4 == 0) {
		this->Player->PlayerTurn = true;
		this->Player->PlayerTurnFinished = false;
		UE_LOG(LogTemp, Log, TEXT("Turn Count %d"), TurnCount);
	}
}

void ABattleManager::NextTurn()
{
	if (this->Player->PlayerTurnFinished) {
		TurnCount++;
		UE_LOG(LogTemp, Log, TEXT("Turn Count %d"), TurnCount);
	}


	int turn_mod = TurnCount % 4;
	if (turn_mod == 0) {
		//its the players go!
	}
	else {
		//this is the enemies go.
		//the enemies turn is decided by looking at the current turn count 
		// TurnCount % 4 - 1  = 0,1,2.
		this->enemy_list[turn_mod - 1]->EnemyTurn = true;
		this->enemy_list[turn_mod - 1]->EnemyTurnFinished = false;
		this->enemy_list[turn_mod - 1]->EnemyAttackFinished = false;
		this->enemy_list[turn_mod - 1]->EnemyAttack();
	}
	
	if (this->enemy_list[turn_mod - 1]->EnemyTurnFinished) {
		TurnCount++;
		}
}


