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
#include "OSY_CrashFactory.h"
#include "OSY_HiHatFactory.h"
#include "OSY_RideFactory.h"
#include "OSY_TomFactory.h"
#include "OSY_Miss.h"

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

	// 나랑 부딪혔을 때 이벤트를 등록
	boxComp->OnComponentBeginOverlap.AddDynamic(this, &AOSY_NodeDestroyZone::OnComponentBeginOverlap);

	CrashFactory = Cast<AOSY_CrashFactory>(UGameplayStatics::GetActorOfClass(GetWorld(), AOSY_CrashFactory::StaticClass()));
	HiHatFactory = Cast<AOSY_HiHatFactory>(UGameplayStatics::GetActorOfClass(GetWorld(), AOSY_HiHatFactory::StaticClass()));
	SnareFactory = Cast<AOSY_SnareFactory>(UGameplayStatics::GetActorOfClass(GetWorld(), AOSY_SnareFactory::StaticClass()));
	RideFactory = Cast<AOSY_RideFactory>(UGameplayStatics::GetActorOfClass(GetWorld(), AOSY_RideFactory::StaticClass()));
	TomFactory = Cast<AOSY_TomFactory>(UGameplayStatics::GetActorOfClass(GetWorld(), AOSY_TomFactory::StaticClass()));

	missFac = Cast<AOSY_Miss>(UGameplayStatics::GetActorOfClass(GetWorld(), AOSY_Miss::StaticClass()));
	
}

// Called every frame
void AOSY_NodeDestroyZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	
	current += DeltaTime;
	if (isOverlap != true)
	{
		////UE_LOG(LogTemp, Warning, TEXT("current : %f"), current);
		isOverlap = true;
	}

	
}

void AOSY_NodeDestroyZone::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AOSY_CrashNodeActor* CN =Cast<AOSY_CrashNodeActor>(OtherActor);
	AOSY_HiHatNodeActor* HN =Cast<AOSY_HiHatNodeActor>(OtherActor);
	AOSY_SnareNodeActor* SN =Cast<AOSY_SnareNodeActor>(OtherActor);
	AOSY_RideNodeActor* RN =Cast<AOSY_RideNodeActor>(OtherActor);
	AOSY_TomNodeActor* TN =Cast<AOSY_TomNodeActor>(OtherActor);

	if (CN != nullptr)
	{
		if (missFac != nullptr)
		{
			missFac->SpawnMiss();
		}
		CrashFactory->ActiveCrashPool[0]->ActiveNode(FVector::ZeroVector, false);
		// 그걸 풀에 넣고
		CrashFactory->CrashPool.Add(CrashFactory->ActiveCrashPool[0]);
		// 액티브 풀에서는 빼버려
		CrashFactory->ActiveCrashPool.RemoveAt(0);

		missCount+=1;
		

	}
	
	if (HN != nullptr)
	{
		if (missFac != nullptr)
		{
			missFac->SpawnMiss();
		}
		HiHatFactory->ActiveHiHatPool[0]->ActiveNode(FVector::ZeroVector, false);
		
		// 그걸 풀에 넣고
		HiHatFactory->HiHatPool.Add(HiHatFactory->ActiveHiHatPool[0]);
		// 액티브 풀에서는 빼버려
		HiHatFactory->ActiveHiHatPool.RemoveAt(0);

		missCount += 1;
	}

	if (SN != nullptr)
	{
		if (missFac != nullptr)
		{
			missFac->SpawnMiss();
		}
		SN->ActiveNode(GetActorLocation(), false);
		if (SnareFactory != nullptr && SnareFactory->ActiveSnarePool.Num() <= 0)
		{
			return;
		}
		else
		{
			SnareFactory->ActiveSnarePool[0]->ActiveNode(FVector::ZeroVector, false);
			SnareFactory->SnarePool.Add(SnareFactory->ActiveSnarePool[0]);
			SnareFactory->ActiveSnarePool.RemoveAt(0);

			missCount += 1;

		}
	}

	if (RN != nullptr)
	{
		if (missFac != nullptr)
		{
			missFac->SpawnMiss();
		}
		RideFactory->ActiveRidePool[0]->ActiveNode(FVector::ZeroVector, false);
		RideFactory->RidePool.Add(RideFactory->ActiveRidePool[0]);
		RideFactory->ActiveRidePool.RemoveAt(0);

	}

	if (TN != nullptr)
	{
		if (missFac != nullptr)
		{
			missFac->SpawnMiss();
		}
		TomFactory->ActiveTomPool[0]->ActiveNode(FVector::ZeroVector, false);
		TomFactory->TomPool.Add(TomFactory->ActiveTomPool[0]);
		TomFactory->ActiveTomPool.RemoveAt(0);

	}

}

