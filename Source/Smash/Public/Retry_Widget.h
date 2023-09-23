// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Retry_Widget.generated.h"

/**
 * 
 */
UCLASS()
class SMASH_API URetry_Widget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="MySettings", meta=(BindWidget))
	class UButton* btn_Retry;

	protected:
	virtual void NativeConstruct() override;

private:
    UFUNCTION()
	void ReturnToFirst();
};
