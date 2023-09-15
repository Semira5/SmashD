// Fill out your copyright notice in the Description page of Project Settings.


#include "OSY_NodeDestroyZone.h"
#include "Components/BoxComponent.h"
#include "OSY_CrashNodeActor.h"
#include "OSY_SnareNodeActor.h"
#include "OSY_SnareFactory.h"
#include "Kismet/GameplayStatics.h"
#include "OSY_HiHatNodeActor.h"
#include "OSY_RideNodeActor.h"
#include "OSY_TomNodeActor.h"

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
	
	
	current += DeltaTime;
	if (isOverlap != true)
	{
		UE_LOG(LogTemp, Warning, TEXT("current : %f"), current);
		isOverlap = true;
	}

	
}

void AOSY_NodeDestroyZone::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AOSY_SnareNodeActor* SN =Cast<AOSY_SnareNodeActor>(OtherActor);
	AOSY_CrashNodeActor* CN =Cast<AOSY_CrashNodeActor>(OtherActor);
	AOSY_HiHatNodeActor* HN =Cast<AOSY_HiHatNodeActor>(OtherActor);
	AOSY_RideNodeActor* RN =Cast<AOSY_RideNodeActor>(OtherActor);
	AOSY_TomNodeActor* TN =Cast<AOSY_TomNodeActor>(OtherActor);
	if (SN != nullptr)
	{
		SN->ActiveNode(GetActorLocation(), false);
	}
	if (CN != nullptr)
	{
		CN->ActiveNode(GetActorLocation(), false);
	}
	if (HN != nullptr)
	{
		HN->ActiveNode(GetActorLocation(), false);
	}
	if (RN != nullptr)
	{
		RN->ActiveNode(GetActorLocation(), false);

	}
	if (TN != nullptr)
	{
		TN->ActiveNode(GetActorLocation(), false);

	}
// 	else
// 	{
// 		OtherActor->Destroy();
// 
// 	}

}

