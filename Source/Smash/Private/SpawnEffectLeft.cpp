// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnEffectLeft.h"
#include <Kismet/GameplayStatics.h>
#include "SmashCharacter.h"
// Sets default values
ASpawnEffectLeft::ASpawnEffectLeft()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawnEffectLeft::BeginPlay()
{
	Super::BeginPlay();
	
	player = Cast<ASmashCharacter>(UGameplayStatics::GetActorOfClass(GetWorld(), ASmashCharacter::StaticClass()));
}

// Called every frame
void ASpawnEffectLeft::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpawnEffectLeft::PlayEffect()
{

	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), spark, GetActorLocation());

}