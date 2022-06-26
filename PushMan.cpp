// Fill out your copyright notice in the Description page of Project Settings.


#include "PushMan.h"
#include "MyCharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "MyUtil.h"
#include "ChangeColorActor.h"
#include "GameManager.h"
#include "Runtime/Engine/Public/EngineUtils.h"
#include "DrawDebugHelpers.h"
// Sets default values
APushMan::APushMan()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MyMovement = CreateDefaultSubobject<UMyCharacterMovementComponent>(TEXT("MyMovementComponent"));
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> Res(TEXT("SkeletalMesh'/Game/SCK_Casual01/Models/Premade_Characters/MESH_PC_03.MESH_PC_03'"));

	if (Res.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(Res.Object);
	}
	
	GetMesh()->SetRelativeLocationAndRotation(FVector(0.f, 0.f, -90.f), FRotator(0.f, -90.f, 0.f));
	SpringArm->SetRelativeRotation(FRotator(-45.f, 0.f, 0.f));
	SpringArm->TargetArmLength = 400.0f;
	SpringArm->SetupAttachment(GetRootComponent());
	Camera->SetupAttachment(SpringArm);

    AttackRange = 200.0f;
    AttackRadius = 50.0f;


}

// Called when the game starts or when spawned
void APushMan::BeginPlay()
{
	Super::BeginPlay();
	for (const auto& target : TActorRange<AGameManager>(GetWorld())) 
	{
		manager = target;
	}
}

// Called every frame
void APushMan::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CollisionCheck();
}

// Called to bind functionality to input
void APushMan::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("Vertical"), this, &APushMan::MoveToVertical);
	PlayerInputComponent->BindAxis(TEXT("Horizontal"), this, &APushMan::MoveToHorizontal);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &APushMan::Turn);

}
void APushMan::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	if (Other)
	{
		if (Other->Tags.Num() > 0) {
			FName TagName = Other->Tags[0];
			FString name = TagName.ToString();
			//LOG("%s", *name);
			if (Other->ActorHasTag(FName(TEXT("Test"))))
			{
//				LOG("MyComp : %s", *MyComp->GetName());
//				LOG("Other : %s", *Other->GetName());
//				LOG("OtherComp : %s", *OtherComp->GetName());
//				LOG("HitLocation : %f, %f, %f", HitLocation.X, HitLocation.Y, HitLocation.Z);
//				LOG("HitNoram : %f, %f, %f", HitNormal.X, HitNormal.Y, HitNormal.Z);
//				LOG("NoramlImpulse : %f, %f, %f", NormalImpulse.X, NormalImpulse.Y, NormalImpulse.Z);
//				LOG("HitResult : %s", *Hit.GetActor()->GetName());
//				LOG("Other Pointer : %p", Other);
				AChangeColorActor* test = Cast<AChangeColorActor>(Other);
//				LOG("casted Other Pointer : %p", test);
				FVector vec = test->OriginColor;
//				LOG("%f, %f, %f", vec.X, vec.Y, vec.Z);

//				test->ChangeColor();

			}
		}
	}
}

void APushMan::PushBox(AActor* Box)
{

}
void APushMan::ChangeMesh()
{
	
}
void APushMan::MoveToVertical(float val)
{
//	FVector loc = GetActorLocation();
//	FVector rst = loc + GetActorForwardVector() * val;
//	SetActorLocation(rst);
	AddMovementInput(GetActorForwardVector(), val);
}

void APushMan::MoveToHorizontal(float val)
{
	AddMovementInput(GetActorRightVector(), val);
//	FVector loc = GetActorLocation();
//	FVector rst = loc + GetActorRightVector() * val;
//	SetActorLocation(rst);
//	UE_LOG(LogTemp, Warning, TEXT("%f %f %f"), GetActorLocation().Y );

}

void APushMan::Turn(float val)
{
	//AddControllerYawInput(val);

	FRotator rot = GetController()->GetControlRotation();
	FRotator rst = rot + FRotator(0.0f, val, 0.0f);
	GetController()->SetControlRotation(rst);
}

void APushMan::CollisionCheck()
{
    FHitResult HitResult;
    FCollisionQueryParams Params(NAME_None, false, this);

    bool bResult = GetWorld()->SweepSingleByChannel(
        HitResult, 
        GetActorLocation(),
        GetActorLocation() + GetActorForwardVector() * 200.0f,
        FQuat::Identity,
        ECollisionChannel::ECC_GameTraceChannel2,
        FCollisionShape::MakeSphere(50.0f),
        Params);

	FVector TraceVec = GetActorForwardVector() * AttackRange;
    FVector Center = GetActorLocation() + TraceVec * 0.5f;
    float HalfHeight = AttackRange * 0.5 + AttackRadius;
    FQuat CapsuleRot = FRotationMatrix::MakeFromZ(TraceVec).ToQuat();
    FColor DrawColor = bResult ? FColor::Green : FColor::Red;
    float DebugLifeTime = 1.0f;
	DrawDebugLine(GetWorld(), GetActorLocation(), GetActorLocation() + GetActorForwardVector() * 500.0f, DrawColor, false, DebugLifeTime);
    //DrawDebugCapsule(GetWorld(), Center, HalfHeight, AttackRadius, CapsuleRot, DrawColor, false, DebugLifeTime);

    if (bResult)
    {
        if (HitResult.Actor.IsValid())
        {
            LOG("Hit Actor Name : %s", *HitResult.Actor->GetName());
        }
    }
}
