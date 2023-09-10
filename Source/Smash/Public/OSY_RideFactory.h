// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
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

	// ��� �����ϴ� �Լ�
	void spawnRidehNode();

	// ���� �ð�
	float currentTime = 0;

};
