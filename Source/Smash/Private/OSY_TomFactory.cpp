// Fill out your copyright notice in the Description page of Project Settings.


#include "OSY_TomFactory.h"
#include "OSY_NodeActor.h"
#include "OSY_TomNodeActor.h"

// Sets default values
AOSY_TomFactory::AOSY_TomFactory()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AOSY_TomFactory::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOSY_TomFactory::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	currentTime += DeltaTime;
	UE_LOG(LogTemp, Warning, TEXT("currentTime : %f"), currentTime);

	TArray<float> spawnTimes =
	{ 8.625f,18.3125f,54.875f,54.953125f,55.03125f,95.5f,95.65625f,95.8125f,96.125f,96.4375f,96.59375f,142.84375f,142.921875f	};

	for (float spawnTime : spawnTimes)
	{
		if (currentTime >= spawnTime && currentTime - DeltaTime < spawnTime)
		{
			spawnTomhNode();
		}
	}
/*
#pragma region 9
	if (currentTime >= 10.3802 && (currentTime - DeltaTime) < 10.3802)
	{
		spawnTomhNode();
	}
#pragma endregion 9
#pragma region 46
	if (currentTime >= 55.5646 && (currentTime - DeltaTime) < 55.5646)
	{
		spawnTomhNode();
	}
	if (currentTime >= 55.640925 && (currentTime - DeltaTime) < 55.640925)
	{
		spawnTomhNode();
	}
	if (currentTime >= 55.71725 && (currentTime - DeltaTime) < 55.71725)
	{
		spawnTomhNode();
	}
#pragma endregion 46
#pragma region 116
	if (currentTime >= 141.3539 && (currentTime - DeltaTime) < 141.3539)
	{
		spawnTomhNode();
	}
	if (currentTime >= 141.430225 && (currentTime - DeltaTime) < 141.430225)
	{
		spawnTomhNode();
	}
#pragma endregion 116
*/
}

void AOSY_TomFactory::spawnTomhNode()
{
	FVector FactoryLoc = GetActorLocation();

	GetWorld()->SpawnActor<AOSY_TomNodeActor>(NodeFactory, FactoryLoc, FRotator::ZeroRotator);
}

