// Fill out your copyright notice in the Description page of Project Settings.


#include "DemoPlayerCharacterBase.h"

// Sets default values
ADemoPlayerCharacterBase::ADemoPlayerCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADemoPlayerCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
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

