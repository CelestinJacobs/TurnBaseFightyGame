// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Enemy.h"
#include "AttackUserWidget.h"




#include "FirstCharacter.generated.h"



UCLASS()
class TURNBASEFIGHTYGAME_API AFirstCharacter : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AFirstCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void Attack();

	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	USceneComponent * Root;


	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* FirstCharacterAMesh;

	UPROPERTY(VisibleAnywhere)
	int Health;

	UPROPERTY(VisibleAnywhere)
	int Damage;


	UPROPERTY(EditAnywhere)
	TArray<AEnemy*> enemy_list;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UAttackUserWidget* widget;


	UFUNCTION(BlueprintCallable)
	void AttackButtonMade();

	
};
