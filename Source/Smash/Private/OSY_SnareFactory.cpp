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
	// ���� ���� �ð��� spawnTime �� �ƴٸ�
	if (currentTime >= spawnTime)
	{
		spawnSnareNode();
		currentNodeIndex++;
	}
	// -> ��� ��������
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
	// Ǯ���� ��� ������ ���׾� ��� ã��
	for (AOSY_SnareNodeActor* SnareNode : SnarePool)
	{
		if (!SnareNode->isHidden)
		{
			continue; // �̹� ��� ���� ������Ʈ�� �ǳʶ�
		}

		SnareNode->ActiveNode(GetActorLocation(), true);
		
		
		break; // �ϳ��� ���׾� ��带 ������ �� ����
	}

}

