// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OSY_Drum_Crash.generated.h"

UCLASS()
class SMASH_API AOSY_Drum_Crash : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOSY_Drum_Crash();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere,Category="MySettings")
	class USceneComponent* compScene;

	UPROPERTY(EditAnywhere,Category="MySettings")
	class UBoxComponent* compBox;

	UPROPERTY(EditAnywhere,Category="MySettings")
	class UStaticMeshComponent* compMesh;

	FVector OriginalScale;
	FTimerHandle ResizeTimerHandle;

	UFUNCTION()
	void OnComponentBeginOverlap( UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void ResetSize();
};
