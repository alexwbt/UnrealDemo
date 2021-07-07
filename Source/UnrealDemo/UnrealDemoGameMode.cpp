// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealDemoGameMode.h"
#include "UnrealDemoHUD.h"
#include "UnrealDemoCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUnrealDemoGameMode::AUnrealDemoGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AUnrealDemoHUD::StaticClass();
}
