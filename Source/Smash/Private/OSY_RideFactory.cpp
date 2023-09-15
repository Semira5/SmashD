// Fill out your copyright notice in the Description page of Project Settings.


#include "OSY_RideFactory.h"
#include "OSY_NodeActor.h"
#include "OSY_RideNodeActor.h"

// Sets default values
AOSY_RideFactory::AOSY_RideFactory()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RidePoolSize = 10;

}

// Called when the game starts or when spawned
void AOSY_RideFactory::BeginPlay()
{
	Super::BeginPlay();

	for (int32 i = 0; i < RidePoolSize; i++)
	{
		FActorSpawnParameters param;
		param.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		AOSY_RideNodeActor* RideNode = GetWorld()->SpawnActor<AOSY_RideNodeActor>(NodeClass,param);

		//SnareNode->SetActorHiddenInGame(true);
		RideNode->ActiveNode(FVector(), false);
		RidePool.Add(RideNode);
	}
	
}

// Called every frame
void AOSY_RideFactory::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (currentNodeIndex >= spawnTimes.Num())
	{
		return;
	}
	currentTime += DeltaTime;
	//UE_LOG(LogTemp, Warning, TEXT("currentTime : %f"), currentTime);

	float spawnTime = spawnTimes[currentNodeIndex];
	// 만약 현재 시간이 spawnTime 이 됐다면
	if (currentTime >= spawnTime)
	{
		spawnRideNode();
		currentNodeIndex++;
	}
}

void AOSY_RideFactory::spawnRideNode()
{
	// 생성위치
	for (AOSY_RideNodeActor* RideNode : RidePool)
	{
		if (!RideNode->isHidden)
		{
			continue; // 이미 사용 중인 오브젝트는 건너뜀
		}

		RideNode->ActiveNode(GetActorLocation(), true);


		break; // 하나의 스네어 노드를 스폰한 후 멈춤
	}
}

