// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "ObjectiveWidget.h"
#include "ObjectiveWorldSubsystem.generated.h"

/**
 *
 */
UCLASS()
class UNREALDEMO_API UObjectiveWorldSubsystem : public UWorldSubsystem
{
    GENERATED_BODY()

public:
    void CreateObjectiveWidget(TSubclassOf<UObjectiveWidget> objective_widget_class);
    void InitObjectives();

    void ShowObjective();
    void CompleteObjective();

private:
    class UObjectiveWidget* objective_widget_ = nullptr;

    TArray<FString> objectives_;
    int objective_count_;

};
