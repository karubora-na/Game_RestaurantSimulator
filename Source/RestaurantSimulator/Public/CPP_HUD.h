// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "CPP_HUD.generated.h"

/**
 * 
 */
UCLASS()
class RESTAURANTSIMULATOR_API ACPP_HUD : public AHUD
{
	GENERATED_BODY()
	
protected:

		virtual void BeginPlay() override;
};
