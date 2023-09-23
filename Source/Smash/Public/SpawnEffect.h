// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnEffect.generated.h"

UCLASS()
class SMASH_API ASpawnEffect : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnEffect();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Æø¹ßÈ¿°ú
	UPROPERTY(EditAnywhere,Category="MySettings")
	class UParticleSystem* spark;

	UFUNCTION()
	void PlayEffect();

	class ASmashCharacter* player;
};
