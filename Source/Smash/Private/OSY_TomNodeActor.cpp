// Fill out your copyright notice in the Description page of Project Settings.


#include "OSY_TomNodeActor.h"
#include "Components/BoxComponent.h"
#include <Kismet/GameplayStatics.h>
#include "OSY_TomNodeEndActor.h"

// Sets default values
AOSY_TomNodeActor::AOSY_TomNodeActor()
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
void AOSY_TomNodeActor::BeginPlay()
{
	Super::BeginPlay();

	Target = Cast<AOSY_TomNodeEndActor>(UGameplayStatics::GetActorOfClass(GetWorld(), AOSY_TomNodeEndActor::StaticClass()));

	if (Target != nullptr)
	{
		direction = Target->GetActorLocation() - GetActorLocation();
	}
	
}

// Called every frame
void AOSY_TomNodeActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector P0 = GetActorLocation();
	FVector vt = direction * speed * DeltaTime;
	FVector P = P0 + vt;
	SetActorLocation(P);

}

void AOSY_TomNodeActor::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

}

