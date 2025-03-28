// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_ItemEnum.h"
#include "CPP_KeyStruct.h"
#include "CPP_SearchItem.generated.h"

UCLASS()
class RESTAURANTSIMULATOR_API ACPP_SearchItem : public AActor
{
	GENERATED_BODY()
private:

	TMap<FCPP_KeyStruct, ECPP_ItemEnum> _recipes;
public:
	// Sets default values for this actor's properties
	ACPP_SearchItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	ECPP_ItemEnum searchItem(ECPP_ItemEnum item0, ECPP_ItemEnum item1, ECPP_ItemEnum item2);
private:

	void addRecipes(ECPP_ItemEnum food,ECPP_ItemEnum item0, ECPP_ItemEnum item1, ECPP_ItemEnum item2);
	bool sortByIncreasing(int* array, int key1, int key2, int key3);
};
