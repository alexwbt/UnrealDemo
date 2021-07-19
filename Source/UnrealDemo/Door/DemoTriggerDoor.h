// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DemoTriggerDoor.generated.h"

class ATriggerBox;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
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

	UPROPERTY(EditAnywhere, NoClear)
	float Speed = 1.0f;

	UPROPERTY(EditAnywhere, NoClear)
	FRotator OpenAngle1 = { 0.0f, 95.0f, 0.0f };

	UPROPERTY(EditAnywhere, NoClear)
	ATriggerBox* TriggerBox1;

	UPROPERTY(EditAnywhere, NoClear)
	FRotator OpenAngle2 = { 0.0f, -95.0f, 0.0f };

	UPROPERTY(EditAnywhere, NoClear)
	ATriggerBox* TriggerBox2;

	UPROPERTY(EditAnywhere, NoClear)
	FRotator ClosedAngle = FRotator::ZeroRotator;

private:
	FRotator target_rotation_ = FRotator::ZeroRotator;
	bool opened_ = false;
	bool locked_ = false;
};
