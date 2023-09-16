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
		PoolChangeRN();
		currentNodeIndex++;
	}
}

void AOSY_RideFactory::PoolChangeRN()
{
	// 풀에서 사용 가능한 스네어 노드 찾기
	for (AOSY_RideNodeActor* RideNode : RidePool)
	{
		// 풀에 0번째에 있는 놈을 활성화를 시킨다.
		auto ActiveRideNode = RidePool[0];
		ActiveRideNode->ActiveNode(GetActorLocation(), true);
		// 풀에서 제거한다.
		ActiveRidePool.Add(ActiveRideNode);
		RidePool.RemoveAt(0);
		break;

	}
}

