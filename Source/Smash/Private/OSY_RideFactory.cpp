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
	// ���� ���� �ð��� spawnTime �� �ƴٸ�
	if (currentTime >= spawnTime)
	{
		spawnRideNode();
		currentNodeIndex++;
	}
}

void AOSY_RideFactory::spawnRideNode()
{
	// ������ġ
	for (AOSY_RideNodeActor* RideNode : RidePool)
	{
		if (!RideNode->isHidden)
		{
			continue; // �̹� ��� ���� ������Ʈ�� �ǳʶ�
		}

		RideNode->ActiveNode(GetActorLocation(), true);


		break; // �ϳ��� ���׾� ��带 ������ �� ����
	}
}

