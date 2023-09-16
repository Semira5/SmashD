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
	{ 42.368f,42.604f,42.84f,43.076f,43.312f,43.548f,44.256f,45.2f,46.144f,47.088f,48.032f,48.976f,49.92f,50.864f,51.808f,52.752f,53.696f,54.64f,55.584f,56.528f,57.472f,58.18f,58.298f,58.416f,58.534f,58.652f,58.77f,59.36f,60.304f,61.248f,62.192f,63.136f,64.08f,65.024f,65.968f,66.912f,67.856f,68.8f,69.744f,70.688f,71.632f,72.34f,72.576f,73.284f,73.402f,73.52f,73.638f,73.756f,73.874f,74.464f,75.408f,76.352f,77.296f,78.24f,79.184f,80.128f,81.072f,82.016f,82.96f,83.904f,84.848f,85.792f,86.736f,87.444f,87.68f,89.568f,90.512f,91.456f,92.4f,93.344f,94.288f,95.232f,96.176f,97.12f,98.064f,99.008f,99.952f,100.896f,101.84f,102.784f,103.728f,104.672f,105.616f,106.56f,107.504f,110.1f,110.336f,110.572f,110.808f,111.044f,111.28f,111.516f,112.224f,113.168f,114.112f,115.056f,116.f,116.944f,117.888f,118.832f,119.776f,120.72f,121.664f,122.608f,123.552f,124.496f,126.148f,126.266f,126.384f,126.502f,126.62f,126.738f,127.328f,128.272f,129.216f,130.16f,131.104f,132.048f,132.992f,133.936f,134.88f,135.824f,137.476f,137.594f,137.712f,137.83f,137.948f,138.066f,141.252f,141.488f,142.432f,143.376f,144.32f,145.264f,146.208f,147.152f,148.096f,149.04f,149.984f,150.928f,151.872f,152.816f,153.76f,154.704f,155.412f,155.648f,156.356f,156.474f,156.592f,156.71f,156.828f,156.946f,157.536f,158.48f,159.424f,160.368f,161.312f,162.256f,163.2f,164.144f,165.088f,166.032f,166.976f,167.92f,168.864f,169.808f,170.516f,170.634f,170.752f,170.87f,170.988f,171.106f,171.224f,171.342f,171.932f,172.05f,172.64f,173.584f,174.528f,175.472f,176.416f,177.36f,178.304f,179.248f,180.192f,181.136f,182.08f,183.024f,183.968f,184.912f,185.856f,186.564f,186.682f,186.8f,186.918f,187.036f,187.154f,187.744f,188.688f,189.632f,190.576f,191.52f,192.464f,193.998f,194.706f,195.296f,196.24f,197.184f,198.128f,198.836f,199.544f,200.252f,200.488f,201.432f


	};

	

};
