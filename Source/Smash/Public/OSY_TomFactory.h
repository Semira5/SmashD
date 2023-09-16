// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OSY_TomNodeActor.h"
#include "OSY_TomFactory.generated.h"

UCLASS()
class SMASH_API AOSY_TomFactory : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOSY_TomFactory();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category="MySettings")
	TSubclassOf<class AOSY_TomNodeActor> NodeFactory;

	//----------------------------
	// 오브젝트 풀을 저장할 배열
	TArray<AOSY_TomNodeActor*> TomPool;

	// Active노드를 담을 리스트다.
	TArray<AOSY_TomNodeActor*> ActiveTomPool;

	//풀사이즈
	UPROPERTY(EditAnywhere, Category="MySettings")
	int32 TomPoolSize;

	// 스네어 노드 클래스에 대한 참조
	UPROPERTY(EditAnywhere, Category="MySettings")
    TSubclassOf<AOSY_TomNodeActor> NodeClass;

	int currentNodeIndex = 0;

	// 노드 스폰하는 함수
	void PoolChangeTN();

	// 현재 시간
	float currentTime = 0;

	TArray<float> spawnTimes =
	{ 42.368f,42.604f,42.84f,43.076f,43.312f,43.548f,110.1f,110.336f,110.572f,110.808f,111.044f,111.28f,111.516f,171.342f,171.46f,171.578f,171.696f,200.96f,201.904f


	};

	
};
