// Fill out your copyright notice in the Description page of Project Settings.

#include "CPP_CookPlace.h"
#include "RestaurantSimulator/CPP_PlayerCharacter.h"
#include "CPP_SearchItem.h"
#include "CPP_ItemEnum.h"
#include "CPP_FunctionLibrary.h"
#include <Kismet/GameplayStatics.h>

// Sets default values
ACPP_CookPlace::ACPP_CookPlace()
{
	// ���b�V���R���|�[�l���g�̍쐬
	_mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	_mesh->SetupAttachment(RootComponent);

	// �R���W�����R���|�[�l���g�̍쐬
	_collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	_collision->SetupAttachment(_mesh);
}

// Called when the game starts or when spawned
void ACPP_CookPlace::BeginPlay()
{
	Super::BeginPlay();

	_collision->OnComponentBeginOverlap.AddDynamic(this, &ACPP_CookPlace::overlapBegin);
}

// Called every frame
void ACPP_CookPlace::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPP_CookPlace::overlapBegin(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult) {

	TObjectPtr<ACPP_PlayerCharacter> player = Cast<ACPP_PlayerCharacter>(OtherActor);
	if (player) {

		CPP_FunctionLibrary::outputString(GetWorld(), TEXT("CookPlace overlapBegin:Success"));

		// �v���C���[���������Ă���A�C�e���ԍ����擾
		ECPP_ItemEnum item_enum_array_temp[MAX_STORAGE_RANGE];
		TObjectPtr<UCPP_StorageComponent> _storage_component = player->getStorageComponent();
		if (_storage_component) {

			_storage_component->getItemNum(item_enum_array_temp);

			// SearchItem�̃I�u�W�F�N�g���擾
			// SearchItem�I�u�W�F�N�g�̎擾�p�z��i�P�������݂���j
			TArray<TObjectPtr<AActor>> actor_array_temp;
			// SearchItem�I�u�W�F�N�g
			TObjectPtr<ACPP_SearchItem> search_item_actor = nullptr;
			UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACPP_SearchItem::StaticClass(), actor_array_temp);
			if (actor_array_temp.Num() != 1) {

				CPP_FunctionLibrary::outputString(GetWorld(), TEXT("error:Not once searchItem obj exist."));
				return;
			}
			else {

				search_item_actor = Cast<ACPP_SearchItem>(actor_array_temp[0]);
			}

			// �����A�C�e������쐬�\�ȃA�C�e��������o��
			if (search_item_actor) {

				ECPP_ItemEnum item0 = item_enum_array_temp[0];
				ECPP_ItemEnum item1 = item_enum_array_temp[1];
				ECPP_ItemEnum item2 = item_enum_array_temp[2];

				ECPP_ItemEnum can_cook_item_num = search_item_actor->searchItem(item0, item1, item2);

				CPP_FunctionLibrary::outputString(
					GetWorld(),
					FString::Printf(TEXT("can_cook_item_num:%d"), (int)can_cook_item_num)
				);
			}
			else {
				CPP_FunctionLibrary::outputString(GetWorld(), TEXT("error:SearchItem obj is not valid."));
				return;
			}
		}
	}
}
