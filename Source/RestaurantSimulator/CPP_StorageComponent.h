// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CPP_ItemStrage.h"
#include "CPP_ItemEnum.h"
#include "CPP_StorageComponent.generated.h"

#define MAX_STORAGE_RANGE 3

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class RESTAURANTSIMULATOR_API UCPP_StorageComponent : public UActorComponent
{
	GENERATED_BODY()

private:

	UPROPERTY()
	FCPP_ItemStrage _item_storage[MAX_STORAGE_RANGE];

public:
	// Sets default values for this component's properties
	UCPP_StorageComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:

	bool saveItem(ECPP_ItemEnum item_num, bool is_food);
	void getItemNum(ECPP_ItemEnum* array);
	
};
