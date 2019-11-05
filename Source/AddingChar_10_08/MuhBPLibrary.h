// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MuhBPLibrary.generated.h"

/**
 * 
 */
UCLASS()
class ADDINGCHAR_10_08_API UMuhBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

		UFUNCTION(BlueprintPure)
			static FString GetLoud(FString MuhWords);

		UFUNCTION(BlueprintPure)
			static FString GetQuiet(FString MuhWords);

		UFUNCTION(BlueprintCallable, Category = "Muh BP Utilities", meta = (WorldContext = "RefObj"))

			static void FlakShot(
				UObject* RefObj, 
				TSubclassOf<AActor> Projectile, 
				FVector Location, 
				FRotator Rotation,
				int32 ShotPerRow,
				int32 ShotPerColumn,
				float ScatterV,
				float ScatterH);

		UPROPERTY(EditAnywhere)
			int32 ShotPerRow = 1;

		UPROPERTY(EditAnywhere)
			int32 ShotPerColumn = 1;

		UPROPERTY(EditAnywhere)
			float ScatterV = 0.0f;

		UPROPERTY(EditAnywhere)
			float ScatterH = 0.0f;
			
	
};
