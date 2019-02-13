
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FirstCharacter.h"
#include "GameFramework/Pawn.h"
#include "Enemy.generated.h"

UCLASS()
class TURNBASEFIGHTYGAME_API AEnemy : public APawn
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
		USceneComponent * Root;


	UPROPERTY()
		class AFirstCharacter* player;

	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* FirstCharacterAMesh;

	UPROPERTY(VisibleAnywhere)
		int Health;

	UPROPERTY(VisibleAnywhere)
		int Damage;

	UPROPERTY(VisibleAnywhere)
		bool IsTargeted;

	UFUNCTION()
		void Targeted(AActor* TouchedActor, FKey ButtonPressed);

	UPROPERTY(VisibleAnywhere)
		bool AmDead;

	//UFUNCTION(BlueprintCallable)
		//void Dead(AFirstCharacter* Attack);

	UPROPERTY(VisibleAnywhere)
		bool EnemyTurn;

	UFUNCTION()
		void EnemyAttack();

	UPROPERTY()
		bool EnemyAttackFinished;

	UPROPERTY()
		bool EnemyTurnFinished;

	UFUNCTION()
		void EnemyEndTurn();

	



};
