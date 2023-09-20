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
	// ������Ʈ Ǯ�� ������ �迭
	TArray<AOSY_TomNodeActor*> TomPool;

	// Active��带 ���� ����Ʈ��.
	TArray<AOSY_TomNodeActor*> ActiveTomPool;

	//Ǯ������
	UPROPERTY(EditAnywhere, Category="MySettings")
	int32 TomPoolSize;

	// ���׾� ��� Ŭ������ ���� ����
	UPROPERTY(EditAnywhere, Category="MySettings")
    TSubclassOf<AOSY_TomNodeActor> NodeClass;

	int currentNodeIndex = 0;

	// ��� �����ϴ� �Լ�
	void PoolChangeTN();

	// ���� �ð�
	float currentTime = 0;

	TArray<float> spawnTimes =
	{ 
1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31,33,35,37,39,41,43,45,47,49,51,53,55,57,59,61,63,65,67,69,71,73,75,77,79,81,83,85,87,89,91,93,95,97,99.101




	};

	
};
