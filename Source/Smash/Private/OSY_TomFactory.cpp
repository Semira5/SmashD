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
	// ���� ���� �ð��� spawnTime �� �ƴٸ�
	if (currentTime >= spawnTime)
	{
		spawnTomNode();
		currentNodeIndex++;
	}
}

void AOSY_TomFactory::spawnTomNode()
{
	// ������ġ
	for (AOSY_TomNodeActor* TomNode : TomPool)
	{
		if (!TomNode->isHidden)
		{
			continue; // �̹� ��� ���� ������Ʈ�� �ǳʶ�
		}

		TomNode->ActiveNode(GetActorLocation(), true);


		break; // �ϳ��� ���׾� ��带 ������ �� ����
	}
}