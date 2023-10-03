// Fill out your copyright notice in the Description page of Project Settings.


#include "Start_Widget.h"
#include "Components/Button.h"
#include <Kismet/GameplayStatics.h>

void UStart_Widget::NativeConstruct()
{
    Super::NativeConstruct();

    btn_Arcade->OnClicked.AddDynamic(this, &UStart_Widget::StartArcadeMode);
    btn_Classic->OnClicked.AddDynamic(this, &UStart_Widget::StartClassicMode);
    btn_Multi->OnClicked.AddDynamic(this, &UStart_Widget::StartMultiMode);
    btn_Settings->OnClicked.AddDynamic(this, &UStart_Widget::StartSettingMode);
}

void UStart_Widget::StartArcadeMode()
{
    ////UE_LOG(LogTemp, Warning, TEXT("StartArcade!!"));
}

void UStart_Widget::StartClassicMode()
{
    if (Fade != nullptr)
    { 
        PlayAnimationForward(Fade);

        FTimerHandle DelayHandle;
        GetWorld()->GetTimerManager().SetTimer(DelayHandle, FTimerDelegate::CreateLambda([&]()
        {
            FString LevelName = TEXT("PracticeMap");
            UGameplayStatics::OpenLevel(this, FName(LevelName));
        }
    ), 2.0f, false);
    }
}

void UStart_Widget::StartMultiMode()
{
    ////UE_LOG(LogTemp, Warning, TEXT("StartMulti!!"));
}

void UStart_Widget::StartSettingMode()
{
    ////UE_LOG(LogTemp, Warning, TEXT("StartSettings!!"));
}

