// Fill out your copyright notice in the Description page of Project Settings.


#include "OSY_Early.h"

// Sets default values
AOSY_Early::AOSY_Early()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AOSY_Early::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOSY_Early::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void AOSY_Early::SpawnEarly()
{
	FActorSpawnParameters param;
	param.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	GetWorld()->SpawnActor<AOSY_Score>(ScoreFactory, GetActorLocation(), FRotator::ZeroRotator, param);
}

