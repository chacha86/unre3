// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"
#include "GameFramework/FloatingPawnMovement.h"
// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComp"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> sm(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_NarrowCapsule.Shape_NarrowCapsule'"));
	movement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("hihi"));
	RootComponent = StaticMesh;
	if (sm.Succeeded())
	{
		StaticMesh->SetStaticMesh(sm.Object);
	}	
}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("Vertical"), this, &AMyPawn::MoveToVertical);
	PlayerInputComponent->BindAxis(TEXT("Horizontal"), this, &AMyPawn::MoveToHorizontal);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &AMyPawn::Turn);

}

void AMyPawn::MoveToVertical(float val)
{
//	FVector loc = GetActorLocation();
//	FVector rst = loc + GetActorForwardVector() * val;
//	SetActorLocation(rst);
//	AddMovementInput(GetActorForwardVector(), val);
}

void AMyPawn::MoveToHorizontal(float val)
{
	AddMovementInput(GetActorRightVector(), val);
//	FVector loc = GetActorLocation();
//	FVector rst = loc + GetActorRightVector() * val;
//	SetActorLocation(rst);
//	UE_LOG(LogTemp, Warning, TEXT("%f %f %f"), GetActorLocation().Y );

}

void AMyPawn::Turn(float val)
{
	UE_LOG(LogTemp, Warning, TEXT("%f"), val);
	FRotator rot = GetActorRotation();
	FRotator rst = rot + FRotator(0.0f, val * 1.f, 0.0f);
	SetActorRotation(rst);

}