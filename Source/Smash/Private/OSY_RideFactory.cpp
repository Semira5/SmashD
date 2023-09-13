// Fill out your copyright notice in the Description page of Project Settings.


#include "OSY_RideFactory.h"
#include "OSY_NodeActor.h"
#include "OSY_RideNodeActor.h"

// Sets default values
AOSY_RideFactory::AOSY_RideFactory()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AOSY_RideFactory::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOSY_RideFactory::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	currentTime += DeltaTime;
	//UE_LOG(LogTemp, Warning, TEXT("currentTime : %f"), currentTime);

	TArray<float> spawnTimes =
	{ 53.34375f};

	for (float spawnTime : spawnTimes)
	{
		if (currentTime >= spawnTime && currentTime - DeltaTime < spawnTime)
		{
			//spawnRidehNode();
		}
	}
	/*
#pragma region 46
	if (currentTime >= 55.8699 && (currentTime - DeltaTime) < 55.8699)
	{
		spawnRidehNode();
	}
#pragma endregion 46
#pragma region 104
	if (currentTime >= 126.3942 && (currentTime - DeltaTime) < 126.3942)
	{
		spawnRidehNode();
	}
#pragma endregion 104
#pragma region 105
	if (currentTime >= 127.6154 && (currentTime - DeltaTime) < 127.6154)
	{
		spawnRidehNode();
	}
#pragma endregion 105
#pragma region 106
	if (currentTime >= 128.8366 && (currentTime - DeltaTime) < 128.8366)
	{
		spawnRidehNode();
	}
#pragma endregion 106
*/
}

void AOSY_RideFactory::spawnRidehNode()
{
	// 생성위치
	FVector FactoryLoc = GetActorLocation();

	GetWorld()->SpawnActor<AOSY_RideNodeActor>(NodeFactory, FactoryLoc, FRotator::ZeroRotator);
}

