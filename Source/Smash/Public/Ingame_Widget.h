// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Ingame_Widget.generated.h"

/**
 * 
 */
UCLASS()
class SMASH_API UIngame_Widget : public UUserWidget
{
	GENERATED_BODY()

public:
    UPROPERTY(EditDefaultsOnly, Category="MySettings", meta=(BindWidget))
	class UButton* btn_PlayGame;

	UPROPERTY(VisibleAnywhere, Transient, meta = (BindWidgetAnim), Category = Menu)
	class UWidgetAnimation* FadeOut;
	UPROPERTY(VisibleAnywhere, Transient, meta = (BindWidgetAnim), Category = Menu)
	class UWidgetAnimation* Gradation;

    UFUNCTION()
	void PlayGame();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool playtick= false;


	static UIngame_Widget* IngameWidget_inst;

protected:
	virtual void NativeConstruct() override;

private:

	
};
