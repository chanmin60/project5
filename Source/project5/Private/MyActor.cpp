// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "Math/UnrealMathUtility.h"
#include "Engine/Engine.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	start = FVector2D(0.0f, 0.0f);
	CurrentLocation = start;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Actor Spawned at: (%f, %f)"), CurrentLocation.X, CurrentLocation.Y);
	Move();
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int32 AMyActor::Step() {
	return FMath::RandRange(0, 1);
}

void AMyActor::Move() {
	for (int32 i = 0; i < 10;i++) {
		int32 DeltaX = Step();
		int32 DeltaY = Step();
		CurrentLocation.X += DeltaX;
		CurrentLocation.Y += DeltaY;
		UE_LOG(LogTemp, Warning, TEXT("Step %d : (%f, %f)로 이동했습니다"), i + 1, CurrentLocation.X, CurrentLocation.Y);
	}
}

