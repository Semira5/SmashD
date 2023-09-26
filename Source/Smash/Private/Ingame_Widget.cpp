// Fill out your copyright notice in the Description page of Project Settings.


#include "Ingame_Widget.h"
#include "Components/Button.h"
#include <Kismet/GameplayStatics.h>

UIngame_Widget* UIngame_Widget::IngameWidget_inst = nullptr;

void UIngame_Widget::NativeConstruct()
{
    Super::NativeConstruct();

    btn_PlayGame->OnClicked.AddDynamic(this, &UIngame_Widget::PlayGame);
    PlayAnimationForward(FadeOut);
    PlayAnimation(Gradation, 0.0f, 0);

    if (!IngameWidget_inst)
    {
        IngameWidget_inst = this;
    }
    
}

void UIngame_Widget::PlayGame()
{
    FString LevelName = TEXT("SakuraPlay");
    UGameplayStatics::OpenLevel(this, FName(LevelName));

}
