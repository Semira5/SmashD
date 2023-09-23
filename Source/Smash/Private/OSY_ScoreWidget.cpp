// Fill out your copyright notice in the Description page of Project Settings.


#include "OSY_ScoreWidget.h"
#include "SmashCharacter.h"
#include "Components/TextBlock.h"
#include "OSY_NodeDestroyZone.h"
#include <Kismet/GameplayStatics.h>
#include "Components/Image.h"

void UOSY_ScoreWidget::NativeConstruct()
{
	Super::NativeConstruct();


	player = GetOwningPlayerPawn<ASmashCharacter>();
	DZ = Cast<AOSY_NodeDestroyZone>(UGameplayStatics::GetActorOfClass(GetWorld(), AOSY_NodeDestroyZone::StaticClass()));
}

void UOSY_ScoreWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if (player != nullptr)
	{
		text_EarlyCount->SetText(FText::AsNumber(player->earlyCount));
		text_GreatCount->SetText(FText::AsNumber(player->greatCount));
		text_ExcellentCount->SetText(FText::AsNumber(player->excellentCount));
		text_MissCount->SetText(FText::AsNumber(DZ->missCount));

		TotalScore = player->greatCount*1500 +player->excellentCount*4500;
		text_TotalScore->SetText(FText::AsNumber(TotalScore));
	}
	SetImageByScore();
}

void UOSY_ScoreWidget::SetImageByScore()
{

	UTexture2D* NewImage = nullptr;

	if (TotalScore >= 0 && TotalScore < 200000)
	{
		NewImage = LoadObject<UTexture2D>(nullptr, TEXT("/Script/Engine.Texture2D'/Game/BJH/RankImage/Bronze.Bronze'"));
	}
	else if (TotalScore >= 200000 && TotalScore < 300000)
	{
		NewImage = LoadObject<UTexture2D>(nullptr, TEXT("/Script/Engine.Texture2D'/Game/BJH/RankImage/Silver.Silver'"));
	}
	else if (TotalScore >= 300000 && TotalScore < 500000)
	{
		NewImage = LoadObject<UTexture2D>(nullptr, TEXT("/Script/Engine.Texture2D'/Game/BJH/RankImage/Silver.Silver'"));
	}
	else if (TotalScore >= 500000 && TotalScore < 700000)
	{
		NewImage = LoadObject<UTexture2D>(nullptr, TEXT("/Script/Engine.Texture2D'/Game/BJH/RankImage/Platinum.Platinum'"));
	}
	else if (TotalScore >= 700000 && TotalScore < 1000000)
	{
		NewImage = LoadObject<UTexture2D>(nullptr, TEXT("/Script/Engine.Texture2D'/Game/BJH/RankImage/Dia.Dia'"));
	}
	else
	{
		NewImage = LoadObject<UTexture2D>(nullptr, TEXT("/Script/Engine.Texture2D'/Game/BJH/RankImage/Challenger.Challenger'"));
	}

	if (NewImage)
	{
		img_inst->SetBrushFromTexture(NewImage);
	}

}
