// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UnrealDemoDoorInteraction.generated.h"

class ATriggerBox;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALDEMO_API UUnrealDemoDoorInteraction : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UUnrealDemoDoorInteraction();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/*
		Properties
	*/

	UPROPERTY(EditAnywhere)
	float Speed = 5.0f;

	UPROPERTY(EditAnywhere)
	FRotator OpenedRotation = { 0.0f, 95.0f, 0.0f };

	UPROPERTY(EditAnywhere)
	FRotator ClosedRotation = FRotator::ZeroRotator;

	UPROPERTY(EditAnywhere)
	ATriggerBox* TriggerBox;

private:
	FRotator target_rotation_;

	bool opened_;

};
