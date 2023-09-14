// Fill out your copyright notice in the Description page of Project Settings.


#include "OSY_SnareFactory.h"
#include "OSY_NodeActor.h"
#include "OSY_SnareNodeActor.h"

// Sets default values
AOSY_SnareFactory::AOSY_SnareFactory()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SnarePoolSize=100;

}

// Called when the game starts or when spawned
void AOSY_SnareFactory::BeginPlay()
{
	Super::BeginPlay();

	for (int32 i = 0; i < SnarePoolSize; i++)
	{
		AOSY_SnareNodeActor* SnareNode = GetWorld()->SpawnActor<AOSY_SnareNodeActor>(NodeClass);
		
		//SnareNode->SetActorHiddenInGame(true);
		SnareNode->ActiveNode(FVector(), false);
		SnarePool.Add(SnareNode);
	}
	
}

// Called every frame
void AOSY_SnareFactory::Tick(float DeltaTime)
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
		spawnSnareNode();
		currentNodeIndex++;
	}
	// -> 노드 생성하자
	//for (float spawnTime : spawnTimes)
	//{
	//	if (currentTime >= spawnTime && currentTime - DeltaTime < spawnTime)
	//	{
	//		spawnSnareNode();
	//		//UE_LOG(LogTemp, Warning, TEXT("currentTime : %f"), currentTime);
	//	}
	//}
	//
}

void AOSY_SnareFactory::spawnSnareNode()
{
	// 풀에서 사용 가능한 스네어 노드 찾기
	for (AOSY_SnareNodeActor* SnareNode : SnarePool)
	{
		if (!SnareNode->isHidden)
		{
			continue; // 이미 사용 중인 오브젝트는 건너뜀
		}

		SnareNode->ActiveNode(GetActorLocation(), true);
		
		
		break; // 하나의 스네어 노드를 스폰한 후 멈춤
	}

}

