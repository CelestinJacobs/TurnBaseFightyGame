// Fill out your copyright notice in the Description page of Project Settings.

#include "FirstCharacter.h"
#include "Components/StaticMeshComponent.h"
#include "Components/WidgetComponent.h"


// Sets default values
AFirstCharacter::AFirstCharacter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;
	
	FirstCharacterAMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FirstCharacterAMesh"));
	FirstCharacterAMesh->AttachTo(RootComponent);
	
	Health = 50;
	Damage = 5;
	PlayerTurn = true;
}

// Called when the game starts or when spawned
void AFirstCharacter::BeginPlay()
{
	Super::BeginPlay();

	for (AEnemy* enemy : this->enemy_list) {
		enemy->player = this;
	}
	
	
}

// Called every frame
void AFirstCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	if (this->widget) {
		if (PlayerTurn) {
			this->widget->SetVisibility(ESlateVisibility::Visible);
		}
		else {
			this->widget->SetVisibility(ESlateVisibility::Hidden);
		}
	}
}


void AFirstCharacter::AttackButtonMade()
{
	if (this->widget)
	{
		this->widget->OnAttackButtonPressed.AddDynamic(this, &AFirstCharacter::Attack);
	}
}



//this function will be called when someone presses a button in the UI!
void AFirstCharacter::Attack()
{

	//have we selected anyone?
	bool selected = false;
	for (AEnemy* enemy : this->enemy_list)
	{
		if (enemy->IsTargeted)
		{
			current_target = enemy;
			selected = true;
			break;
		}
	}

	if(!selected)
	{
		UE_LOG(LogTemp, Log, TEXT("pick a target!!"));
		return;
	}
	else
	{
		//attack the enemy we have selected.
		UE_LOG(LogTemp, Log, TEXT("before %d"), current_target->Health);
		current_target->Health -= this->Damage;
		current_target->IsTargeted = false;
		if(current_target->Health <= 0)
		{
			UE_LOG(LogTemp, Log, TEXT("Target Eliminated!"));
			current_target->Destroy();
		}

		UE_LOG(LogTemp, Log, TEXT("after %d"), current_target->Health);
		PlayerTurn = false;


		//TODO: select who's turn it is next? because it's not the players anymore. 
		this->enemy_list[0]->EnemyTurn = true;

		//maybe check if they is ded?
	}
}

void AFirstCharacter::EndTurn()
{
	/*if (PlayerTurn = false)
	{
		AEnemy->EnemyTurn = true
	}*/
}

