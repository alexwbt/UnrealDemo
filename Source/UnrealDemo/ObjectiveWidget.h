// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ObjectiveWidget.generated.h"

/**
 *
 */
UCLASS()
class UNREALDEMO_API UObjectiveWidget : public UUserWidget
{
    GENERATED_BODY()

public:

    /* Properties */

    UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
    class UTextBlock* ObjectiveDescription;

    void SetObjective(FString description);

};
