// Fill out your copyright notice in the Description page of Project Settings.


#include "OSY_NodeDestroyZone.h"
#include "Components/BoxComponent.h"
#include "OSY_CrashNodeActor.h"

// Sets default values
AOSY_NodeDestroyZone::AOSY_NodeDestroyZone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("boxComp"));
	RootComponent = boxComp;

}

// Called when the game starts or when spawned
void AOSY_NodeDestroyZone::BeginPlay()
{
	Super::BeginPlay();

	// ³ª¶û ºÎµúÇûÀ» ¶§ ÀÌº¥Æ®¸¦ µî·Ï
	boxComp->OnComponentBeginOverlap.AddDynamic(this, &AOSY_NodeDestroyZone::OnComponentBeginOverlap);
	
}

// Called every frame
void AOSY_NodeDestroyZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
}

void AOSY_NodeDestroyZone::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp,Warning,TEXT("Overlap"));
	OtherActor->Destroy();

}

