// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectiveWorldSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "ObjectiveWidget.h"

void UObjectiveWorldSubsystem::CreateObjectiveWidget(TSubclassOf<UObjectiveWidget> objective_widget_class)
{
    if (!objective_widget_)
    {
        auto* player_controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
        objective_widget_ = CreateWidget<UObjectiveWidget>(player_controller, objective_widget_class);
    }
}

void UObjectiveWorldSubsystem::InitObjectives()
{
    objectives_.Push("Go through the door.");
    objective_count_ = 1;
}

void UObjectiveWorldSubsystem::ShowObjective()
{
    if (objective_count_ > 0)
    {
        objective_widget_->RemoveFromViewport();
        objective_widget_->AddToViewport();
        objective_widget_->SetObjective(objectives_[0]);
    }
}

void UObjectiveWorldSubsystem::CompleteObjective()
{
    if (objective_count_ > 0)
    {
        objective_widget_->RemoveFromViewport();
        objective_widget_->AddToViewport();
        objective_widget_->SetObjective(objectives_[0] + "(Completed)");

        objectives_.RemoveAt(0);
        objective_count_--;
    }
}
