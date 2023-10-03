// Fill out your copyright notice in the Description page of Project Settings.


#include "OSY_RideFactory.h"
#include "OSY_RideNodeActor.h"
#include <Kismet/GameplayStatics.h>

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

	if (currentNodeIndex >= spawnTimes.Num())
	{
		return;
	}
	currentTime += DeltaTime;


	float spawnTime = spawnTimes[currentNodeIndex];
	// 만약 현재 시간이 spawnTime 이 됐다면
	if (currentTime >= spawnTime)
	{
		PoolChangeRN();
		currentNodeIndex++;
	}
}

void AOSY_RideFactory::PoolChangeRN()
{
	//UGameplayStatics::PlaySound2D(GetWorld(), KickSound);
}

