// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OSY_CrashNodeActor.h"
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
	TSubclassOf<class UIngame_Widget> IngameWidget;

	UPROPERTY(EditAnywhere, Category="MySettings")
	TSubclassOf<class AOSY_CrashNodeActor> NodeFactory;

	//----------------------------
	// 오브젝트 풀을 저장할 배열
	TArray<AOSY_CrashNodeActor*> CrashPool;

	// Active노드를 담을 리스트다.
	TArray<AOSY_CrashNodeActor*> ActiveCrashPool;

	//풀사이즈
	UPROPERTY(EditAnywhere, Category="MySettings")
	int32 CrashPoolSize;

	// 스네어 노드 클래스에 대한 참조
	UPROPERTY(EditAnywhere, Category="MySettings")
    TSubclassOf<AOSY_CrashNodeActor> NodeClass;

	int currentNodeIndex = 0;

	// 노드 스폰하는 함수
	void PoolChangeCN();

	// 현재 시간
	float currentTime = 0;

	TArray<float> spawnTimes =
	{ 
	7,15,23,31,39,47,53,55,63,71,79,87,95
	};


};
