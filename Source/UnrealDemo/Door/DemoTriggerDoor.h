// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DemoTriggerDoor.generated.h"

class ATriggerBox;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UNREALDEMO_API UDemoTriggerDoor : public UActorComponent
{
    GENERATED_BODY()

public:
    UDemoTriggerDoor();

protected:
    virtual void BeginPlay() override;

public:
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    /* Properties */

    UPROPERTY(EditAnywhere, NoClear);
    float speed = 1.0f;

    UPROPERTY(EditAnywhere, NoClear);
    FRotator open_angle_1 = { 0.0f, 95.0f, 0.0f };

    UPROPERTY(EditAnywhere, NoClear);
    ATriggerBox* trigger_box_1;

    UPROPERTY(EditAnywhere, NoClear);
    FRotator open_angle_2 = { 0.0f, -95.0f, 0.0f };

    UPROPERTY(EditAnywhere, NoClear);
    ATriggerBox* trigger_box_2;

    UPROPERTY(EditAnywhere, NoClear);
    FRotator closed_angle = FRotator::ZeroRotator;

    /* Events */

    DECLARE_EVENT(FDemoTriggerDoor, FPlayerWentThroughDoor);
    FPlayerWentThroughDoor& OnPlayerGoThrough() { return through_door_event_; }

private:
    FPlayerWentThroughDoor through_door_event_;
    bool was_in_both_trigger_box_ = false;

    FRotator target_rotation_ = FRotator::ZeroRotator;
    bool opened_ = false;
    bool locked_ = false;
};
