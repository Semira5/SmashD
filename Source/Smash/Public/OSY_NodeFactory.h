// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OSY_NodeFactory.generated.h"

UCLASS()
class SMASH_API AOSY_NodeFactory : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOSY_NodeFactory();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// 노드 스폰하는 함수
	void spawnNode();

	UPROPERTY(EditAnywhere, Category="MySettings")
	TSubclassOf<class AOSY_NodeActor> NodeFactory;

	// 현재 시간
	float currentTime=0;

};
