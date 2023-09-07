// Fill out your copyright notice in the Description page of Project Settings.


#include "OSY_Drum_Snare.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"

// Sets default values
AOSY_Drum_Snare::AOSY_Drum_Snare()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	compScene = CreateDefaultSubobject<USceneComponent>(TEXT("compScene"));
	SetRootComponent(compScene);

	compBox = CreateDefaultSubobject<UBoxComponent>(TEXT("compBox"));
	compBox->SetupAttachment(compScene);
	compBox->SetRelativeLocation(FVector(-30, -43, 59));
	compBox->SetRelativeRotation(FRotator(0, 0, 0));
	compBox->SetRelativeScale3D(FVector(0.4f, 0.4f, 0.05f));
	compBox->SetBoxExtent(FVector(32, 32, 32));

	compMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("compMesh"));
	compMesh->SetRelativeRotation(FRotator(0, 115, 0));
	compMesh->SetupAttachment(compScene);
	ConstructorHelpers::FObjectFinder<UStaticMesh>tempMesh(TEXT("//Script/Engine.StaticMesh'/Game/BJH/DrumAsset/Drum_HP_Sub_Drum_snall_High_poly.Drum_HP_Sub_Drum_snall_High_poly'"));
	if (tempMesh.Succeeded())
	{
		compMesh->SetStaticMesh(tempMesh.Object);
	}

}

// Called when the game starts or when spawned
void AOSY_Drum_Snare::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOSY_Drum_Snare::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AOSY_Drum_Snare::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

}

