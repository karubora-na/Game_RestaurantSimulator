// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPP_ItemEnum.generated.h"
/**
 *
 */
UENUM(BlueprintType)
enum class ECPP_ItemEnum : uint8 {

	NONE = 0,
	TUNA,
	RICE,
	LAVER,
	TUNA_RICE_BALL
};