// Fill out your copyright notice in the Description page of Project Settings.


#include "OSY_Excellent.h"

// Sets default values
AOSY_Excellent::AOSY_Excellent()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


}

// Called when the game starts or when spawned
void AOSY_Excellent::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOSY_Excellent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void AOSY_Excellent::SpawnExcellent()
{

	FActorSpawnParameters param;
	param.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn; 
	GetWorld()->SpawnActor<AOSY_Score>(ScoreFactory, GetActorLocation(), FRotator::ZeroRotator,param);
}

