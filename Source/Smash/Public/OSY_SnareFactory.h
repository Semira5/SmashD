// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OSY_SnareNodeActor.h"
#include "OSY_SnareFactory.generated.h"

UCLASS()
class SMASH_API AOSY_SnareFactory : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOSY_SnareFactory();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(EditAnywhere, Category="MySettings")
	TSubclassOf<class AOSY_SnareNodeActor> NodeFactory;

	// 오브젝트 풀을 저장할 배열
	TArray<AOSY_SnareNodeActor*> SnarePool;

	// Active노드를 담을 리스트다.
	TArray<AOSY_SnareNodeActor*> ActiveSnarePool;

	//풀사이즈
	UPROPERTY(EditAnywhere, Category="MySettings")
	int32 SnarePoolSize;

	// 스네어 노드 클래스에 대한 참조
	UPROPERTY(EditAnywhere, Category="MySettings")
    TSubclassOf<AOSY_SnareNodeActor> NodeClass;
	
	int currentNodeIndex = 0;

	// 노드 스폰하는 함수
	void PoolChangeSN();

	// 현재 시간
	float currentTime = 0;

	TArray<float> spawnTimes =
	{ 
	6.5f,7.5f,8.5f,9.5f,10.5f,11.5f,12.5f,13.5f,14.f,14.25f,14.5f,14.75f,15.5f,16.5f,17.5f,18.5f,19.5f,20.5f,21.5f,22.f,22.25f,22.5f,22.75f,23.5f,24.5f,25.5f,26.5f,27.5f,28.5f,29.5f,30.5f,31.5f,32.5f,33.5f,34.5f,35.5f,36.5f,37.5f,38.5f,39.5f,40.5f,41.5f,42.5f,43.5f,44.5f,45.5f,46.5f,47.5f,48.5f,49.5f,50.5f,51.5f,52.5f,53.f,54.5f,55.5f,56.5f,57.5f,58.5f,59.5f,60.5f,61.5f,62.5f,63.5f,64.5f,65.5f,66.5f,67.5f,68.5f,69.5f,70.5f,71.5f,72.5f,73.5f,74.5f,75.5f,76.5f,77.5f,78.5f,79.5f,80.5f,81.5f,82.5f,83.5f,84.5f,85.5f,86.f,86.25f,86.5f,86.75f,87.5f,88.5f,89.5f,90.5f,91.5f,92.5f,93.5f,94.f,94.25f,94.5f,94.75f,95.5f,96.5f,97.5f,98.5f,99.5f,100.5f,101.5f,102.5f

	};

	

};
