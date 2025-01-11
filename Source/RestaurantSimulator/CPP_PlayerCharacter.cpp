// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_PlayerCharacter.h"
#include "CPPParameter.h"
#include <Components/CapsuleComponent.h>
#include <EnhancedInputComponent.h>

// Sets default values
ACPP_PlayerCharacter::ACPP_PlayerCharacter()
{

	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->InitCapsuleSize(CAPSULE_SIZE.X, CAPSULE_SIZE.Y);

	_camera_component = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	_camera_component->SetupAttachment(GetCapsuleComponent());
	_camera_component->SetRelativeLocation(CAMERA_RELATIVE_LOCATION);
	_camera_component->bUsePawnControlRotation = true;

	_storage_component = CreateDefaultSubobject<UCPP_StorageComponent>(TEXT("Storage"));

	_world = GetWorld();
}

// Called when the game starts or when spawned
void ACPP_PlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController* player_controller = Cast<APlayerController>(Controller)) {

		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(player_controller->GetLocalPlayer())) {

			Subsystem->AddMappingContext(_default_mapping_context, 0);
		}
	}
}

// Called to bind functionality to input
void ACPP_PlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	UEnhancedInputComponent* enhanced_input_component = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (enhanced_input_component) {

		enhanced_input_component->BindAction(_move_action, ETriggerEvent::Triggered, this, &ACPP_PlayerCharacter::Move);

		enhanced_input_component->BindAction(_look_action, ETriggerEvent::Triggered, this, &ACPP_PlayerCharacter::Look);

		enhanced_input_component->BindAction(_interact_action, ETriggerEvent::Started, this, &ACPP_PlayerCharacter::haveItem);
	}

}

void ACPP_PlayerCharacter::Tick(float DeltaTime) {

	Super::Tick(DeltaTime);

	_selecting_actor = searchItem();
}

// 前後左右移動
void ACPP_PlayerCharacter::Move(const FInputActionValue& Value) {

	FVector2D move_vector = Value.Get<FVector2D>();

	if (Controller != nullptr) {

		AddMovementInput(GetActorForwardVector(), move_vector.Y);
		AddMovementInput(GetActorRightVector(), move_vector.X);
	}
}

// カメラの回転
void ACPP_PlayerCharacter::Look(const FInputActionValue& Value) {

	FVector2D look_vector = Value.Get<FVector2D>();

	if (Controller != nullptr) {

		AddControllerYawInput(look_vector.X);
		AddControllerPitchInput(look_vector.Y);
	}
}

// 画面中央のアクタを取得する
void ACPP_PlayerCharacter::haveItem() {

	if (!_selecting_actor) {
		UE_LOG(LogTemp, Log, TEXT("SelectingActor:%s"), _selecting_actor ? TEXT("true") : TEXT("false"));
		return;
	}

	TObjectPtr<ACPP_PickUp> hit_item = Cast<ACPP_PickUp>(_selecting_actor);

	ECPP_ItemEnum num = hit_item->getItemType();
	bool is_food = hit_item->getIsFood();

	UE_LOG(LogTemp, Log, TEXT("Item Num:%d Is Food:%s"), num, is_food ? TEXT("true") : TEXT("false"));

	if (hit_item) {
		// AC_ストレージに保存する
		_storage_component->saveItem(num, is_food);
	}
}

TObjectPtr<AActor> ACPP_PlayerCharacter::searchItem() {

	FHitResult hit_result;
	bool is_hit = false;

	if (!_world) {
		return nullptr;
	}

	FVector start = _camera_component->GetComponentLocation();
	FVector end = start + _camera_component->GetForwardVector() * ITEM_SEARCH_CAN_DISTANCE;
	ECollisionChannel trace_channel = ECC_Visibility;

	is_hit = _world->LineTraceSingleByChannel(hit_result, start, end, trace_channel);
	/*ライントレースのラインの可視化*/DrawDebugLine(_world, start, end, FColor::Red, false, 0.1f, 0, 1.0f);

	if (!is_hit) {
		return nullptr;
	}

	return hit_result.GetActor();
}

TObjectPtr<UCPP_StorageComponent> ACPP_PlayerCharacter::getStorageComponent() {

	return _storage_component;
}