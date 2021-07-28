// Copyright Epic Games, Inc. All Rights Reserved.


#include "UnrealDemoGameModeBase.h"
#include "ObjectiveWorldSubsystem.h"
#include "Door/DemoTriggerDoor.h"

void AUnrealDemoGameModeBase::StartPlay()
{
    Super::StartPlay();

    ensureMsgf(objective_widget_class, TEXT("AUnrealDemoGameModeBase::StartPlay objective widget class is not set"));

    auto* objective_system = GetWorld()->GetSubsystem<UObjectiveWorldSubsystem>();
    if (objective_system && objective_widget_class)
    {
        objective_system->CreateObjectiveWidget(objective_widget_class);
        objective_system->InitObjectives();
        objective_system->ShowObjective();
    }

    auto* door_comp = objective_door->FindComponentByClass<UDemoTriggerDoor>();
    auto comp = [this]()
    {
        CompleteDoorObjective();
    };
    door_comp->OnPlayerGoThrough().AddLambda(comp);
}

void AUnrealDemoGameModeBase::CompleteDoorObjective()
{
    if (!completed_door_objective_)
    {
        auto* objective_system = GetWorld()->GetSubsystem<UObjectiveWorldSubsystem>();
        objective_system->CompleteObjective();

        completed_door_objective_ = true;
    }
}
