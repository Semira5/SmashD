// Fill out your copyright notice in the Description page of Project Settings.


#include "SmashAudience.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ASmashAudience::ASmashAudience()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	rootComp = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));
	SetRootComponent(rootComp);

	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	meshComp->SetupAttachment(rootComp);
	meshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	meshComp->SetRelativeScale3D(FVector(0.1f, 0.1f, 0.6f));
	
	
}

// Called when the game starts or when spawned
void ASmashAudience::BeginPlay()
{
	Super::BeginPlay();
	
// 	audMat = UMaterialInstanceDynamic::Create(meshComp->GetMaterial(0), this);
// 	meshComp->SetMaterial(0, audMat);
// 
// 	audMat->SetVectorParameterValue(FName("AudColor"), (FVector4)baseColor);
// 	audMat->SetScalarParameterValue(FName("Intensity"), 5);
}

// Called every frame
void ASmashAudience::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

