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


	//play a countdown or start animation?!?!?!
}

void ABattleManager::StartTurn()
{
	if (TurnCount % 4 == 0) {
		this->Player->PlayerTurn = true;
		this->Player->PlayerTurnFinished = false;
	}
		
}

void ABattleManager::NextTurn()
{
	if (this->Player->PlayerTurnFinished) {
		TurnCount++;
	}
	if (TurnCount % 4 != 0) {

		//TurnCount % 4 != 0 => 0,1,2,3. 0 is players go, 1,2,3 is enemies go.
		//TurnCount % 4 - 1 => -1,0,1,2

		this->Player->enemy_list[0]->EnemyTurn = true;
	}

}


