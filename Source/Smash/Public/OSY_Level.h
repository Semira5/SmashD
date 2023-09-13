// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "OSY_Level.generated.h"

/**
 * 
 */
UCLASS()
class SMASH_API AOSY_Level : public ALevelScriptActor
{
	GENERATED_BODY()

public:
	AOSY_Level();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "MySettings")
	float currentTime = 0;

	UPROPERTY(EditAnywhere, Category = "MySettings")
	float playSoundTime = 2;
	
	UPROPERTY(EditDefaultsOnly, Category="MySettings")
	class USoundBase* StillWaiting;

	bool bfirsttick=true;

	
	void playMusic();
};
