// Fill out your copyright notice in the Description page of Project Settings.


#include "OSY_HiHatNodeEndActor.h"
#include "Components/BoxComponent.h"

// Sets default values
AOSY_HiHatNodeEndActor::AOSY_HiHatNodeEndActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	compBox = CreateDefaultSubobject<UBoxComponent>(TEXT("compBox"));
	SetRootComponent(compBox);
	compBox->SetBoxExtent(FVector(50, 50, 32));

	compMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("compMesh"));
	compMesh->SetupAttachment(compBox);
	compMesh->SetRelativeScale3D(FVector(0.38f, 0.38f, 0.23f));

	ConstructorHelpers::FObjectFinder<UStaticMesh> tempMesh(TEXT("/Script/Engine.StaticMesh'/Engine/EngineMeshes/Cube.Cube'"));
	if (tempMesh.Succeeded())
	{
		compMesh->SetStaticMesh(tempMesh.Object);
	}

}

// Called when the game starts or when spawned
void AOSY_HiHatNodeEndActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOSY_HiHatNodeEndActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AOSY_HiHatNodeEndActor::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

}

