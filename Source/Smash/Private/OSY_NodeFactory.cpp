// Fill out your copyright notice in the Description page of Project Settings.


#include "OSY_NodeFactory.h"
#include "OSY_NodeActor.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AOSY_NodeFactory::AOSY_NodeFactory()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AOSY_NodeFactory::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOSY_NodeFactory::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UE_LOG(LogTemp,Warning,TEXT("DeltaTime : %f"),DeltaTime);
	currentTime+= DeltaTime;
	//생성할거야
	UE_LOG(LogTemp,Warning,TEXT("CurrentTime : %f"),currentTime);
	if (currentTime >= 0.3125f && (currentTime - DeltaTime) < 0.3125f)
	{
		spawnNode();
	}
	// 2마디----마디별로 8로 나눠라
	if (currentTime >= 0.625f && (currentTime - DeltaTime) < 0.625f)
	{
		spawnNode();
	}
	
	


}

void AOSY_NodeFactory::spawnNode()
{
	// 생성위치
	FVector FactoryLoc = GetActorLocation();

	GetWorld()->SpawnActor<AOSY_NodeActor>(NodeFactory,FactoryLoc,FRotator::ZeroRotator);
}

