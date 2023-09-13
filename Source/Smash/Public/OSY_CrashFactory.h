// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OSY_CrashFactory.generated.h"

UCLASS()
class SMASH_API AOSY_CrashFactory : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOSY_CrashFactory();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere, Category="MySettings")
	TSubclassOf<class AOSY_CrashNodeActor> NodeFactory;


	// 노드 스폰하는 함수
	void spawnCrashNode();

	// 현재 시간
	float currentTime = 0;


};
