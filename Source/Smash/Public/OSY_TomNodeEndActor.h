// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OSY_TomNodeEndActor.generated.h"

UCLASS()
class SMASH_API AOSY_TomNodeEndActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOSY_TomNodeEndActor();

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

	

	UFUNCTION()
	void OnComponentBeginOverlap( UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
