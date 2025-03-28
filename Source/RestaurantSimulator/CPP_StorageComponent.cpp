// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_StorageComponent.h"
#include "CPP_ItemEnum.h"
#include "CPP_FunctionLibrary.h"

UCPP_StorageComponent::UCPP_StorageComponent()
{
	for (int idx = 0; idx < MAX_STORAGE_RANGE; idx++) {

		_item_storage[idx]._is_valid = false;
		_item_storage[idx]._item_num = ECPP_ItemEnum::NONE;
		_item_storage[idx]._is_food = false;
	}
}


// Called when the game starts
void UCPP_StorageComponent::BeginPlay()
{
	Super::BeginPlay();

}

bool UCPP_StorageComponent::saveItem(ECPP_ItemEnum item_num, bool is_food) {

	for (int idx = 0; idx < MAX_STORAGE_RANGE; idx++) {
		if (!_item_storage[idx]._is_valid) {

			_item_storage[idx]._is_valid = true;
			_item_storage[idx]._item_num = item_num;
			_item_storage[idx]._is_food = is_food;
			CPP_FunctionLibrary::outputString(
				GetWorld(),
				FString::Printf(TEXT("Storage_idx[%d] ItemNum:%d Is_Food:%s"), idx, (int)item_num, is_food ? TEXT("true") : TEXT("false"))
			);

			return true;
		}
	}
	return false;
}

void UCPP_StorageComponent::getItemNum(ECPP_ItemEnum* array) {

	for (int i = 0; i < MAX_STORAGE_RANGE; i++) {

		array[i] = _item_storage[i]._item_num;
	}
}
