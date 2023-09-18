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
#include "Components/WidgetInteractionComponent.h"
#include "WidgetPointerComponent.h"
#include "OSY_Drum_HiHat.h"
#include "OSY_Drum_Crash.h"
#include "OSY_HiHatFactory.h"
#include "OSY_CrashFactory.h"
#include "OSY_SnareFactory.h"
#include "OSY_RideFactory.h"
#include "OSY_TomFactory.h"
#include "OSY_Drum_Ride.h"
#include "OSY_Drum_Snare.h"
#include "OSY_Drum_TomKick.h"
#include "OSY_CrashNodeEndActor.h"
#include "OSY_HiHatNodeEndActor.h"
#include "OSY_SnareNodeEndActor.h"
#include "OSY_RideNodeEndActor.h"
#include "OSY_TomNodeEndActor.h"

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

	//위젯
	rightWidgetPointer = CreateDefaultSubobject<UWidgetInteractionComponent>(TEXT("Right Widget Pointer"));
	rightWidgetPointer->SetupAttachment(rightStick);
	rightWidgetPointer->SetRelativeLocation(FVector(55.0f, 56.0f, -90.0f));

	widgetPointerComp = CreateDefaultSubobject<UWidgetPointerComponent>(TEXT("Widget Pointer Component"));
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

	CrashFactory =Cast<AOSY_CrashFactory>(UGameplayStatics::GetActorOfClass(GetWorld(), AOSY_CrashFactory::StaticClass()));
	HiHatFactory =Cast<AOSY_HiHatFactory>(UGameplayStatics::GetActorOfClass(GetWorld(), AOSY_HiHatFactory::StaticClass()));
	SnareFactory =Cast<AOSY_SnareFactory>(UGameplayStatics::GetActorOfClass(GetWorld(), AOSY_SnareFactory::StaticClass()));
	RideFactory =Cast<AOSY_RideFactory>(UGameplayStatics::GetActorOfClass(GetWorld(), AOSY_RideFactory::StaticClass()));
	TomFactory =Cast<AOSY_TomFactory>(UGameplayStatics::GetActorOfClass(GetWorld(), AOSY_TomFactory::StaticClass()));


	CrashEnd =Cast<AOSY_CrashNodeEndActor>(UGameplayStatics::GetActorOfClass(GetWorld(), AOSY_CrashNodeEndActor::StaticClass()));
	HiHatEnd =Cast<AOSY_HiHatNodeEndActor>(UGameplayStatics::GetActorOfClass(GetWorld(), AOSY_HiHatNodeEndActor::StaticClass()));
	SnareEnd =Cast<AOSY_SnareNodeEndActor>(UGameplayStatics::GetActorOfClass(GetWorld(), AOSY_SnareNodeEndActor::StaticClass()));
	RideEnd =Cast<AOSY_RideNodeEndActor>(UGameplayStatics::GetActorOfClass(GetWorld(), AOSY_RideNodeEndActor::StaticClass()));
	TomEnd =Cast<AOSY_TomNodeEndActor>(UGameplayStatics::GetActorOfClass(GetWorld(), AOSY_TomNodeEndActor::StaticClass()));




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

		widgetPointerComp->SetupPlayerInputComponent(enhancedInputComponent, inputActions);
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
	if (bCanUseLeftStick)
	{
		leftLog->SetText(FText::FromString("Collision!!"));
		APlayerController* pc = GetController<APlayerController>();



		AOSY_Drum_Crash* Crash = Cast<AOSY_Drum_Crash>(OtherActor);
		if (Crash)
		{
			// 사운드를 재생한다.
			UGameplayStatics::PlaySoundAtLocation(GetWorld(), CrashSound, GetActorLocation());
			// 햅틱이 가능하게 한다.
			pc->PlayHapticEffect(smash_Haptic, EControllerHand::Left, 1.0f, false);

			// 만약 팩토리가 존재하고, 앤드가 존재하면
			if (CrashFactory != nullptr && CrashEnd != nullptr)
			{
				// 만약 오브젝트 풀에 아무것도 없으면
				if (CrashFactory->ActiveCrashPool.Num() <= 0)
				{
					return;
				}
				// 존재한다면
				else
				{
					// 거리를 측정해
					FVector cDVector = CrashEnd->GetActorLocation() - CrashFactory->ActiveCrashPool[0]->GetActorLocation();
					cDistance = cDVector.Size();

					// 만약 앤드와 0번의 거리가 100보다 크면 아무것도 하지마
					if (cDistance >= 100)
					{
						return;
					}
					else
					{

						//액티브풀에 담긴 상태일테니까
						// 활성화를 끈 다음에
						CrashFactory->ActiveCrashPool[0]->ActiveNode(FVector::ZeroVector, false);
						// 그걸 풀에 넣고
						CrashFactory->CrashPool.Add(CrashFactory->ActiveCrashPool[0]);
						// 액티브 풀에서는 빼버려
						CrashFactory->ActiveCrashPool.RemoveAt(0);
					}

				}
			}

		}

		AOSY_Drum_HiHat* HiHat = Cast<AOSY_Drum_HiHat>(OtherActor);
		if (HiHat)
		{
			// 사운드를 재생한다.
			UGameplayStatics::PlaySoundAtLocation(GetWorld(), HiHatSound, GetActorLocation());
			// 햅틱이 가능하게 한다.
			pc->PlayHapticEffect(smash_Haptic, EControllerHand::Left, 1.0f, false);

			if (HiHatFactory != nullptr && HiHatEnd != nullptr)
			{
				if (HiHatFactory->ActiveHiHatPool.Num() <= 0)
				{
					return;
				}
				else
				{
					FVector hDVector = HiHatEnd->GetActorLocation() - HiHatFactory->ActiveHiHatPool[0]->GetActorLocation();
					hDistance = hDVector.Size();

					if (hDistance >= 100)
					{
						return;
					}
					else
					{
						HiHatFactory->ActiveHiHatPool[0]->ActiveNode(FVector::ZeroVector, false);
						HiHatFactory->HiHatPool.Add(HiHatFactory->ActiveHiHatPool[0]);
						HiHatFactory->ActiveHiHatPool.RemoveAt(0);

					}

				}
			}

		}

		AOSY_Drum_Snare* Snare = Cast<AOSY_Drum_Snare>(OtherActor);
		if (Snare)
		{
			// 사운드를 재생한다.
			UGameplayStatics::PlaySoundAtLocation(GetWorld(), RideSound, GetActorLocation());
			// 햅틱이 가능하게 한다.
			pc->PlayHapticEffect(smash_Haptic, EControllerHand::Left, 1.0f, false);

			if (SnareFactory != nullptr && SnareEnd != nullptr)
			{
				if (SnareFactory->ActiveSnarePool.Num() <= 0)
				{
					return;
				}
				else
				{
					FVector sDVector = SnareEnd->GetActorLocation() - SnareFactory->ActiveSnarePool[0]->GetActorLocation();
					sDistance = sDVector.Size();

					if (sDistance >= 100)
					{
						return;
					}
					else
					{
						SnareFactory->ActiveSnarePool[0]->ActiveNode(FVector::ZeroVector, false);
						SnareFactory->SnarePool.Add(SnareFactory->ActiveSnarePool[0]);
						SnareFactory->ActiveSnarePool.RemoveAt(0);
					}
				}
			}

		}

		AOSY_Drum_Ride* Ride = Cast<AOSY_Drum_Ride>(OtherActor);
		if (Ride)
		{
			// 사운드를 재생한다.
			UGameplayStatics::PlaySoundAtLocation(GetWorld(), RideSound, GetActorLocation());
			// 햅틱이 가능하게 한다.
			pc->PlayHapticEffect(smash_Haptic, EControllerHand::Left, 1.0f, false);

			if (RideFactory != nullptr && RideEnd != nullptr)
			{
				if (RideFactory->ActiveRidePool.Num() <= 0)
				{
					return;
				}
				else
				{
					FVector rDVector = RideEnd->GetActorLocation() - RideFactory->ActiveRidePool[0]->GetActorLocation();
					rDistance = rDVector.Size();

					if (rDistance >= 100)
					{
						RideFactory->ActiveRidePool[0]->ActiveNode(FVector::ZeroVector, false);
						RideFactory->RidePool.Add(RideFactory->ActiveRidePool[0]);
						RideFactory->ActiveRidePool.RemoveAt(0);
					}
				}
			}

		}

		AOSY_Drum_TomKick* Tom = Cast<AOSY_Drum_TomKick>(OtherActor);
		if (Tom)
		{
			// 사운드를 재생한다.
			UGameplayStatics::PlaySoundAtLocation(GetWorld(), TomSound, GetActorLocation());
			// 햅틱이 가능하게 한다.
			pc->PlayHapticEffect(smash_Haptic, EControllerHand::Left, 1.0f, false);

			if (TomFactory != nullptr && TomEnd != nullptr)
			{
				if (TomFactory->ActiveTomPool.Num() <= 0)
				{
					return;
				}
				else
				{
					FVector tDVector = TomEnd->GetActorLocation() - TomFactory->ActiveTomPool[0]->GetActorLocation();
					tDistance = tDVector.Size();

					if (tDistance >= 100)
					{
						return;
					}
					else
					{
						TomFactory->ActiveTomPool[0]->ActiveNode(FVector::ZeroVector, false);
						TomFactory->TomPool.Add(TomFactory->ActiveTomPool[0]);
						TomFactory->ActiveTomPool.RemoveAt(0);
					}
				}
			}

		}


	}
}

//오른쪽 충돌 이벤트
void ASmashCharacter::OnComponentRightBeginOverlap(class UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (bCanUseRightStick)
	{
	    rightLog->SetText(FText::FromString("Collision!!"));
		APlayerController* pc = GetController<APlayerController>();

		
	
		AOSY_Drum_Crash* Crash = Cast<AOSY_Drum_Crash>(OtherActor);
		if (Crash)
		{
			// 사운드를 재생한다.
			UGameplayStatics::PlaySoundAtLocation(GetWorld(), CrashSound, GetActorLocation());
			// 햅틱이 가능하게 한다.
			pc->PlayHapticEffect(smash_Haptic, EControllerHand::Right, 1.0f, false);

			
			// 만약 팩토리가 존재하고, 앤드가 존재하면
			if (CrashFactory != nullptr && CrashEnd != nullptr)
			{
				// 만약 오브젝트 풀에 아무것도 없으면
				if (CrashFactory->ActiveCrashPool.Num() <= 0)
				{
					return;
				}
				// 존재한다면
				else
				{
					// 거리를 측정해
					FVector cDVector= CrashEnd->GetActorLocation()-CrashFactory->ActiveCrashPool[0]->GetActorLocation();
					cDistance = cDVector.Size();

					// 만약 앤드와 0번의 거리가 100보다 크면 아무것도 하지마
					if (cDistance >= 100)
					{
						return;
					}
					else
					{

						//액티브풀에 담긴 상태일테니까
						// 활성화를 끈 다음에
						CrashFactory->ActiveCrashPool[0]->ActiveNode(FVector::ZeroVector, false);
						// 그걸 풀에 넣고
						CrashFactory->CrashPool.Add(CrashFactory->ActiveCrashPool[0]);
						// 액티브 풀에서는 빼버려
						CrashFactory->ActiveCrashPool.RemoveAt(0);
					}

				}
			}
		}

		AOSY_Drum_HiHat* HiHat = Cast<AOSY_Drum_HiHat>(OtherActor);
		if (HiHat)
		{
			// 사운드를 재생한다.
			UGameplayStatics::PlaySoundAtLocation(GetWorld(), HiHatSound, GetActorLocation());
			// 햅틱이 가능하게 한다.
			pc->PlayHapticEffect(smash_Haptic, EControllerHand::Right, 1.0f, false);


			if (HiHatFactory != nullptr && HiHatEnd != nullptr)
			{
				if (HiHatFactory->ActiveHiHatPool.Num() <=0)
				{
					return;
				}
				else
				{
					FVector hDVector = HiHatEnd->GetActorLocation() - HiHatFactory->ActiveHiHatPool[0]->GetActorLocation();
					hDistance = hDVector.Size();

					if (hDistance >= 100)
					{
						return;
					}
					else
					{
						HiHatFactory->ActiveHiHatPool[0]->ActiveNode(FVector::ZeroVector, false);
						HiHatFactory->HiHatPool.Add(HiHatFactory->ActiveHiHatPool[0]);
						HiHatFactory->ActiveHiHatPool.RemoveAt(0);

					}

				}
			}

		}

		AOSY_Drum_Snare* Snare = Cast<AOSY_Drum_Snare>(OtherActor);
		if (Snare)
		{
			// 사운드를 재생한다.
			UGameplayStatics::PlaySoundAtLocation(GetWorld(), RideSound, GetActorLocation());
			// 햅틱이 가능하게 한다.
			pc->PlayHapticEffect(smash_Haptic, EControllerHand::Right, 1.0f, false);

			if (SnareFactory != nullptr && SnareEnd != nullptr)
			{
				if (SnareFactory->ActiveSnarePool.Num() <= 0)
				{
					return;
				}
				else
				{
					FVector sDVector = SnareEnd->GetActorLocation()-SnareFactory->ActiveSnarePool[0]->GetActorLocation();
					sDistance = sDVector.Size();

					if (sDistance >= 100)
					{
						return;
					}
					else
					{	
						SnareFactory->ActiveSnarePool[0]->ActiveNode(FVector::ZeroVector, false);
						SnareFactory->SnarePool.Add(SnareFactory->ActiveSnarePool[0]);
						SnareFactory->ActiveSnarePool.RemoveAt(0);
					}
				}
			}

		}

		AOSY_Drum_Ride* Ride = Cast<AOSY_Drum_Ride>(OtherActor);
		if (Ride)
		{
			// 사운드를 재생한다.
			UGameplayStatics::PlaySoundAtLocation(GetWorld(), RideSound, GetActorLocation());
			// 햅틱이 가능하게 한다.
			pc->PlayHapticEffect(smash_Haptic, EControllerHand::Right, 1.0f, false);

			if (RideFactory != nullptr && RideEnd != nullptr)
			{
				if (RideFactory->ActiveRidePool.Num() <= 0)
				{
					return;
				}
				else
				{
					FVector rDVector = RideEnd->GetActorLocation()-RideFactory->ActiveRidePool[0]->GetActorLocation();
					rDistance = rDVector.Size();

					if (rDistance >= 100)
					{
						RideFactory->ActiveRidePool[0]->ActiveNode(FVector::ZeroVector, false);
						RideFactory->RidePool.Add(RideFactory->ActiveRidePool[0]);
						RideFactory->ActiveRidePool.RemoveAt(0);
					}
				}
			}
		}

		AOSY_Drum_TomKick* Tom = Cast<AOSY_Drum_TomKick>(OtherActor);
		if (Tom)
		{
			// 사운드를 재생한다.
			UGameplayStatics::PlaySoundAtLocation(GetWorld(), TomSound, GetActorLocation());
			// 햅틱이 가능하게 한다.
			pc->PlayHapticEffect(smash_Haptic, EControllerHand::Right, 1.0f, false);

			if (TomFactory != nullptr && TomEnd != nullptr)
			{
				if (TomFactory->ActiveTomPool.Num() <= 0)
				{
					return;
				}
				else
				{
					FVector tDVector = TomEnd->GetActorLocation()-TomFactory->ActiveTomPool[0]->GetActorLocation();
					tDistance = tDVector.Size();

					if (tDistance >= 100)
					{
						return;
					}
					else
					{
						TomFactory->ActiveTomPool[0]->ActiveNode(FVector::ZeroVector, false);
						TomFactory->TomPool.Add(TomFactory->ActiveTomPool[0]);
						TomFactory->ActiveTomPool.RemoveAt(0);
					}
				}
			}
			
		}

		
	}
}





