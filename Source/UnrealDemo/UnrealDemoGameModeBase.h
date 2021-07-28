// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ObjectiveWidget.h"
#include "UnrealDemoGameModeBase.generated.h"

/**
 *
 */
UCLASS()
class UNREALDEMO_API AUnrealDemoGameModeBase : public AGameModeBase
{
    GENERATED_BODY()

public:
    void StartPlay() override;

    void CompleteDoorObjective();

    UPROPERTY(EditDefaultsOnly);
    TSubclassOf<UObjectiveWidget> objective_widget_class;

    UPROPERTY(EditDefaultsOnly);
    TSoftObjectPtr<AActor> objective_door;

private:
    bool completed_door_objective_ = false;

};
