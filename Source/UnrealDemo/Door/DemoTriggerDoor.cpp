// Fill out your copyright notice in the Description page of Project Settings.


#include "DemoTriggerDoor.h"

#include "Engine/TriggerBox.h"

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

    auto current_rotation = GetOwner()->GetActorRotation();
    auto new_rotation = FMath::RInterpTo(current_rotation, target_rotation_, DeltaTime, Speed);
    GetOwner()->SetActorRotation(new_rotation);

    auto world = GetWorld();
    if (!world)
        return;

    auto player_pawn = world->GetFirstPlayerController()->GetPawn();
    if (!player_pawn)
        return;

    bool in_trigger_1 = TriggerBox1 && TriggerBox1->IsOverlappingActor(player_pawn);
    bool in_trigger_2 = TriggerBox2 && TriggerBox2->IsOverlappingActor(player_pawn);

    if (!opened_ && in_trigger_1)
    {
        target_rotation_ = OpenAngle1;
        opened_ = true;
    }
    else if (!opened_ && in_trigger_2)
    {
        target_rotation_ = OpenAngle2;
        opened_ = true;
    }
    else if (!in_trigger_1 && !in_trigger_2)
    {
        target_rotation_ = ClosedAngle;
        opened_ = false;
    }
}

