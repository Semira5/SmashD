// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OSY_RideNodeActor.h"
#include "OSY_RideFactory.generated.h"

UCLASS()
class SMASH_API AOSY_RideFactory : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOSY_RideFactory();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category="MySettings")
	TSubclassOf<class AOSY_RideNodeActor> NodeFactory;

	// ������Ʈ Ǯ�� ������ �迭
	TArray<AOSY_RideNodeActor*> RidePool;

	// Active��带 ���� ����Ʈ��.
	TArray<AOSY_RideNodeActor*> ActiveRidePool;

	//Ǯ������
	UPROPERTY(EditAnywhere, Category="MySettings")
	int32 RidePoolSize;

	// ���׾� ��� Ŭ������ ���� ����
	UPROPERTY(EditAnywhere, Category="MySettings")
    TSubclassOf<AOSY_RideNodeActor> NodeClass;

	int currentNodeIndex = 0;

	UPROPERTY(EditDefaultsOnly, Category="MySettings")
	class USoundBase* KickSound;

	// ��� �����ϴ� �Լ�
	void PoolChangeRN();

	// ���� �ð�
	float currentTime = 0;

	TArray<float> spawnTimes =
	{ 
	7.25f,9,10,11,12,13,14,15,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103

	};



};
