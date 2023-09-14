// Fill out your copyright notice in the Description page of Project Settings.


#include "OSY_NodeDestroyZone.h"
#include "Components/BoxComponent.h"
#include "OSY_CrashNodeActor.h"
#include "OSY_SnareNodeActor.h"
#include "OSY_SnareFactory.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AOSY_NodeDestroyZone::AOSY_NodeDestroyZone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("boxComp"));
	RootComponent = boxComp;

}

// Called when the game starts or when spawned
void AOSY_NodeDestroyZone::BeginPlay()
{
	Super::BeginPlay();

	// ���� �ε����� �� �̺�Ʈ�� ���
	boxComp->OnComponentBeginOverlap.AddDynamic(this, &AOSY_NodeDestroyZone::OnComponentBeginOverlap);
	
}

// Called every frame
void AOSY_NodeDestroyZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	
	current += DeltaTime;
	if (isOverlap != true)
	{
		UE_LOG(LogTemp, Warning, TEXT("current : %f"), current);
		isOverlap = true;
	}

	
}

void AOSY_NodeDestroyZone::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AOSY_SnareNodeActor* SN =Cast<AOSY_SnareNodeActor>(OtherActor);
	if (SN != nullptr)
	{
		//Ǯ�� �־�����
		//Ǯ�� ���丮���� �ִ�.
		//AOSY_SnareFactory* SF = Cast<AOSY_SnareFactory>(UGameplayStatics::GetActorOfClass(GetWorld(),AOSY_SnareFactory::StaticClass()));
		//// Ǯ�� �־��ٰŴ�
		//SF->SnarePool.Add(SN);
		SN->ActiveNode(GetActorLocation(), false);
	}
	else
	{
		OtherActor->Destroy();

	}

}

