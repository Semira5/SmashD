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
	// ������Ʈ Ǯ�� ������ �迭
	TArray<AOSY_CrashNodeActor*> CrashPool;

	// Active��带 ���� ����Ʈ��.
	TArray<AOSY_CrashNodeActor*> ActiveCrashPool;

	//Ǯ������
	UPROPERTY(EditAnywhere, Category="MySettings")
	int32 CrashPoolSize;

	// ���׾� ��� Ŭ������ ���� ����
	UPROPERTY(EditAnywhere, Category="MySettings")
    TSubclassOf<AOSY_CrashNodeActor> NodeClass;

	int currentNodeIndex = 0;

	// ��� �����ϴ� �Լ�
	void PoolChangeCN();

	// ���� �ð�
	float currentTime = 0;

	TArray<float> spawnTimes =
	{ 
	7,15,23,31,39,47,53,55,63,71,79,87,95
	};


};
