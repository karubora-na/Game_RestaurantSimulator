// Copyright Epic Games, Inc. All Rights Reserved.

#include "RestaurantSimulatorGameMode.h"
#include "RestaurantSimulatorCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARestaurantSimulatorGameMode::ARestaurantSimulatorGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
