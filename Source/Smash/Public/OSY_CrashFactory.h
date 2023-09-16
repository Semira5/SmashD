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
	{ 28.68f,36.232f,40.008f,41.896f,43.784f,51.336f,58.888f,66.44f,73.992f,81.544f,87.444f,87.68f,89.096f,96.648f,107.976f,111.752f,119.304f,126.856f,134.408f,138.184f,141.252f,141.488f,141.96f,149.512f,155.412f,155.648f,156.12f,157.064f,164.616f,172.168f,179.72f,187.272f,194.824f,198.836f,199.544f,200.252f,200.488f,201.432f,202.376f
	};


};
