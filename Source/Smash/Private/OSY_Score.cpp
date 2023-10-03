// Fill out your copyright notice in the Description page of Project Settings.


#include "OSY_Score.h"

// Sets default values
AOSY_Score::AOSY_Score()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	SetLifeSpan(2);

}

// Called when the game starts or when spawned
void AOSY_Score::BeginPlay()
{
	Super::BeginPlay();


	
}

// Called every frame
void AOSY_Score::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector p0 = GetActorLocation();
	FVector vt = FVector::UpVector*speed*DeltaTime;
	FVector p = p0 + vt;
	SetActorLocation(p);

}

