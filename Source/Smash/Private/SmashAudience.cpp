// Fill out your copyright notice in the Description page of Project Settings.


#include "SmashAudience.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ASmashAudience::ASmashAudience()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	meshComp->SetupAttachment(RootComponent);
	meshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	meshComp->SetRelativeScale3D(FVector(0.1f, 0.1f, 0.6f));
	SetRootComponent(meshComp);
}

// Called when the game starts or when spawned
void ASmashAudience::BeginPlay()
{
	Super::BeginPlay();
	
	audMat = UMaterialInstanceDynamic::Create(meshComp->GetMaterial(0), this);
	meshComp->SetMaterial(0, audMat);

	audMat->SetVectorParameterValue(FName("AudColor"), (FVector4)baseColor);
	audMat->SetScalarParameterValue(FName("Intensity"), 20);
}

// Called every frame
void ASmashAudience::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

