// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameManager.generated.h"

/**
 * 
 */
UCLASS()
class COLLISION_API AGameManager : public AGameModeBase
{
	GENERATED_BODY()
	virtual void BeginPlay();
	AGameManager();
	class APushMan* PushMan;
public:
	void CollisionTestDo(AActor* actor1, AActor* actor2);

};

