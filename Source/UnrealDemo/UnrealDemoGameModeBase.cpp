// Copyright Epic Games, Inc. All Rights Reserved.


#include "UnrealDemoGameModeBase.h"
#include "Kismet/GameplayStatics.h"

void AUnrealDemoGameModeBase::StartPlay()
{
    Super::StartPlay();

    APlayerController* player_controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
    objective_widget_ = CreateWidget<UUserWidget>(player_controller, ObjectiveWidgetClass);
    if (objective_widget_)
        objective_widget_->AddToViewport();
}
