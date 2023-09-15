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
	// ���� ���� �ð��� spawnTime �� �ƴٸ�
	if (currentTime >= spawnTime)
	{
		spawnCrashNode();
		currentNodeIndex++;
	}
	
	

}

void AOSY_CrashFactory::spawnCrashNode()
{	
	// Ǯ���� ��� ������ ���׾� ��� ã��
	for (AOSY_CrashNodeActor* CrashNode : CrashPool)
	{
		if (!CrashNode->isHidden)
		{
			continue; // �̹� ��� ���� ������Ʈ�� �ǳʶ�
		}

		CrashNode->ActiveNode(GetActorLocation(), true);


		break; // �ϳ��� ���׾� ��带 ������ �� ����
	}


}

