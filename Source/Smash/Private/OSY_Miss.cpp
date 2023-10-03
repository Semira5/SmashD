// Fill out your copyright notice in the Description page of Project Settings.


#include "OSY_Miss.h"

// Sets default values
AOSY_Miss::AOSY_Miss()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


}

// Called when the game starts or when spawned
void AOSY_Miss::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOSY_Miss::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AOSY_Miss::SpawnMiss()
{
	FActorSpawnParameters param;
	param.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	GetWorld()->SpawnActor<AOSY_Score>(ScoreFactory, GetActorLocation(), FRotator::ZeroRotator, param);
}

