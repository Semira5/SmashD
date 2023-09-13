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
#include "Components/BoxComponent.h"
#include "OSY_CrashNodeActor.h"
#include "OSY_HiHatNodeActor.h"
#include "OSY_RideNodeActor.h"
#include "OSY_SnareNodeActor.h"
#include "OSY_TomNodeActor.h"
#include <Kismet/GameplayStatics.h>

// Sets default values
ASmashCharacter::ASmashCharacter()
{

	PrimaryActorTick.bCanEverTick = true;

	bCanUseRightStick = true;

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

	leftcomp = CreateDefaultSubobject<UBoxComponent>(TEXT("leftcompBox"));
	leftcomp->SetupAttachment(leftStick);
	leftcomp->SetRelativeLocation(FVector(110.0f, 55.0f, -90.0f));
	leftcomp->SetRelativeScale3D(FVector(1.f, 1.f, 1.f));

	rightcomp = CreateDefaultSubobject<UBoxComponent>(TEXT("rightcompBox"));
	rightcomp->SetupAttachment(rightStick);
	rightcomp->SetRelativeLocation(FVector(110.0f, 55.0f, -90.0f));;
	rightcomp->SetRelativeScale3D(FVector(1.f, 1.f, 1.f));
}

// Called when the game starts or when spawned
void ASmashCharacter::BeginPlay()
{
	Super::BeginPlay();


	rightcomp->OnComponentBeginOverlap.AddDynamic(this, &ASmashCharacter::OnComponentRightBeginOverlap);
	leftcomp->OnComponentBeginOverlap.AddDynamic(this, &ASmashCharacter::OnComponentLeftBeginOverlap);

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



void ASmashCharacter::RightTriggerDown()
{
	//rightLog->SetText(FText::FromString("Right Trigger Down!"));
	bRightTriggerDown = true;
	CanPlayingDrumsRight();
}

void ASmashCharacter::RightTriggerUp()
{
	//rightLog->SetText(FText::FromString("Right Trigger Up!"));
	bRightTriggerDown = false;
	CanPlayingDrumsRight();
}

void ASmashCharacter::RightGripDown()
{
	//rightLog->SetText(FText::FromString("Right Grip Down!"));
	bRightGripDown = true;
	CanPlayingDrumsRight();
}

void ASmashCharacter::RightGripUp()
{
	//rightLog->SetText(FText::FromString("Right Grip Up!"));
	bRightGripDown = false;
	CanPlayingDrumsRight();
}


void ASmashCharacter::RightADown()
{
	rightLog->SetText(FText::FromString("Right A Button Down!"));

// 	사용자가 바라보고 있는 방향을 정면으로 다시 정렬(회전, 위치)
// 		UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
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
	CanPlayingDrumsLeft();
}

void ASmashCharacter::LeftTriggerUp()
{
	bLeftTriggerDown = false;
	CanPlayingDrumsLeft();
}

void ASmashCharacter::LeftGripDown()
{
	bLeftGripDown = true;
	CanPlayingDrumsLeft();
}

void ASmashCharacter::LeftGripUp()
{
	bLeftGripDown = false;
	CanPlayingDrumsLeft();
}

void ASmashCharacter::CanPlayingDrumsLeft()
{
	if (bLeftTriggerDown && bLeftGripDown)
	{
		APlayerController* pc = GetController<APlayerController>();

		leftLog->SetText(FText::FromString("Can Playing Drum"));

		//햅틱 이벤트(드럼 콜리젼 추가되면 조건식 추가하기)
		pc->PlayHapticEffect(smash_Haptic, EControllerHand::Left, 1.0f, false);

		bCanUseLeftStick = true;
	}
	else
	{
		leftLog->SetText(FText::FromString("Cant Playing Drum"));
	}
}

void ASmashCharacter::CanPlayingDrumsRight()
{
	if (bRightTriggerDown && bRightGripDown)
	{
		APlayerController* pc = GetController<APlayerController>();

		//드럼 콜리젼과 연결 -> 연주
		rightLog->SetText(FText::FromString("Can Playing Drum"));

		//햅틱 이벤트(드럼 콜리젼 추가되면 조건식 추가하기)
		pc->PlayHapticEffect(smash_Haptic, EControllerHand::Right, 1.0f, false);

		bCanUseRightStick = true;
	}
	else
	{
		rightLog->SetText(FText::FromString("Cant Playing Drum"));
	}
}

//왼쪽 충돌 이벤트
void ASmashCharacter::OnComponentLeftBeginOverlap(class UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	leftLog->SetText(FText::FromString("Collision!!"));
	APlayerController* pc = GetController<APlayerController>();
	AOSY_CrashNodeActor* CrashNodeActor = Cast<AOSY_CrashNodeActor>(OtherActor);
	AOSY_HiHatNodeActor* HiHatNodeActor = Cast<AOSY_HiHatNodeActor>(OtherActor);
	AOSY_RideNodeActor* RideNodeActor = Cast<AOSY_RideNodeActor>(OtherActor);
	AOSY_SnareNodeActor* SnarNodeActor = Cast<AOSY_SnareNodeActor>(OtherActor);
	AOSY_TomNodeActor* TomNodeActor = Cast<AOSY_TomNodeActor>(OtherActor);

	if (CrashNodeActor)
	{
		//Chash사운드 플레이
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), CrashSound, GetActorLocation());

		pc->PlayHapticEffect(smash_Haptic, EControllerHand::Left, 1.0f, false);

		OtherActor->Destroy();
		rightLog->SetText(FText::FromString("Overlap Chrash"));
	}

	if (HiHatNodeActor)
	{
		//HiHat사운드 플레이
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), HiHatSound, GetActorLocation());

		pc->PlayHapticEffect(smash_Haptic, EControllerHand::Left, 1.0f, false);

		OtherActor->Destroy();
	}

	if (RideNodeActor)
	{
		//Ride사운드 플레이
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), RideSound, GetActorLocation());

		pc->PlayHapticEffect(smash_Haptic, EControllerHand::Left, 1.0f, false);
		OtherActor->Destroy();

	}

	if (SnarNodeActor)
	{
		//Snar사운드 플레이
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), SnarSound, GetActorLocation());

		pc->PlayHapticEffect(smash_Haptic, EControllerHand::Left, 1.0f, false);

		OtherActor->Destroy();
	}

	if (TomNodeActor)
	{
		//Tom사운드 플레이
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), TomSound, GetActorLocation());

		pc->PlayHapticEffect(smash_Haptic, EControllerHand::Left, 1.0f, false);

		OtherActor->Destroy();
	}
}

//오른쪽 충돌 이벤트
void ASmashCharacter::OnComponentRightBeginOverlap(class UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//if (bCanUseRightStick == true)
	//{
	    rightLog->SetText(FText::FromString("Collision!!"));
		APlayerController* pc = GetController<APlayerController>();
		AOSY_CrashNodeActor* CrashNodeActor = Cast<AOSY_CrashNodeActor>(OtherActor);
		AOSY_HiHatNodeActor* HiHatNodeActor = Cast<AOSY_HiHatNodeActor>(OtherActor);
		AOSY_RideNodeActor* RideNodeActor = Cast<AOSY_RideNodeActor>(OtherActor);
		AOSY_SnareNodeActor* SnarNodeActor = Cast<AOSY_SnareNodeActor>(OtherActor);
		AOSY_TomNodeActor* TomNodeActor = Cast<AOSY_TomNodeActor>(OtherActor);
		 
		if (CrashNodeActor)
		{
			//Chash사운드 플레이
			UGameplayStatics::PlaySoundAtLocation(GetWorld(), CrashSound, GetActorLocation());

			pc->PlayHapticEffect(smash_Haptic, EControllerHand::Right, 1.0f, false);

			OtherActor->Destroy();
			rightLog->SetText(FText::FromString("Overlap Chrash"));
		}

		if (HiHatNodeActor)
		{
			//HiHat사운드 플레이
			UGameplayStatics::PlaySoundAtLocation(GetWorld(), HiHatSound, GetActorLocation());

			pc->PlayHapticEffect(smash_Haptic, EControllerHand::Right, 1.0f, false);

			OtherActor->Destroy();
		}

		if (RideNodeActor)
		{
			//Ride사운드 플레이
			UGameplayStatics::PlaySoundAtLocation(GetWorld(), RideSound, GetActorLocation());

			pc->PlayHapticEffect(smash_Haptic, EControllerHand::Right, 1.0f, false);
			OtherActor->Destroy();

		}

		if (SnarNodeActor)
		{
			//Snar사운드 플레이
			UGameplayStatics::PlaySoundAtLocation(GetWorld(), SnarSound, GetActorLocation());

			pc->PlayHapticEffect(smash_Haptic, EControllerHand::Right, 1.0f, false);

			OtherActor->Destroy();
		}

		if (TomNodeActor)
		{
			//Tom사운드 플레이
			UGameplayStatics::PlaySoundAtLocation(GetWorld(), TomSound, GetActorLocation());

			pc->PlayHapticEffect(smash_Haptic, EControllerHand::Right, 1.0f, false);

			OtherActor->Destroy();
		}
	//}
}





