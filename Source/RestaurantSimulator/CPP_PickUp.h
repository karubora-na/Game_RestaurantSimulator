// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPP_ItemEnum.h"
#include "GameFramework/Actor.h"
#include "CPP_PickUp.generated.h"

UCLASS()
class RESTAURANTSIMULATOR_API ACPP_PickUp : public AActor
{
	GENERATED_BODY()

private:

	UPROPERTY(EditAnywhere, Category = Mesh)
	TObjectPtr<UStaticMeshComponent> _mesh;

	UPROPERTY(EditAnywhere, Category = Num)
	ECPP_ItemEnum _item_num;

	UPROPERTY(EditAnywhere, Category = Bool)
	bool _is_food;

public:
	// Sets default values for this actor's properties
	ACPP_PickUp();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	ECPP_ItemEnum getItemType()const;
	bool getIsFood()const;
};
