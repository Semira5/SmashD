// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
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

	// ��� �����ϴ� �Լ�
	void spawnHiHatNode();

	// ���� �ð�
	float currentTime = 0;
};