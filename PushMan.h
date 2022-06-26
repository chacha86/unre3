// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PushMan.generated.h"

UCLASS()
class COLLISION_API APushMan : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APushMan();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
private:

	virtual void NotifyHit(
    class UPrimitiveComponent * MyComp,
    AActor * Other,
    class UPrimitiveComponent * OtherComp,
    bool bSelfMoved,
    FVector HitLocation,
    FVector HitNormal,
    FVector NormalImpulse,
    const FHitResult & Hit
);
	

	class UMyCharacterMovementComponent* MyMovement;
	UPROPERTY(EditAnywhere)
	class UCameraComponent* Camera;
	UPROPERTY(EditAnywhere)
	class USpringArmComponent* SpringArm;
	class AGameManager* manager;
	void PushBox(AActor* Box);
	void CollisionCheck();
	void MoveToVertical(float val);
	void MoveToHorizontal(float val);
	void Turn(float val);
   UPROPERTY(EditAnywhere)
    float AttackRange;

    UPROPERTY(EditAnywhere)
    float AttackRadius;
public:
	void ChangeMesh();

};
