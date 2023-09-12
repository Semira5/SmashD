// Fill out your copyright notice in the Description page of Project Settings.


#include "OSY_CrashNodeEndActor.h"
#include "Components/BoxComponent.h"

// Sets default values
AOSY_CrashNodeEndActor::AOSY_CrashNodeEndActor()
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
void AOSY_CrashNodeEndActor::BeginPlay()
{
	Super::BeginPlay();

	compBox->OnComponentBeginOverlap.AddDynamic(this, &AOSY_CrashNodeEndActor::OnComponentBeginOverlap);
	
}

// Called every frame
void AOSY_CrashNodeEndActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AOSY_CrashNodeEndActor::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
	UE_LOG(LogTemp, Warning, TEXT("Overlap"));
}

