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

	if (player != nullptr)
	{
		if (player->CanPlayEffect == true)
		{
			PlayEffect();
			player->CanPlayEffect = false;
		}
	}

}

void ASpawnEffect::PlayEffect()
{
 
	UE_LOG(LogTemp, Warning, TEXT("Effect!!!"));
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), spark, GetActorLocation());
	
}

