// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPP_ItemEnum.h"
#include "CPP_KeyStruct.generated.h"
/**
 *
 */
USTRUCT(BlueprintType)
struct FCPP_KeyStruct {

	GENERATED_BODY()

	int _first_key;
	int _second_key;
	int _third_key;

	FCPP_KeyStruct()
		:_first_key(0), _second_key(0), _third_key(0){
	}

	FCPP_KeyStruct(int first, int second)
		:_first_key(first), _second_key(second),_third_key(0) {
	}

	FCPP_KeyStruct(int first, int second, int third)
		:_first_key(first), _second_key(second), _third_key(third) {
	}


	bool operator==(const FCPP_KeyStruct& other) const {

		return _first_key == other._first_key &&
			_second_key == other._second_key &&
			_third_key == other._third_key;
	}

};

FORCEINLINE uint32 GetTypeHash(const FCPP_KeyStruct& Key) {

	return HashCombine(HashCombine(GetTypeHash(Key._first_key), GetTypeHash(Key._second_key)), GetTypeHash(Key._third_key));
}
