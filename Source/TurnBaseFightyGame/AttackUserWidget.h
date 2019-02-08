// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AttackUserWidget.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAtackButtonDelegate);


UCLASS()
class TURNBASEFIGHTYGAME_API UAttackUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintCallable, Category = "AttackButton")
	FAtackButtonDelegate OnAttackButtonPressed;

};
