// Fill out your copyright notice in the Description page of Project Settings.


#include "MuhBPLibrary.h"
#include "GameFramework/Actor.h"
#include "Engine/Engine.h"

FString UMuhBPLibrary::GetLoud(FString MuhWords)
{
	return MuhWords.ToUpper();
}

FString UMuhBPLibrary::GetQuiet(FString MuhWords)
{
	return MuhWords.ToLower();
}

void UMuhBPLibrary::FlakShot(UObject* RefObj, TSubclassOf<AActor> Projectile, FVector Location, FRotator Rotation, int32 ShotPerRow, int32 ShotPerColumn, float ScatterV, float ScatterH)
{
	UWorld* const MuhWorld = GEngine->GetWorldFromContextObjectChecked(RefObj);
	
	for (int32 i = 0; i < ShotPerColumn; i++) 
	{
		Rotation += FRotator(i * ScatterV - (0.5f * ScatterH * ShotPerColumn), 0.0f, 0.0f);

		for (int j = 0; j < ShotPerRow; j++)
		{
			Rotation += FRotator(0.0f, j * ScatterH - (0.5f * ScatterV * ShotPerRow), 0.0f);
			AActor* MuhShot = MuhWorld->SpawnActor<AActor>(Projectile, Location, Rotation);
			Rotation -= FRotator(0.0f, j * ScatterH - (0.5f * ScatterV * ShotPerRow), 0.0f);
		}

		Rotation -= FRotator(i * ScatterV - (0.5f * ScatterH * ShotPerColumn), 0.0f, 0.0f);
	}
}

