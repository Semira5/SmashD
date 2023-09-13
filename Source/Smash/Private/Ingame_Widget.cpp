// Fill out your copyright notice in the Description page of Project Settings.


#include "Ingame_Widget.h"
#include "Components/Button.h"
#include <Kismet/GameplayStatics.h>

void UIngame_Widget::NativeConstruct()
{
    Super::NativeConstruct();

    btn_PlayGame->OnClicked.AddDynamic(this, &UIngame_Widget::PlayGame);
}

void UIngame_Widget::PlayGame()
{
    
}
