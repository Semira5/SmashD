// Fill out your copyright notice in the Description page of Project Settings.


#include "Retry_Widget.h"
#include "Components/Button.h"
#include <Kismet/GameplayStatics.h>
#include <TimerManager.h>

void URetry_Widget::NativeConstruct()
{
    Super::NativeConstruct();

    btn_Retry->OnClicked.AddDynamic(this, &URetry_Widget::ReturnToFirst);
}


void URetry_Widget::ReturnToFirst()
{
    FString LevelName = TEXT("Level_BJH");
    UGameplayStatics::OpenLevel(this, FName(LevelName));
}


