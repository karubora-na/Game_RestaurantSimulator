// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_PickUp.h"
#include "CPP_ItemEnum.h"

// Sets default values
ACPP_PickUp::ACPP_PickUp()
{
	_mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	_mesh->SetupAttachment(RootComponent);

	_item_num = ECPP_ItemEnum::NONE;

	_is_food = false;
}

// Called when the game starts or when spawned
void ACPP_PickUp::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_PickUp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

ECPP_ItemEnum ACPP_PickUp::getItemType() const{
	return _item_num;
}

bool ACPP_PickUp::getIsFood()const {
	return _is_food;
}