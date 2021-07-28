// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectiveWidget.h"
#include "Components/TextBlock.h"


void UObjectiveWidget::SetObjective(FString description)
{
    if (ObjectiveDescription)
    {
        ObjectiveDescription->SetText(FText::FromString(description));
    }
}
