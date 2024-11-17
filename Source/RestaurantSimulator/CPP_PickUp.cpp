// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_PickUp.h"

// Sets default values
ACPP_PickUp::ACPP_PickUp()
{
	_mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	_mesh->SetupAttachment(RootComponent);

	_item_num = 0;

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

int32 ACPP_PickUp::getItemNum() const{
	return _item_num;
}

bool ACPP_PickUp::getIsFood()const {
	return _is_food;
}