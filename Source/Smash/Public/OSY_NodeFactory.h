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

	TArray<float> spawnTimes =
	{ 0.96875f,2.21875f,3.46875f,4.71875f,5.96875f,7.21875f,8.46875f,9.71875f,10.96875f,12.21875f,13.46875f,14.71875f,15.96875f,17.21875f,19.71875f,16.96875f,18.21875f,19.46875f,20.71875f,21.96875f,23.21875f,24.46875f,29.71875f,26.96875f,28.21875f,29.46875f,34.71875f,31.96875f,33.21875f,40.96875f,42.21875f,43.46875f,44.71875f,45.96875f,47.21875f,48.46875f,49.71875f,50.96875f,48.21875f,49.46875f,50.71875f,55.96875f,53.21875f,54.46875f,55.71875f,56.96875f,58.21875f,59.46875f,60.71875f,65.96875f,63.21875f,64.46875f,65.71875f,70.96875f,68.21875f,69.46875f,77.21875f,78.46875f,79.71875f,80.96875f,82.21875f,83.46875f,84.71875f,85.96875f,87.21875f,88.46875f,89.71875f,90.96875f,92.21875f,93.46875f,94.71875f,95.96875f,97.21875f,98.46875f,99.71875f,100.96875f,102.21875f,103.46875f,104.71875f,105.96875f,107.21875f,108.46875f,109.71875f,110.96875f,112.21875f,109.46875f,110.71875f,111.96875f,117.21875f,114.46875f,115.71875f,116.96875f,122.21875f,123.46875f,124.71875f,125.96875f,127.21875f,128.46875f,129.71875f,130.96875f,133.46875f,134.71875f,135.96875f,137.21875f,138.46875f,139.71875f,140.96875f,142.21875f,143.46875f,144.71875f,145.96875f,147.21875f,148.46875f,149.71875f,150.96875f,152.21875f,153.46875f,154.71875f,155.96875f



	};

};
