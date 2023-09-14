// Fill out your copyright notice in the Description page of Project Settings.


#include "OSY_CrashNodeActor.h"
#include "Components/BoxComponent.h"
#include <Kismet/GameplayStatics.h>
#include "OSY_CrashNodeEndActor.h"
#include "SmashCharacter.h"

// Sets default values
AOSY_CrashNodeActor::AOSY_CrashNodeActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	compBox = CreateDefaultSubobject<UBoxComponent>(TEXT("compBox"));
	SetRootComponent(compBox);
	compBox->SetBoxExtent(FVector(50, 50, 32));

	compMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("compMesh"));
	compMesh->SetupAttachment(compBox);
	compMesh->SetRelativeScale3D(FVector(0.38f, 0.38f, 0.23f));

	ConstructorHelpers::FObjectFinder<UStaticMesh> tempMesh(TEXT("/Script/Engine.StaticMesh'/Engine/EngineMeshes/Cube.Cube'"));
	if (tempMesh.Succeeded())
	{
		compMesh->SetStaticMesh(tempMesh.Object);
	}

}

// Called when the game starts or when spawned
void AOSY_CrashNodeActor::BeginPlay()
{
	Super::BeginPlay();


	Target = Cast<AOSY_CrashNodeEndActor>(UGameplayStatics::GetActorOfClass(GetWorld(), AOSY_CrashNodeEndActor::StaticClass()));

	compBox-> OnComponentBeginOverlap.AddDynamic(this,&AOSY_CrashNodeActor::OnComponentBeginOverlap);

	if (Target != nullptr)
	{
		StartLocation = GetActorLocation();
		TargetLocation = Target->GetActorLocation();
	}
	
}

// Called every frame
void AOSY_CrashNodeActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation;

	//if (CurrentLerpTime < TotalLerpTime)
	{
		// Lerp 함수를 사용하여 현재 위치를 새 위치로 보간
		NewLocation = FMath::Lerp(StartLocation, TargetLocation, CurrentLerpTime / TotalLerpTime);

		// 새 위치로 이동
		SetActorLocation(NewLocation);

		// 시간 업데이트
		CurrentLerpTime += DeltaTime;
	}


}

void AOSY_CrashNodeActor::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

}

