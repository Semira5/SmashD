// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OSY_ScoreFloatingWidget.generated.h"

/**
 * 
 */
UCLASS()
class SMASH_API UOSY_ScoreFloatingWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime);


public :

	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category = MySettings)
	class UTextBlock* text_Score;

private :
	UPROPERTY()
	class ASmashCharacter* player;
	
};
