// Fill out your copyright notice in the Description page of Project Settings.


#include "OSY_ScoreFloatingWidget.h"
#include "SmashCharacter.h"
#include <Kismet/GameplayStatics.h>
#include "Components/TextBlock.h"


void UOSY_ScoreFloatingWidget::NativeConstruct()
{
	Super::NativeConstruct();


	player = GetOwningPlayerPawn<ASmashCharacter>();
	
}

void UOSY_ScoreFloatingWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

}
