// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OSY_HiHatNodeActor.h"
#include "OSY_HiHatFactory.generated.h"

UCLASS()
class SMASH_API AOSY_HiHatFactory : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOSY_HiHatFactory();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category="MySettings")
	TSubclassOf<class AOSY_HiHatNodeActor> NodeFactory;

	//----------------------------
	// 오브젝트 풀을 저장할 배열 이면서 InActive노드를 담고 있겠지
	TArray<AOSY_HiHatNodeActor*> HiHatPool;

	// Active노드를 담을 리스트다.
	TArray<AOSY_HiHatNodeActor*> ActiveHiHatPool;

	//풀사이즈
	UPROPERTY(EditAnywhere, Category="MySettings")
	int32 HiHatPoolSize;

	// 스네어 노드 클래스에 대한 참조
	UPROPERTY(EditAnywhere, Category="MySettings")
    TSubclassOf<AOSY_HiHatNodeActor> NodeClass;

	int currentNodeIndex = 0;

	// 노드 스폰하는 함수
	void PoolChangeHN();

	// 현재 시간
	float currentTime = 0;

	TArray<float> spawnTimes =
	{ 
		6.5f,7.5f,8.f,8.5f,9.f,9.5f,10.f,10.5f,11.f,11.5f,12.f,12.5f,13.f,13.5f,15.5f,16.f,16.5f,17.f,17.5f,18.f,18.5f,19.f,19.5f,20.f,20.5f,21.f,21.5f,23.5f,24.f,24.5f,25.f,25.5f,26.f,26.5f,27.f,27.5f,28.f,28.5f,29.f,29.5f,30.f,30.5f,31.5f,32.f,32.5f,33.f,33.5f,34.f,34.5f,35.f,35.5f,36.f,36.5f,37.f,37.5f,38.f,38.5f,39.5f,40.f,40.5f,41.f,41.5f,42.f,42.5f,43.f,43.5f,44.f,44.5f,45.f,45.5f,46.f,46.5f,47.5f,48.f,48.5f,49.f,49.5f,50.f,50.5f,51.f,51.5f,52.f,52.5f,55.5f,56.f,56.5f,57.f,57.5f,58.f,58.5f,59.f,59.5f,60.f,60.5f,61.f,61.5f,62.f,62.5f,63.5f,64.f,64.5f,65.f,65.5f,66.f,66.5f,67.f,67.5f,68.f,68.5f,69.f,69.5f,70.f,70.5f,71.5f,72.f,72.5f,73.f,73.5f,74.f,74.5f,75.f,75.5f,76.f,76.5f,77.f,77.5f,78.f,78.5f,79.5f,80.f,80.5f,81.f,81.5f,82.f,82.5f,83.f,83.5f,84.f,84.5f,85.f,85.5f,87.5f,88.f,88.5f,89.f,89.5f,90.f,90.5f,91.f,91.5f,92.f,92.5f,93.f,93.5f,95.5f,96.f,96.5f,97.f,97.5f,98.f,98.5f,99.f,99.5f,100.f,100.5f,101.f,101.5f,102.f,102.5f

	};


	
};
