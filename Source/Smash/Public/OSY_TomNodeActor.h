// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OSY_TomNodeActor.generated.h"

UCLASS()
class SMASH_API AOSY_TomNodeActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOSY_TomNodeActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// 노드 콜리전
	UPROPERTY(EditAnywhere,Category= MySettings)
	class UBoxComponent* compBox;

	// 노드 메시
	UPROPERTY(EditAnywhere,Category= MySettings)
	class UStaticMeshComponent* compMesh;

	// 이동에 필요한 속성
	float speed = 1;
	FVector direction;

	// 타겟 액터
	UPROPERTY(EditAnywhere,Category= MySettings)
	class AOSY_TomNodeEndActor* Target;

	UFUNCTION()
	void OnComponentBeginOverlap( UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


	FVector StartLocation;
	FVector TargetLocation;
	float CurrentLerpTime = 0.0f;
	float TotalLerpTime = 2.0f; // 목표 시간 (초) 설정 (여기서는 2초)


	void ActiveNode(const FVector& FactoryLoc, bool isActivation);

	bool isHidden = true;


};
