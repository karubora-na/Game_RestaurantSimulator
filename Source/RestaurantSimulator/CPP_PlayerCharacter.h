// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <CoreMinimal.h>
#include <GameFramework/Character.h>
#include <Camera/CameraComponent.h>
#include <EnhancedInputSubsystems.h>
#include <InputMappingContext.h>
#include "CPP_PickUp.h"
#include "CPP_StorageComponent.h"
#include <CPP_PlayerCharacter.generated.h>

UCLASS()
class RESTAURANTSIMULATOR_API ACPP_PlayerCharacter : public ACharacter
{
	GENERATED_BODY()

private:

	const FVector2D CAPSULE_SIZE = FVector2D(55.0f, 96.0f);
	const FVector CAMERA_RELATIVE_LOCATION = FVector(30.0f, 0.0f, 60.0f);
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UCameraComponent> _camera_component;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UCPP_StorageComponent> _storage_component;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UInputMappingContext> _default_mapping_context;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UInputAction> _move_action;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UInputAction> _look_action;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UInputAction> _interact_action;

	UPROPERTY()
	TObjectPtr<UWorld> _world;

	UPROPERTY(EditAnywhere)
	int32 ITEM_SEARCH_CAN_DISTANCE;

	UPROPERTY()
	TObjectPtr<AActor> _selecting_actor;

public:

	ACPP_PlayerCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	TObjectPtr<UCPP_StorageComponent> getStorageComponent()const;
protected:
	
	virtual void BeginPlay() override;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

	void haveItem();
	TObjectPtr<AActor> searchItem();
	
};
