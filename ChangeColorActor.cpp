// Fill out your copyright notice in the Description page of Project Settings.


#include "ChangeColorActor.h"
#include "MyUtil.h"

// Sets default values
AChangeColorActor::AChangeColorActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Res(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("Material'/Game/StarterContent/Materials/My_Test_Material.My_Test_Material'"));

	if (Res.Succeeded())
	{
		MeshComponent->SetStaticMesh(Res.Object);
	}

	if (Material.Succeeded())
	{
		MeshComponent->SetMaterial(0, Material.Object);
	}

	MyMID = MeshComponent->CreateDynamicMaterialInstance(0);
	LOG("this pointer : %p", this);
	OriginColor = FVector(0.1f, 0.8f, 0.3f);
	TargetColor = FVector(0.8f, 0.1f, 0.2f);
	MyMID->SetVectorParameterValue(TEXT("Color"), OriginColor);
	CurrentColor = OriginColor;
}

// Called when the game starts or when spawned
void AChangeColorActor::BeginPlay()
{
	Super::BeginPlay();
//	OriginColor = FVector(0.1f, 0.8f, 0.3f);
//	TargetColor = FVector(0.8f, 0.1f, 0.2f);
}

// Called every frame
void AChangeColorActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AChangeColorActor::ChangeColor()
{
	LOG("Curr : %f, %f, %f", CurrentColor.X, CurrentColor.Y, CurrentColor.Z);
	LOG("Ori : %f, %f, %f", OriginColor.X, OriginColor.Y, OriginColor.Z);
	LOG("targ : %f, %f, %f", TargetColor.X, TargetColor.Y, TargetColor.Z);
	if(CurrentColor != OriginColor)
	{
		CurrentColor = OriginColor;
	}
	else
	{
		CurrentColor = TargetColor;
	}
	MyMID = MeshComponent->CreateDynamicMaterialInstance(0);
	float f = FMath::FRandRange(0.f, 1.f);
	if (f <= 0.5)
	{
		MyMID->SetVectorParameterValue("Color", FVector(1.0f, 0.0f, 0.0f));
	}
	else {
		MyMID->SetVectorParameterValue("Color", FVector(0.0f, 0.0f, 1.0f));
	}
}

