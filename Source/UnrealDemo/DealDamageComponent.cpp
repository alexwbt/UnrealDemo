// Fill out your copyright notice in the Description page of Project Settings.


#include "DealDamageComponent.h"
#include "Components/CapsuleComponent.h"
#include "Player/DemoPlayerCharacterBase.h"
#include "GameFramework/DamageType.h"

// Sets default values for this component's properties
UDealDamageComponent::UDealDamageComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	trigger_capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("TriggerCapsule"));
	trigger_capsule->OnComponentBeginOverlap.AddDynamic(this, &UDealDamageComponent::OnEnter);
	trigger_capsule->OnComponentEndOverlap.AddDynamic(this, &UDealDamageComponent::OnExit);
}


// Called when the game starts
void UDealDamageComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UDealDamageComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    const auto damge_type_class = TSubclassOf<UDamageType>(UDamageType::StaticClass());
    FDamageEvent event(damge_type_class);
    auto* owner = GetOwner();

    for (const auto& player : players_)
        player->TakeDamage(damage_per_tick, event, nullptr, owner);
}

void UDealDamageComponent::OnEnter(
    UPrimitiveComponent* overlapped_comp,
    AActor* other_actor,
    UPrimitiveComponent* other_comp,
    int32 other_body_index,
    bool from_sweep,
    const FHitResult& sweep_result
) {
    auto* owner = GetOwner();
    if (other_actor == owner)
    {
        return;
    }

    auto* player_character = Cast<ADemoPlayerCharacterBase>(other_actor);
    if (player_character && !players_.Contains(player_character))
    {
        UE_LOG(LogTemp, Warning, TEXT("DealDamageComponent: OnEnter"));
        players_.Add(player_character);
    }
}

void UDealDamageComponent::OnExit(
    UPrimitiveComponent* overlapped_comp,
    AActor* other_actor,
    UPrimitiveComponent* other_comp,
    int32 other_body_index
) {
    auto* player_character = Cast<ADemoPlayerCharacterBase>(other_actor);
    if (player_character && players_.Contains(player_character))
    {
        UE_LOG(LogTemp, Warning, TEXT("DealDamageComponent: OnExit"));
        players_.Remove(player_character);
    }
}


