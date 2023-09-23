// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OSY_ScoreWidget.generated.h"

/**
 * 
 */
UCLASS()
class SMASH_API UOSY_ScoreWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime);

public:

	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category = MySettings)
	class UTextBlock* text_Total;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category = MySettings)
	class UTextBlock* text_TotalScore =0;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category = MySettings)
	class UTextBlock* text_Early;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category = MySettings)
	class UTextBlock* text_EarlyCount =0;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category = MySettings)
	class UTextBlock* text_Great;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category = MySettings)
	class UTextBlock* text_GreatCount =0;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category = MySettings)
	class UTextBlock* text_Excellent;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category = MySettings)
	class UTextBlock* text_ExcellentCount =0;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category = MySettings)
	class UTextBlock* text_Miss;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category = MySettings)
	class UTextBlock* text_MissCount =0;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category = "UI")
	class UImage* img_inst;

	UFUNCTION(BlueprintCallable, Category = "UI")
	void SetImageByScore();

	UPROPERTY(VisibleAnywhere, Category = MySettings)
	int TotalScore;

private:
	UPROPERTY()
	class ASmashCharacter* player;
	UPROPERTY()
	class AOSY_NodeDestroyZone* DZ;
	
};
