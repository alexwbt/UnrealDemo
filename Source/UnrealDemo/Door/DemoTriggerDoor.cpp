// Fill out your copyright notice in the Description page of Project Settings.


#include "DemoTriggerDoor.h"

#include "Engine/TriggerBox.h"
#include "Engine/World.h"

#include "DrawDebugHelpers.h"

#include "../ObjectiveWorldSubsystem.h"

static TAutoConsoleVariable<bool> CVarToggleDebugDoor(
    TEXT("UnrealDemo.DemoTriggerDoor.Debug"),
    false,
    TEXT("DemoTriggerDoor debug display."),
    ECVF_Default
);

// Sets default values for this component's properties
UDemoTriggerDoor::UDemoTriggerDoor()
{
    PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UDemoTriggerDoor::BeginPlay()
{
    Super::BeginPlay();
}


// Called every frame
void UDemoTriggerDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (CVarToggleDebugDoor->GetBool())
    {
        FString string = TEXT("Door State: ");
        string += opened_ ? TEXT("Opened") : TEXT("Closed");

        FVector offset(-50.0f, 0.0f, 100.0f);
        DrawDebugString(GetWorld(), offset, string, GetOwner(), FColor::Blue, 0.0f);
    }

    auto current_rotation = GetOwner()->GetActorRotation();
    auto new_rotation = FMath::RInterpTo(current_rotation, target_rotation_, DeltaTime, speed);
    GetOwner()->SetActorRotation(new_rotation);

    auto world = GetWorld();
    if (!world)
        return;

    auto player_pawn = world->GetFirstPlayerController()->GetPawn();
    if (!player_pawn)
        return;

    bool in_trigger_1 = trigger_box_1 && trigger_box_1->IsOverlappingActor(player_pawn);
    bool in_trigger_2 = trigger_box_2 && trigger_box_2->IsOverlappingActor(player_pawn);
    bool in_one_trigger_box = in_trigger_1 != in_trigger_2;

    if (in_one_trigger_box && was_in_both_trigger_box_)
    {
        //went_through_ = true;
        through_door_event_.Broadcast();
        UE_LOG(LogTemp, Warning, TEXT("Player Went through door"));
    }
    was_in_both_trigger_box_ = in_trigger_1 && in_trigger_2;

    if (!opened_ && in_trigger_1)
    {
        target_rotation_ = open_angle_1;
        opened_ = true;
    }
    else if (!opened_ && in_trigger_2)
    {
        target_rotation_ = open_angle_2;
        opened_ = true;
    }
    else if (opened_ && !in_trigger_1 && !in_trigger_2)
    {
        target_rotation_ = closed_angle;
        opened_ = false;
    }
}

