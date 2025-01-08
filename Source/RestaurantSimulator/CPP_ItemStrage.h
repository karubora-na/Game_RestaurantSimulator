// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPP_ItemEnum.h"
#include "CPP_ItemStrage.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct FCPP_ItemStrage {
	GENERATED_BODY()
public:

	bool _is_valid;

	ECPP_ItemEnum _item_num;

	bool _is_food;
};
