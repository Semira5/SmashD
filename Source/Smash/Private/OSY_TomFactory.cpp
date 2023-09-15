// Fill out your copyright notice in the Description page of Project Settings.


#include "OSY_TomFactory.h"
#include "OSY_NodeActor.h"
#include "OSY_TomNodeActor.h"

// Sets default values
AOSY_TomFactory::AOSY_TomFactory()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TomPoolSize = 10;

}

// Called when the game starts or when spawned
void AOSY_TomFactory::BeginPlay()
{
	Super::BeginPlay();

	for (int32 i = 0; i < TomPoolSize; i++)
	{
		FActorSpawnParameters param;
		param.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		AOSY_TomNodeActor* TomNode = GetWorld()->SpawnActor<AOSY_TomNodeActor>(NodeClass,param);

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
	//UE_LOG(LogTemp, Warning, TEXT("currentTime : %f"), currentTime);

	float spawnTime = spawnTimes[currentNodeIndex];
	// 만약 현재 시간이 spawnTime 이 됐다면
	if (currentTime >= spawnTime)
	{
		spawnTomNode();
		currentNodeIndex++;
	}
}

void AOSY_TomFactory::spawnTomNode()
{
	// 생성위치
	for (AOSY_TomNodeActor* TomNode : TomPool)
	{
		if (!TomNode->isHidden)
		{
			continue; // 이미 사용 중인 오브젝트는 건너뜀
		}

		TomNode->ActiveNode(GetActorLocation(), true);


		break; // 하나의 스네어 노드를 스폰한 후 멈춤
	}
}