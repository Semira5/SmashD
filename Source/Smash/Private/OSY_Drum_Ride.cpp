// Fill out your copyright notice in the Description page of Project Settings.


#include "OSY_Drum_Ride.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "SmashCharacter.h"

// Sets default values
AOSY_Drum_Ride::AOSY_Drum_Ride()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	compScene = CreateDefaultSubobject<USceneComponent>(TEXT("compScene"));
	SetRootComponent(compScene);

	compBox = CreateDefaultSubobject<UBoxComponent>(TEXT("compBox"));
	compBox->SetupAttachment(compScene);
	compBox->SetRelativeLocation(FVector(-7.356771, -31.933054, 101.091586));
	compBox->SetRelativeRotation(FRotator(-20, 0, 15));
	compBox->SetRelativeScale3D(FVector(0.4f, 0.4f, 0.05f));
	compBox->SetBoxExtent(FVector(32, 32, 32));

	compMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("compMesh"));
	compMesh->SetRelativeRotation(FRotator(0, 274, 0));
	compMesh->SetupAttachment(compScene);
	ConstructorHelpers::FObjectFinder<UStaticMesh>tempMesh(TEXT("/Script/Engine.StaticMesh'/Game/BJH/DrumAsset/Drum_HP_Sub_Tails_2_High_poly.Drum_HP_Sub_Tails_2_High_poly'"));
	if (tempMesh.Succeeded())
	{
		compMesh->SetStaticMesh(tempMesh.Object);
	}

}

// Called when the game starts or when spawned
void AOSY_Drum_Ride::BeginPlay()
{
	Super::BeginPlay();
	
	compBox->OnComponentBeginOverlap.AddDynamic(this, &AOSY_Drum_Ride::OnComponentBeginOverlap);
}

// Called every frame
void AOSY_Drum_Ride::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AOSY_Drum_Ride::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
}


