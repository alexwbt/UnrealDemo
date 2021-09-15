// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "../HealthComponent.h"
#include "DemoPlayerCharacterBase.generated.h"

UCLASS()
class UNREALDEMO_API ADemoPlayerCharacterBase : public ACharacter
{
    GENERATED_BODY()

public:
    // Sets default values for this character's properties
    ADemoPlayerCharacterBase();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    virtual void FellOutOfWorld(const class UDamageType& damage_type) override;

    virtual float TakeDamage(float amount, const FDamageEvent& event, AController* instigator, AActor* causer) override;

    virtual void OnDeath();

    UFUNCTION(BlueprintCallable)
    bool IsAlive() const
    {
        return health_component && !health_component->IsDead();
    }

    UFUNCTION(BlueprintCallable)
    float GetCurrentHealth() const
    {
        return health_component ? health_component->current_health : 0.0f;
    }

    UFUNCTION()
    void RestartLevel() const;

    UFUNCTION(BlueprintCallable)
    void HandleItemCollected();

    UFUNCTION(BlueprintImplementableEvent)
    void ItemCollected();

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    int ItemsCollected = 0;

private:
    UPROPERTY(EditAnywhere)
    UHealthComponent* health_component = nullptr;

    FTimerHandle death_timer_;

    APlayerController* PC;

    UPROPERTY(EditAnywhere, Category="Effects")
    TSubclassOf<class UCameraShakeBase> CamShake;
};
