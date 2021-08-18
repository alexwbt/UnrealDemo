// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DealDamageComponent.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UNREALDEMO_API UDealDamageComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere)
    float damage_per_tick = 0.5f;

    UPROPERTY(EditAnywhere, NoClear)
    class UCapsuleComponent* trigger_capsule;

private:
    TArray<class ADemoPlayerCharacterBase*> players_;

public:
    // Sets default values for this component's properties
    UDealDamageComponent();

    UFUNCTION()
    void OnEnter(
        UPrimitiveComponent* overlapped_comp,
        AActor* other_actor,
        UPrimitiveComponent* other_comp,
        int32 other_body_index,
        bool from_sweep,
        const FHitResult& sweep_result
    );

    UFUNCTION()
    void OnExit(
        UPrimitiveComponent* overlapped_comp,
        AActor* other_actor,
        UPrimitiveComponent* other_comp,
        int32 other_body_index
    );

    //virtual void O

protected:
    // Called when the game starts
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


};
