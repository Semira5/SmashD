// Fill out your copyright notice in the Description page of Project Settings.


#include "OSY_SnareFactory.h"
#include "OSY_SnareNodeActor.h"

// Sets default values
AOSY_SnareFactory::AOSY_SnareFactory()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SnarePoolSize = 20;

}

// Called when the game starts or when spawned
void AOSY_SnareFactory::BeginPlay()
{
	Super::BeginPlay();

	for (int32 i = 0; i < SnarePoolSize; i++)
	{
		FActorSpawnParameters param;
		param.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		AOSY_SnareNodeActor* SnareNode = GetWorld()->SpawnActor<AOSY_SnareNodeActor>(NodeClass, param);

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

	float spawnTime = spawnTimes[currentNodeIndex];
	// ���� ���� �ð��� spawnTime �� �ƴٸ�
	if (currentTime >= spawnTime)
	{
		PoolChangeSN();
		currentNodeIndex++;
	}

}

void AOSY_SnareFactory::PoolChangeSN()
{
	// Ǯ���� ��� ������ ���׾� ��� ã��
	for (AOSY_SnareNodeActor* SnareNode : SnarePool)
	{
		// Ǯ�� 0��°�� �ִ� ���� Ȱ��ȭ�� ��Ų��.
		auto ActiveSnareNode = SnarePool[0];
		ActiveSnareNode->ActiveNode(GetActorLocation(), true);
		// Ǯ���� �����Ѵ�.
		ActiveSnarePool.Add(ActiveSnareNode);
		SnarePool.RemoveAt(0);
		break;

	}
}

