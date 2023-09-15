// Fill out your copyright notice in the Description page of Project Settings.


#include "OSY_CrashFactory.h"
#include "OSY_NodeActor.h"
#include "OSY_CrashNodeActor.h"
#include "OSY_Level.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AOSY_CrashFactory::AOSY_CrashFactory()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CrashPoolSize = 20;

}

// Called when the game starts or when spawned
void AOSY_CrashFactory::BeginPlay()
{
	Super::BeginPlay();

	for (int32 i = 0; i < CrashPoolSize; i++)
	{
		FActorSpawnParameters param;
		param.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		AOSY_CrashNodeActor* CrashNode = GetWorld()->SpawnActor<AOSY_CrashNodeActor>(NodeClass,param);

		//SnareNode->SetActorHiddenInGame(true);
		CrashNode->ActiveNode(FVector(), false);
		CrashPool.Add(CrashNode);
	}
	
}

// Called every frame
void AOSY_CrashFactory::Tick(float DeltaTime)
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
		spawnCrashNode();
		currentNodeIndex++;
	}
	
	

}

void AOSY_CrashFactory::spawnCrashNode()
{	
	// 풀에서 사용 가능한 스네어 노드 찾기
	for (AOSY_CrashNodeActor* CrashNode : CrashPool)
	{
		if (!CrashNode->isHidden)
		{
			continue; // 이미 사용 중인 오브젝트는 건너뜀
		}

		CrashNode->ActiveNode(GetActorLocation(), true);


		break; // 하나의 스네어 노드를 스폰한 후 멈춤
	}


}

