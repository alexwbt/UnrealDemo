// Fill out your copyright notice in the Description page of Project Settings.


#include "DemoPlayerCharacterBase.h"
#include "DemoPlayerControllerBase.h"
#include "GameFramework/DamageType.h"


// Sets default values
ADemoPlayerCharacterBase::ADemoPlayerCharacterBase()
{
    // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    health_component = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
}

// Called when the game starts or when spawned
void ADemoPlayerCharacterBase::BeginPlay()
{
    Super::BeginPlay();

    PC = GetWorld()->GetFirstPlayerController();
}

// Called every frame
void ADemoPlayerCharacterBase::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADemoPlayerCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ADemoPlayerCharacterBase::FellOutOfWorld(const UDamageType& damage_type)
{
    RestartLevel();
}

float ADemoPlayerCharacterBase::TakeDamage(float amount, const FDamageEvent& event, AController* instigator, AActor* causer)
{
    auto damage = Super::TakeDamage(amount, event, instigator, causer);
    UE_LOG(LogTemp, Warning, TEXT("Player took damage: %.2f"), damage);
    if (health_component && !health_component->IsDead())
    {
        health_component->TakeDamage(damage);
        if (health_component->IsDead())
        {
            OnDeath();
        }
    }
    return damage;
}

void ADemoPlayerCharacterBase::OnDeath()
{
    GetWorld()->GetTimerManager().SetTimer(death_timer_, this, &ADemoPlayerCharacterBase::RestartLevel, 2.0f, false);

    auto* player_controller = GetController<ADemoPlayerControllerBase>();
    if (player_controller)
    {
        player_controller->DisableInput(player_controller);
    }
}


void ADemoPlayerCharacterBase::RestartLevel() const
{
    auto* player_controller = GetController<ADemoPlayerControllerBase>();
    if (player_controller)
    {
        player_controller->RestartLevel();
    }
}

void ADemoPlayerCharacterBase::HandleItemCollected()
{
    ItemsCollected++;

    PC->PlayerCameraManager->StartCameraShake(CamShake, 1.0f);

    ItemCollected();
}
