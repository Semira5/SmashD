// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OSY_SnareNodeActor.generated.h"

UCLASS()
class SMASH_API AOSY_SnareNodeActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOSY_SnareNodeActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// ��� �ݸ���
	UPROPERTY(EditAnywhere,Category= MySettings)
	class UBoxComponent* compBox;

	// ��� �޽�
	UPROPERTY(EditAnywhere,Category= MySettings)
	class UStaticMeshComponent* compMesh;

	// �̵��� �ʿ��� �Ӽ�
	float speed = 1;
	FVector direction;

	// Ÿ�� ����
	UPROPERTY(EditAnywhere,Category= MySettings)
	class AOSY_SnareNodeEndActor* Target;

	UFUNCTION()
	void OnComponentBeginOverlap( UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


	FVector StartLocation;
	FVector TargetLocation;
	float CurrentLerpTime = 0.0f;
	float TotalLerpTime = 2.0f; // ��ǥ �ð� (��) ���� (���⼭�� 2��)

};
