// Fill out your copyright notice in the Description page of Project Settings.


#include "A_Retry.h"
#include <UMG/Public/Components/WidgetComponent.h>
#include "Retry_Widget.h"

// Sets default values
AA_Retry::AA_Retry()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	retryWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("Retry Widget"));
	retryWidget->SetupAttachment(RootComponent);

// 	static ConstructorHelpers::FClassFinder<UUserWidget> WidgetClass(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/A_OSY/UI/BP_RetryWidget.BP_RetryWidget'"));
// 	if (WidgetClass.Succeeded())
// 	{
// 		retryWidget->SetWidgetClass(WidgetClass.Class);
// 	}
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



