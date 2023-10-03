// Fill out your copyright notice in the Description page of Project Settings.


#include "OSY_Greate.h"

// Sets default values
AOSY_Greate::AOSY_Greate()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AOSY_Greate::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOSY_Greate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void AOSY_Greate::SpawnGreate()
{
	FActorSpawnParameters param;
	param.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	GetWorld()->SpawnActor<AOSY_Score>(ScoreFactory, GetActorLocation(), FRotator::ZeroRotator, param);
}

