// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameManagerTest.generated.h"

/**
 * 
 */
UCLASS()
class COLLISION_API AGameManagerTest : public AGameModeBase
{
	GENERATED_BODY()
	virtual void BeginPlay();
	void TActor();
	void FActor();
	void TObject();
	class APushMan* PushMan;
};


