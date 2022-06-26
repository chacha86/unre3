// Fill out your copyright notice in the Description page of Project Settings.


#include "GameManager.h"
#include "PushMan.h"
#include "ChangeColorActor.h"
#include "MyUtil.h"
#include "Runtime/Engine/Public/EngineUtils.h"
#include "Kismet/GameplayStatics.h"
AGameManager::AGameManager()
{
	DefaultPawnClass = APushMan::StaticClass();
}
void AGameManager::BeginPlay()
{
//	Super::BeginPlay();
//	int32 i = 0;
//	for(const auto& man : TActorRange<APushMan>(GetWorld()))
//	{
//		if (man) {
//			LOG("%s", *man->GetName());
//			LOG("%d", i);
//			PushMan = man;
//			i++;
//		}
//	}
//
//	if (PushMan)
//	{
//		APlayerController* con = UGameplayStatics::GetPlayerController(this, 0);
//		LOG("%p", con);
//		if (con)
//		{
//			con->Possess(PushMan);
//		}
//	}
//
}
//
//void AGameManager::CollisionTestDo(AActor* actor1, AActor* actor2)
//{
//	LOG("colli start");
////	if (actor1) {
////		Cast<APushMan>(actor1)->ChangeMesh();
////	}
////
//	if (actor2) {
//		Cast<AChangeColorActor>(actor2)->ChangeColor();
//	}
//	LOG("colli end");
//}
//