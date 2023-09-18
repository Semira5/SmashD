// Fill out your copyright notice in the Description page of Project Settings.


#include "OSY_TomFactory.h"
#include "OSY_TomNodeActor.h"

// Sets default values
AOSY_TomFactory::AOSY_TomFactory()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TomPoolSize = 20;

}

// Called when the game starts or when spawned
void AOSY_TomFactory::BeginPlay()
{
	Super::BeginPlay();

	for (int32 i = 0; i < TomPoolSize; i++)
	{
		FActorSpawnParameters param;
		param.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		AOSY_TomNodeActor* TomNode = GetWorld()->SpawnActor<AOSY_TomNodeActor>(NodeClass, param);

		//SnareNode->SetActorHiddenInGame(true);
		TomNode->ActiveNode(FVector(), false);
		TomPool.Add(TomNode);
	}

}

// Called every frame
void AOSY_TomFactory::Tick(float DeltaTime)
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
		PoolChangeTN();
		currentNodeIndex++;
	}

}

void AOSY_TomFactory::PoolChangeTN()
{
	// 풀에서 사용 가능한 스네어 노드 찾기
	for (AOSY_TomNodeActor* TomNode : TomPool)
	{
		// 풀에 0번째에 있는 놈을 활성화를 시킨다.
		auto ActiveTomNode = TomPool[0];
		ActiveTomNode->ActiveNode(GetActorLocation(), true);
		// 풀에서 제거한다.
		ActiveTomPool.Add(ActiveTomNode);
		TomPool.RemoveAt(0);
		break;

	}
}
