// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SmashAudience.generated.h"

UCLASS()
class SMASH_API ASmashAudience : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASmashAudience();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditDefaultsOnly, Category="MySettings|Components")
	class USceneComponent* rootComp;

	UPROPERTY(EditDefaultsOnly, Category="MySettings")
	class UStaticMeshComponent* meshComp;

	UPROPERTY(EditDefaultsOnly, Category="MySettings")
	class UStaticMeshComponent* meshComp2;

	UPROPERTY(EditDefaultsOnly, Category="MySettings")
	class UStaticMeshComponent* meshComp3;

	UPROPERTY(EditDefaultsOnly, Category="MySettings")
	class UStaticMeshComponent* meshComp4;

	UPROPERTY(EditDefaultsOnly, Category="MySettings")
	class UStaticMeshComponent* meshComp5;
	
	UPROPERTY(EditDefaultsOnly, Category = "MySettings")
	FLinearColor baseColor;

private:
    class UMaterialInstanceDynamic* audMat;

};
