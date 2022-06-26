// Fill out your copyright notice in the Description page of Project Settings.


#include "GameManagerTest.h"
#include "PushMan.h"
#include "MyUtil.h"
#include "Runtime/Engine/Public/EngineUtils.h"
void AGameManagerTest::BeginPlay()
{
	Super::BeginPlay();
	TActor();
	LOG("====================");
	FActor();
	LOG("====================");
	TObject();
}
void AGameManagerTest::TActor() {
	int32 i = 0;
	TActorRange<ACharacter> range = TActorRange<ACharacter>(GetWorld());
	for (const auto& man : range)
	{
		if (man) {
			LOG("%s", *man->GetName());
			LOG("%d", i);
			//PushMan = man;
			i++;
		}
	}
}
void AGameManagerTest::FActor() {
	int32 i = 0;

	for (const auto& man : FActorRange(GetWorld()))
	{
		if (man) {
			LOG("%s", *man->GetName());
			LOG("%d", i);
			//PushMan = man;
			i++;
		}
	}
}
void AGameManagerTest::TObject() {
	int32 i = 0;

	for (const auto& man : TObjectRange<ACharacter>())
	{
		if (man) {
			LOG("%s", *man->GetName());
			LOG("%d", i);
			//PushMan = man;
			i++;
		}
	}
}