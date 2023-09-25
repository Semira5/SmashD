// Fill out your copyright notice in the Description page of Project Settings.


#include "OSY_Drum_Crash.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "SmashCharacter.h"

// Sets default values
AOSY_Drum_Crash::AOSY_Drum_Crash()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	compScene = CreateDefaultSubobject<USceneComponent>(TEXT("compScene"));
	SetRootComponent(compScene);

	compBox = CreateDefaultSubobject<UBoxComponent>(TEXT("compBox"));
	compBox->SetupAttachment(compScene);
	compBox->SetRelativeLocation(FVector(-32.582295f, 0.734776f, 101.956334f));
	compBox->SetRelativeRotation(FRotator(-20, 0, -10));
	compBox->SetRelativeScale3D(FVector(0.4f, 0.4f, 0.05f));
	compBox->SetBoxExtent(FVector(32, 32, 32));

	compMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("compMesh"));
	compMesh->SetRelativeRotation(FRotator(0, -166, 0));
	compMesh->SetupAttachment(compScene);
	ConstructorHelpers::FObjectFinder<UStaticMesh>tempMesh(TEXT("/Script/Engine.StaticMesh'/Game/BJH/DrumAsset/Drum_HP_Sub_Tails_2_High_poly.Drum_HP_Sub_Tails_2_High_poly'"));
	if (tempMesh.Succeeded())
	{
		compMesh->SetStaticMesh(tempMesh.Object);
	}

}

// Called when the game starts or when spawned
void AOSY_Drum_Crash::BeginPlay()
{
	Super::BeginPlay();
	
	compBox->OnComponentBeginOverlap.AddDynamic(this, &AOSY_Drum_Crash::OnComponentBeginOverlap);

	// Snare의 원래 크기를 OriginalScale에 저장합니다.
	OriginalScale = compMesh->GetComponentScale();
}

// Called every frame
void AOSY_Drum_Crash::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AOSY_Drum_Crash::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ASmashCharacter* Player = Cast<ASmashCharacter>(OtherActor);

	FVector NewScale = FVector(2.6f, 2.6f, 2.5f);
	compMesh->SetWorldScale3D(NewScale);

	float TimeToResetSize = 0.5f;
	GetWorldTimerManager().SetTimer(ResizeTimerHandle, this, &AOSY_Drum_Crash::ResetSize, TimeToResetSize, false);
}

void AOSY_Drum_Crash::ResetSize()
{
	compMesh->SetWorldScale3D(OriginalScale);
}

