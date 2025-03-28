// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class RESTAURANTSIMULATOR_API CPP_FunctionLibrary
{
public:
	CPP_FunctionLibrary();
	~CPP_FunctionLibrary();

	// à¯êîÅ@GetWorld(),TEXT()
	static void outputString(TObjectPtr<UObject> WorldContextObject, FString text);
	static void outputString(TObjectPtr<UObject> WorldContextObject, FString text, FColor text_color);
};
