// Fill out your copyright notice in the Description page of Project Settings.


#include "OSY_Level.h"
#include "Kismet/GameplayStatics.h"
#include "Ingame_Widget.h"

AOSY_Level::AOSY_Level()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AOSY_Level::BeginPlay()
{
	Super::BeginPlay();

	playMusic();

	TSubclassOf<UIngame_Widget> WidgetClass = UIngame_Widget::StaticClass();
	UIngame_Widget* IngameWidget = CreateWidget<UIngame_Widget>(GetWorld(), WidgetClass);
	if (IngameWidget)
	{
		IngameWidget->AddToViewport();
	}

	//FTimerHandle handle;
	//GetWorldTimerManager().SetTimer(handle, this, &AOSY_Level::playMusic, 2.f, false);
	

}

void AOSY_Level::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	currentTime+= DeltaTime;
	//2�ʰ� �Ǹ� �÷�����
	//UE_LOG(LogTemp,Warning,TEXT("currentTime : %f"),currentTime);
	if (currentTime >= playSoundTime && currentTime - DeltaTime < playSoundTime)
	{

		//	playMusic();
		//UE_LOG(LogTemp,Warning,TEXT("currentTime : %f"),currentTime);
		
	}

}

void AOSY_Level::playMusic()
{

	UGameplayStatics::PlaySound2D(GetWorld(),StillWaiting);
}
