// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FirstCharacter.h"

#include "BattleManager.generated.h"


UCLASS()
class TURNBASEFIGHTYGAME_API ABattleManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABattleManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
		int TurnCount;

	UPROPERTY(EditAnywhere)
		TArray<class AEnemy*> enemy_list;

	UPROPERTY(EditAnywhere)
		AFirstCharacter *Player;

	UFUNCTION()
		void StartTurn();

	UFUNCTION()
		void NextTurn();
	
};
