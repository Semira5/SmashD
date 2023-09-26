// Fill out your copyright notice in the Description page of Project Settings.


#include "OSY_HiHatFactory.h"
#include "OSY_HiHatNodeActor.h"
#include "OSY_Drum_HiHat.h"

// Sets default values
AOSY_HiHatFactory::AOSY_HiHatFactory()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	HiHatPoolSize = 20;
}

// Called when the game starts or when spawned
void AOSY_HiHatFactory::BeginPlay()
{
	Super::BeginPlay();

	for (int32 i = 0; i < HiHatPoolSize; i++)
	{
		FActorSpawnParameters param;
	param.SpawnCollisionHandlingOverride=ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		AOSY_HiHatNodeActor* HiHatNode = GetWorld()->SpawnActor<AOSY_HiHatNodeActor>(NodeClass,param);

		//SnareNode->SetActorHiddenInGame(true);
		HiHatNode->ActiveNode(FVector(), false);
		HiHatPool.Add(HiHatNode);
	}
	
}

// Called every frame
void AOSY_HiHatFactory::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (currentNodeIndex >= spawnTimes.Num())
	{
		return;
	}
	currentTime += DeltaTime;

	float spawnTime = spawnTimes[currentNodeIndex];
	// 만약 현재 시간이 spawnTime 이 됐다면
	if (currentTime >= spawnTime)
	{
		PoolChangeHN();
		currentNodeIndex++;
	}

}

void AOSY_HiHatFactory::PoolChangeHN()
{
	// 풀에서 사용 가능한 스네어 노드 찾기
	for (AOSY_HiHatNodeActor* HiHatNode : HiHatPool)
	{
		// 풀에 0번째에 있는 놈을 활성화를 시킨다.
		auto ActiveHiHatNode = HiHatPool[0];
		ActiveHiHatNode->ActiveNode(GetActorLocation(),true);
		// 풀에서 제거한다.
		ActiveHiHatPool.Add(ActiveHiHatNode);
		HiHatPool.RemoveAt(0);
		break;
		
	}
}

