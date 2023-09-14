// Fill out your copyright notice in the Description page of Project Settings.


#include "OSY_NodeActor.h"
#include "Components/BoxComponent.h"
#include <Kismet/GameplayStatics.h>
#include "OSY_NodeEndActor.h"
#include "OSY_NodeDestroyZone.h"

// Sets default values
AOSY_NodeActor::AOSY_NodeActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	compBox=CreateDefaultSubobject<UBoxComponent>(TEXT("compBox"));
	SetRootComponent(compBox);
	compBox->SetBoxExtent(FVector(50,50,32));

	compMesh= CreateDefaultSubobject<UStaticMeshComponent>(TEXT("compMesh"));
	compMesh->SetupAttachment(compBox);
	compMesh->SetRelativeScale3D(FVector(0.38f,0.38f,0.23f));

	ConstructorHelpers::FObjectFinder<UStaticMesh> tempMesh(TEXT("/Script/Engine.StaticMesh'/Engine/EngineMeshes/Cube.Cube'"));
	if (tempMesh.Succeeded())
	{
		compMesh->SetStaticMesh(tempMesh.Object);
	}
	

}

// Called when the game starts or when spawned
void AOSY_NodeActor::BeginPlay()
{
	Super::BeginPlay();

	Target = Cast<AOSY_NodeEndActor>(UGameplayStatics::GetActorOfClass(GetWorld(), AOSY_NodeEndActor::StaticClass()));

	if (Target != nullptr)
	{
		StartLocation = GetActorLocation();
		TargetLocation = Target->GetActorLocation();
	}

	
}

// Called every frame
void AOSY_NodeActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	if (CurrentLerpTime < TotalLerpTime)
	{
		// Lerp �Լ��� ����Ͽ� ���� ��ġ�� �� ��ġ�� ����
		FVector NewLocation = FMath::Lerp(StartLocation, TargetLocation, CurrentLerpTime / TotalLerpTime);

		// �� ��ġ�� �̵�
		SetActorLocation(NewLocation);

		// �ð� ������Ʈ
		CurrentLerpTime += DeltaTime;
	}

}



void AOSY_NodeActor::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

}

void AOSY_NodeActor::ResetNode()
{
	// ���׾� ����� ��ġ ���� �� ǥ��
	FVector FactoryLoc = GetActorLocation();
	SetActorLocation(FactoryLoc);
	SetActorHiddenInGame(false);
}

