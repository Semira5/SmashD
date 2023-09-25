// Fill out your copyright notice in the Description page of Project Settings.


#include "A_Retry.h"
#include <UMG/Public/Components/WidgetComponent.h>

// Sets default values
AA_Retry::AA_Retry()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	retryWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("Retry Widget"));
	retryWidget->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AA_Retry::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AA_Retry::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

