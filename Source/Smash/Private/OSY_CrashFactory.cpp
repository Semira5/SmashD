// Fill out your copyright notice in the Description page of Project Settings.


#include "OSY_CrashFactory.h"
#include "OSY_NodeActor.h"

// Sets default values
AOSY_CrashFactory::AOSY_CrashFactory()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AOSY_CrashFactory::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOSY_CrashFactory::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	currentTime += DeltaTime;

#pragma region 10
	if (currentTime >= 10.9908 && (currentTime - DeltaTime) < 10.9908)
	{
		spawnCrashNode();
	}
	if (currentTime >= 11.2961 && (currentTime - DeltaTime) < 11.2961)
	{
		spawnCrashNode();
	}
	if (currentTime >= 11.6014 && (currentTime - DeltaTime) < 11.6014)
	{
		spawnCrashNode();
	}
	if (currentTime >= 11.9067 && (currentTime - DeltaTime) < 11.9067)
	{
		spawnCrashNode();
	}
#pragma endregion 10
#pragma region 11
	if (currentTime >= 12.212 && (currentTime - DeltaTime) < 12.212)
	{
		spawnCrashNode();
	}
	if (currentTime >= 12.5173 && (currentTime - DeltaTime) < 12.5173)
	{
		spawnCrashNode();
	}
	if (currentTime >= 12.8226 && (currentTime - DeltaTime) < 12.8226)
	{
		spawnCrashNode();
	}
	if (currentTime >= 13.1279 && (currentTime - DeltaTime) < 13.1279)
	{
		spawnCrashNode();
	}
#pragma endregion 11
#pragma region 12
	if (currentTime >= 13.4332 && (currentTime - DeltaTime) < 13.4332)
	{
		spawnCrashNode();
	}
	if (currentTime >= 13.7385 && (currentTime - DeltaTime) < 13.7385)
	{
		spawnCrashNode();
	}
	if (currentTime >= 14.0438 && (currentTime - DeltaTime) < 14.0438)
	{
		spawnCrashNode();
	}
	if (currentTime >= 14.3491 && (currentTime - DeltaTime) < 14.3491)
	{
		spawnCrashNode();
	}
	if (currentTime >= 14.425425 && (currentTime - DeltaTime) < 14.425425)
	{
		spawnCrashNode();
	}
#pragma endregion 12
#pragma region 13
	if (currentTime >= 14.6544 && (currentTime - DeltaTime) < 14.6544)
	{
		spawnCrashNode();
	}
	if (currentTime >= 15.265 && (currentTime - DeltaTime) < 15.265)
	{
		spawnCrashNode();
	}
#pragma endregion 13
#pragma region 18
	if (currentTime >= 20.7604 && (currentTime - DeltaTime) < 20.7604)
	{
		spawnCrashNode();
	}
#pragma endregion 18
#pragma region 26
	if (currentTime >= 30.53 && (currentTime - DeltaTime) < 30.53)
	{
		spawnCrashNode();
	}
#pragma endregion 26
#pragma region 30
	if (currentTime >= 35.4148 && (currentTime - DeltaTime) < 35.4148)
	{
		spawnCrashNode();
	}
#pragma endregion 30
#pragma region 35
	if (currentTime >= 41.5208 && (currentTime - DeltaTime) < 41.5208)
	{
		spawnCrashNode();
	}
	if (currentTime >= 41.8261 && (currentTime - DeltaTime) < 41.8261)
	{
		spawnCrashNode();
	}
	if (currentTime >= 42.1314 && (currentTime - DeltaTime) < 42.1314)
	{
		spawnCrashNode();
	}
	if (currentTime >= 42.4367 && (currentTime - DeltaTime) < 42.4367)
	{
		spawnCrashNode();
	}
#pragma endregion 35
#pragma region 36
	if (currentTime >= 42.742 && (currentTime - DeltaTime) < 42.742)
	{
		spawnCrashNode();
	}
	if (currentTime >= 43.0473 && (currentTime - DeltaTime) < 43.0473)
	{
		spawnCrashNode();
	}
	if (currentTime >= 43.3526 && (currentTime - DeltaTime) < 43.3526)
	{
		spawnCrashNode();
	}
	if (currentTime >= 43.6579 && (currentTime - DeltaTime) < 43.6579)
	{
		spawnCrashNode();
	}
#pragma endregion 36
#pragma region 37
	if (currentTime >= 43.9632 && (currentTime - DeltaTime) < 43.9632)
	{
		spawnCrashNode();
	}
	if (currentTime >= 44.2685 && (currentTime - DeltaTime) < 44.2685)
	{
		spawnCrashNode();
	}
	if (currentTime >= 44.5738 && (currentTime - DeltaTime) < 44.5738)
	{
		spawnCrashNode();
	}
	if (currentTime >= 44.8791 && (currentTime - DeltaTime) < 44.8791)
	{
		spawnCrashNode();
	}
#pragma endregion 37
#pragma region 38
	if (currentTime >= 45.1844 && (currentTime - DeltaTime) < 45.1844)
	{
		spawnCrashNode();
	}
	if (currentTime >= 45.795 && (currentTime - DeltaTime) < 45.795)
	{
		spawnCrashNode();
	}
#pragma endregion 38
#pragma region 39
	if (currentTime >= 46.4056 && (currentTime - DeltaTime) < 46.4056)
	{
		spawnCrashNode();
	}
	if (currentTime >= 46.7109 && (currentTime - DeltaTime) < 46.7109)
	{
		spawnCrashNode();
	}
	if (currentTime >= 47.0162 && (currentTime - DeltaTime) < 47.0162)
	{
		spawnCrashNode();
	}
	if (currentTime >= 47.3215 && (currentTime - DeltaTime) < 47.3215)
	{
		spawnCrashNode();
	}
#pragma endregion 39
#pragma region 40
	if (currentTime >= 47.6268 && (currentTime - DeltaTime) < 47.6268)
	{
		spawnCrashNode();
	}
	if (currentTime >= 47.9321 && (currentTime - DeltaTime) < 47.9321)
	{
		spawnCrashNode();
	}
	if (currentTime >= 48.2374 && (currentTime - DeltaTime) < 48.2374)
	{
		spawnCrashNode();
	}
	if (currentTime >= 48.5427 && (currentTime - DeltaTime) < 48.5427)
	{
		spawnCrashNode();
	}
#pragma endregion 40
#pragma region 41
	if (currentTime >= 48.848 && (currentTime - DeltaTime) < 48.848)
	{
		spawnCrashNode();
	}
	if (currentTime >= 49.1533 && (currentTime - DeltaTime) < 49.1533)
	{
		spawnCrashNode();
	}
	if (currentTime >= 49.4586 && (currentTime - DeltaTime) < 49.4586)
	{
		spawnCrashNode();
	}
	if (currentTime >= 49.7639 && (currentTime - DeltaTime) < 49.7639)
	{
		spawnCrashNode();
	}
#pragma endregion 41
#pragma region 42
	if (currentTime >= 50.0692 && (currentTime - DeltaTime) < 50.0692)
	{
		spawnCrashNode();
	}
#pragma endregion 42
#pragma region 43
	if (currentTime >= 51.2904 && (currentTime - DeltaTime) < 51.2904)
	{
		spawnCrashNode();
	}
#pragma endregion 43
#pragma region 43
	if (currentTime >= 56.1752 && (currentTime - DeltaTime) < 56.1752)
	{
		spawnCrashNode();
	}
#pragma endregion 43









}

void AOSY_CrashFactory::spawnCrashNode()
{	
	// 생성위치
	FVector FactoryLoc = GetActorLocation();

	GetWorld()->SpawnActor<AOSY_NodeActor>(NodeFactory, FactoryLoc, FRotator::ZeroRotator);


}

