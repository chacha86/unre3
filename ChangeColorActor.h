// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ChangeColorActor.generated.h"

UCLASS()
class COLLISION_API AChangeColorActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChangeColorActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION()
	void ChangeColor();
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MeshComponent;
	UMaterialInstanceDynamic* MyMID;
	FVector OriginColor;
	FVector TargetColor;
	FVector CurrentColor;
};
