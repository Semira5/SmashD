// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Start_Widget.generated.h"

/**
 * 
 */
UCLASS()
class SMASH_API UStart_Widget : public UUserWidget
{
	GENERATED_BODY()
	
public:
    UPROPERTY(EditDefaultsOnly, Category="MySettings", meta=(BindWidget))
	    class UButton* btn_Arcade;
	UPROPERTY(EditDefaultsOnly, Category="MySettings", meta=(BindWidget))
	    class UButton* btn_Classic;
    UPROPERTY(EditDefaultsOnly, Category="MySettings", meta=(BindWidget))
	    class UButton* btn_Multi;
    UPROPERTY(EditDefaultsOnly, Category="MySettings", meta=(BindWidget))
	    class UButton* btn_Settings;
	UPROPERTY(VisibleAnywhere, Transient, meta = (BindWidgetAnim), Category = Menu)
	    class UWidgetAnimation* Fade;

protected:
	virtual void NativeConstruct() override;

private:
    UFUNCTION()
	void StartArcadeMode();
	UFUNCTION()
	void StartClassicMode();
	UFUNCTION()
	void StartMultiMode();
	UFUNCTION()
	void StartSettingMode();
};
