
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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


	void Attack();

	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
		USceneComponent * Root;


	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* FirstCharacterAMesh;

	UPROPERTY(VisibleAnywhere)
		int Health;

	UPROPERTY(VisibleAnywhere)
		int Damage;

	UPROPERTY(VisibleAnywhere)
		bool IsTargeted;

	UFUNCTION()
		void Targeted(AActor* TouchedActor, FKey ButtonPressed);

};
