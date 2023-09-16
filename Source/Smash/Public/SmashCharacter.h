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

	UFUNCTION()
	void OnComponentLeftBeginOverlap(class UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnComponentRightBeginOverlap(class UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

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

	UPROPERTY(EditAnywhere,Category="MySettings")
	class UBoxComponent* rightcomp;
	
	UPROPERTY(EditAnywhere,Category="MySettings")
	class UBoxComponent* leftcomp;

	UPROPERTY(EditDefaultsOnly, Category="MySettings")
	class USoundBase* CrashSound;

	UPROPERTY(EditDefaultsOnly, Category="MySettings")
	class USoundBase* HiHatSound;

	UPROPERTY(EditDefaultsOnly, Category="MySettings")
	class USoundBase* RideSound;

	UPROPERTY(EditDefaultsOnly, Category="MySettings")
	class USoundBase* SnarSound;

	UPROPERTY(EditDefaultsOnly, Category="MySettings")
	class USoundBase* TomSound;

	UPROPERTY(EditDefaultsOnly, Category="MySettings")
	class UWidgetInteractionComponent* rightWidgetPointer;

	UPROPERTY(EditDefaultsOnly, Category="MySettings")
	class UWidgetPointerComponent* widgetPointerComp;

	UPROPERTY(EditAnywhere, Category="MySettings|Inputs")
	TArray<class UInputAction*> inputActions;
	//����(��ƽ)ȿ�� �߰�
	UPROPERTY(EditAnywhere, Category="MySettings")
	class UHapticFeedbackEffect_Base* smash_Haptic;


private:
	void RightTriggerDown();
	void RightTriggerUp();
	void RightGripDown();
	void RightGripUp();
	void RightADown();
	void RightAUp();
	void RightBDown();
	void RightBUp();

	void LeftTriggerDown();
	void LeftTriggerUp();
	void LeftGripDown();
	void LeftGripUp();
	
	void CanPlayingDrumsLeft();
	void CanPlayingDrumsRight();

	bool bRightTriggerDown = false;
	bool bRightGripDown = false;
	bool bLeftTriggerDown = false;
	bool bLeftGripDown = false;
	bool bCanUseLeftStick = false;
	bool bCanUseRightStick = false;

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
};
