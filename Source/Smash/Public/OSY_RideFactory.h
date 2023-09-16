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

	// ��� �����ϴ� �Լ�
	void PoolChangeRN();

	// ���� �ð�
	float currentTime = 0;

	TArray<float> spawnTimes =
	{ 40.008f,138.184f,200.96f,201.904f,202.376f

	};



};
