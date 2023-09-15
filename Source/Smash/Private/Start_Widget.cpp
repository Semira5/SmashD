// Fill out your copyright notice in the Description page of Project Settings.


#include "Start_Widget.h"
#include "Components/Button.h"
#include <Kismet/GameplayStatics.h>

void UStart_Widget::NativeConstruct()
{
    Super::NativeConstruct();

    btn_Classic->OnClicked.AddDynamic(this, &UStart_Widget::StartClassicMode);
    PlayAnimationForward(Fade);
}

void UStart_Widget::StartClassicMode()
{
    if (Fade != nullptr)
    { 
        PlayAnimationForward(Fade);

        FTimerHandle DelayHandle;
        GetWorld()->GetTimerManager().SetTimer(DelayHandle, FTimerDelegate::CreateLambda([&]()
        {
            FString LevelName = TEXT("PlayMap");
            UGameplayStatics::OpenLevel(this, FName(LevelName));
        }
    ), 2.0f, false);
    }
}

