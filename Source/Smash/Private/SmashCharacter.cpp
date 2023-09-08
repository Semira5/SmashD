// Fill out your copyright notice in the Description page of Project Settings.


#include "SmashCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "MotionControllerComponent.h"
#include "Components/TextRenderComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

// Sets default values
ASmashCharacter::ASmashCharacter()
{
 
	PrimaryActorTick.bCanEverTick = true;

	hmdCam = CreateDefaultSubobject<UCameraComponent>(TEXT("HMD Camera"));
	hmdCam->SetupAttachment(RootComponent);

	hmdMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("HMD Mesh"));
	hmdMesh->SetupAttachment(hmdCam);

	leftMotionController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("Left MotionController"));
	leftMotionController->SetupAttachment(RootComponent);
	leftMotionController->SetTrackingMotionSource(FName("Left"));

	leftStick = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Left Stick Mesh"));
	leftStick->SetupAttachment(leftMotionController);

	leftLog = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Left Log"));
	leftLog->SetupAttachment(leftMotionController);
	leftLog->SetRelativeLocation(FVector(70, -40, 0));
	leftLog->SetRelativeRotation(FRotator(0, 180, 0));
	leftLog->SetTextRenderColor(FColor(255, 255, 0, 255));
	leftLog->SetHorizontalAlignment(EHTA_Center);
	leftLog->SetVerticalAlignment(EVRTA_TextCenter);

	rightMotionController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("Right MotionController"));
	rightMotionController->SetupAttachment(RootComponent);
	rightMotionController->SetTrackingMotionSource(FName("Right"));

	rightStick = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Right Stick Mesh"));
	rightStick->SetupAttachment(rightMotionController);

	rightLog = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Right Log"));
	rightLog->SetupAttachment(rightMotionController);
	rightLog->SetRelativeLocation(FVector(70, 40, 0));
	rightLog->SetRelativeRotation(FRotator(0, 180, 0));
	rightLog->SetTextRenderColor(FColor(255, 255, 0, 255));
	rightLog->SetHorizontalAlignment(EHTA_Center);
	rightLog->SetVerticalAlignment(EVRTA_TextCenter);

}

// Called when the game starts or when spawned
void ASmashCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	leftLog->SetText(FText::FromString("1"));
	rightLog->SetText(FText::FromString("2"));

	//머리 장비 기준점 설정
	UHeadMountedDisplayFunctionLibrary::SetTrackingOrigin(EHMDTrackingOrigin::Stage);

	APlayerController* pc = GetController<APlayerController>();
	if (pc != nullptr)
	{
		UEnhancedInputLocalPlayerSubsystem* subSys = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(pc->GetLocalPlayer());

		if (subSys != nullptr)
		{
			subSys->AddMappingContext(imc_VRmap, 0);
		}
	}
}

// Called every frame
void ASmashCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASmashCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* enhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (enhancedInputComponent != nullptr)
	{
		enhancedInputComponent->BindAction(inputActions[0], ETriggerEvent::Started, this, &ASmashCharacter::RightTriggerDown);
		enhancedInputComponent->BindAction(inputActions[0], ETriggerEvent::Completed, this, &ASmashCharacter::RightTriggerUp);
		enhancedInputComponent->BindAction(inputActions[1], ETriggerEvent::Started, this, &ASmashCharacter::RightGripDown);
		enhancedInputComponent->BindAction(inputActions[1], ETriggerEvent::Completed, this, &ASmashCharacter::RightGripUp);
		enhancedInputComponent->BindAction(inputActions[2], ETriggerEvent::Started, this, &ASmashCharacter::RightADown);
		enhancedInputComponent->BindAction(inputActions[2], ETriggerEvent::Completed, this, &ASmashCharacter::RightAUp);
		enhancedInputComponent->BindAction(inputActions[3], ETriggerEvent::Started, this, &ASmashCharacter::RightBDown);
		enhancedInputComponent->BindAction(inputActions[3], ETriggerEvent::Completed, this, &ASmashCharacter::RightBUp);

		enhancedInputComponent->BindAction(inputActions[4], ETriggerEvent::Started, this, &ASmashCharacter::LeftTriggerDown);
		enhancedInputComponent->BindAction(inputActions[4], ETriggerEvent::Completed, this, &ASmashCharacter::LeftTriggerUp);
		enhancedInputComponent->BindAction(inputActions[5], ETriggerEvent::Started, this, &ASmashCharacter::LeftGripDown);
		enhancedInputComponent->BindAction(inputActions[5], ETriggerEvent::Completed, this, &ASmashCharacter::LeftGripUp);
	}
}
//
void ASmashCharacter::RightTriggerDown()
{
	//rightLog->SetText(FText::FromString("Right Trigger Down!"));
	bRightTriggerDown = true;
	CanPlayingDrums();
}

void ASmashCharacter::RightTriggerUp()
{
	//rightLog->SetText(FText::FromString("Right Trigger Up!"));
	bRightTriggerDown = false;
	CanPlayingDrums();
}

void ASmashCharacter::RightGripDown()
{
	//rightLog->SetText(FText::FromString("Right Grip Down!"));
	bRightGripDown = true;
	CanPlayingDrums();
}

void ASmashCharacter::RightGripUp()
{
	//rightLog->SetText(FText::FromString("Right Grip Up!"));
	bRightGripDown = false;
	CanPlayingDrums();
}


void ASmashCharacter::RightADown()
{
	rightLog->SetText(FText::FromString("Right A Button Down!"));

	// 사용자가 바라보고 있는 방향을 정면으로 다시 정렬(회전, 위치)
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void ASmashCharacter::RightAUp()
{
	rightLog->SetText(FText::FromString("Right A Button Up!"));
}

void ASmashCharacter::RightBDown()
{
	rightLog->SetText(FText::FromString("Right B Button Down!"));
}

void ASmashCharacter::RightBUp()
{
	rightLog->SetText(FText::FromString("Right B Button Up!"));
}

void ASmashCharacter::LeftTriggerDown()
{
    bLeftTriggerDown = true;
	CanPlayingDrums();
}

void ASmashCharacter::LeftTriggerUp()
{
	bLeftTriggerDown = false;
	CanPlayingDrums();
}

void ASmashCharacter::LeftGripDown()
{
    bLeftGripDown = true;
	CanPlayingDrums();
}

void ASmashCharacter::LeftGripUp()
{
	bLeftGripDown = false;
	CanPlayingDrums();
}

void ASmashCharacter::CanPlayingDrums()
{
	if (bRightTriggerDown && bRightGripDown && bLeftTriggerDown && bLeftGripDown)
	{
		//드럼 콜리젼과 연결 -> 연주
		rightLog->SetText(FText::FromString("Can Playing Drum"));
		leftLog->SetText(FText::FromString("Can Playing Drum"));
	}
	else
	{
		rightLog->SetText(FText::FromString("Cant Playing Drum"));
		leftLog->SetText(FText::FromString("Cant Playing Drum"));
	}
}



