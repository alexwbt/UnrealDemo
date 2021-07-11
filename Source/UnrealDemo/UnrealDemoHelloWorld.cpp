// Fill out your copyright notice in the Description page of Project Settings.


#include "UnrealDemoHelloWorld.h"

// Sets default values for this component's properties
UUnrealDemoHelloWorld::UUnrealDemoHelloWorld()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	UE_LOG(LogTemp, Log, TEXT("Hello World! %s Constructed."), *Name);
}


// Called when the game starts
void UUnrealDemoHelloWorld::BeginPlay()
{
	Super::BeginPlay();


	UE_LOG(LogTemp, Log, TEXT("Hello World! %s Started."), *Name);
}


// Called every frame
void UUnrealDemoHelloWorld::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (LogEveryTick)
		UE_LOG(LogTemp, Log, TEXT("Hello World! %s Tick."), *Name);
}

