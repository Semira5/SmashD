// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SmashCharacter.generated.h"

UCLASS()
class SMASH_API ASmashCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASmashCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category="MySettings|Components")
	class UCameraComponent* hmdCam;

	UPROPERTY(EditAnywhere, Category="MySettings|Components")
	class UStaticMeshComponent* hmdMesh;

	UPROPERTY(EditAnywhere, Category="MySettings|Components")
	class UMotionControllerComponent* leftMotionController;

	UPROPERTY(EditAnywhere, Category="MySettings|Components")
	class UStaticMeshComponent* leftStick;
	
	UPROPERTY(EditAnywhere, Category="MySettings|Components")
	class UTextRenderComponent* leftLog;

	UPROPERTY(EditAnywhere, Category="MySettings|Components")
	class UMotionControllerComponent* rightMotionController;

	UPROPERTY(EditAnywhere, Category="MySettings|Components")
	class UStaticMeshComponent* rightStick;

	UPROPERTY(EditAnywhere, Category="MySettings|Components")
	class UTextRenderComponent* rightLog;

	UPROPERTY(EditAnywhere, Category="MySettings|Inputs")
	class UInputMappingContext* imc_VRmap;

	UPROPERTY(EditAnywhere, Category="MySettings|Inputs")
	TArray<class UInputAction*> inputActions;
};
