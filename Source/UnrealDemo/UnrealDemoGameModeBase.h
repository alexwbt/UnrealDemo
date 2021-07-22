// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Blueprint/UserWidget.h"
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

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> ObjectiveWidgetClass;

private:
	UUserWidget* objective_widget_ = nullptr;
	
};
