// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnEffect.h"
#include <Kismet/GameplayStatics.h>
#include "SmashCharacter.h"

// Sets default values
ASpawnEffect::ASpawnEffect()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawnEffect::BeginPlay()
{
	Super::BeginPlay();

	player = Cast<ASmashCharacter>(UGameplayStatics::GetActorOfClass(GetWorld(), ASmashCharacter::StaticClass()));

	
}

// Called every frame
void ASpawnEffect::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);



}

void ASpawnEffect::PlayEffect()
{
   
    FVector ActorLocation = GetActorLocation();

    FVector SpawnLocation1 = ActorLocation + FVector(0, 200, 0); 
    FVector SpawnLocation2 = ActorLocation + FVector(0, -200, 0); 

    UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), spark, SpawnLocation1);
    UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), spark, SpawnLocation2);
	
}

