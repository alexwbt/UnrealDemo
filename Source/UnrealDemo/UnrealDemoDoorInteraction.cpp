// Fill out your copyright notice in the Description page of Project Settings.


#include "UnrealDemoDoorInteraction.h"

#include "Engine/TriggerBox.h"

// Sets default values for this component's properties
UUnrealDemoDoorInteraction::UUnrealDemoDoorInteraction()
{
    PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UUnrealDemoDoorInteraction::BeginPlay()
{
    Super::BeginPlay();
}


// Called every frame
void UUnrealDemoDoorInteraction::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    auto current_rotation = GetOwner()->GetActorRotation();
    auto new_rotation = FMath::RInterpTo(current_rotation, target_rotation_, DeltaTime, Speed);
    GetOwner()->SetActorRotation(new_rotation);

    if (!TriggerBox)
        return;

    auto world = GetWorld();
    if (!world)
        return;

    auto player_pawn = world->GetFirstPlayerController()->GetPawn();
    if (!player_pawn)
        return;

    if (TriggerBox->IsOverlappingActor(player_pawn))
        target_rotation_ = OpenedRotation;
    else
        target_rotation_ = ClosedRotation;
}

