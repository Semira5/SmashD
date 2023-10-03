// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OSY_NodeDestroyZone.generated.h"

UCLASS()
class SMASH_API AOSY_NodeDestroyZone : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOSY_NodeDestroyZone();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	// 필요속성 : 박스 충돌체
	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* boxComp;
	UPROPERTY(VisibleAnywhere)
	bool isOverlap = true;

	UFUNCTION()
	void OnComponentBeginOverlap( UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	float current = 0;

	int missCount = 0;


	UPROPERTY()
	class AOSY_CrashFactory* CrashFactory;
	UPROPERTY()
	class AOSY_HiHatFactory* HiHatFactory;
	UPROPERTY()
	class AOSY_SnareFactory* SnareFactory;
	UPROPERTY()
	class AOSY_RideFactory* RideFactory;
	UPROPERTY()
	class AOSY_TomFactory* TomFactory;

	UPROPERTY()
	class AOSY_Miss* missFac;

};
