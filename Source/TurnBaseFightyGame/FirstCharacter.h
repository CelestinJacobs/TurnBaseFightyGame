// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
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

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Attack();

	UPROPERTY()
	USceneComponent* Root;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* FirstCharacterAMesh;

	UPROPERTY(VisibleAnywhere)
	int Health;

	UPROPERTY(VisibleAnywhere)
	int Damage;

	UPROPERTY(VisibleAnywhere)
		UWidgetComponent* AttackButton;
	
	
};
