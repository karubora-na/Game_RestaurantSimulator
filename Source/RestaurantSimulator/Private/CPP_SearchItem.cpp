// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_SearchItem.h"
#include "CPP_ItemEnum.h"

// Sets default values
ACPP_SearchItem::ACPP_SearchItem() {

}

// Called when the game starts or when spawned
void ACPP_SearchItem::BeginPlay()
{
	Super::BeginPlay();

	addRecipes(ECPP_ItemEnum::TUNA_RICE_BALL, ECPP_ItemEnum::TUNA, ECPP_ItemEnum::RICE, ECPP_ItemEnum::LAVER);
}

// Called every frame
void ACPP_SearchItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// 引数に指定したアイテムの組み合わせに該当するアイテムを検索
ECPP_ItemEnum ACPP_SearchItem::searchItem(ECPP_ItemEnum item1, ECPP_ItemEnum item2, ECPP_ItemEnum item3) {

	int item1_num = (int)item1;
	int item2_num = (int)item2;
	int item3_num = (int)item3;

	int item_num_array[3];
	bool is_success = sortByIncreasing(item_num_array, item1_num, item2_num, item3_num);
	if (is_success) {

		FCPP_KeyStruct item_key(item_num_array[0], item_num_array[1], item_num_array[2]);
		ECPP_ItemEnum* searched_item = _recipes.Find(item_key);

		UE_LOG(LogTemp, Log, TEXT("item1:%d,item2:%d,item3:%d"), (int)item_num_array[0], (int)item_num_array[1], (int)item_num_array[2]);

		if (searched_item) {

			return *searched_item;
		}
	}

	return ECPP_ItemEnum::NONE;
}

// レシピの設定
void ACPP_SearchItem::addRecipes(ECPP_ItemEnum food, ECPP_ItemEnum item1, ECPP_ItemEnum item2, ECPP_ItemEnum item3) {

	int item1_num = (int)item1;
	int item2_num = (int)item2;
	int item3_num = (int)item3;

	int item_num_array[3];
	bool is_success = sortByIncreasing(item_num_array, item1_num, item2_num, item3_num);
	if (is_success) {

		_recipes.Add(FCPP_KeyStruct(
			item_num_array[0],
			item_num_array[1],
			item_num_array[2]),
			food);
		int a = 0;
	}
	return;
}

// 昇順のソート　アイテムが３つ存在しない場合失敗
bool ACPP_SearchItem::sortByIncreasing(int* array, int key1, int key2, int key3) {

	if (key1 == 0 || key2 == 0 || key3 == 0) {
		return false;
	}

	int array_temp[3];
	int bigger_num;
	int smaller_num;

	if (key1 < key2) {
		smaller_num = key1;
		bigger_num = key2;
	}
	else {
		bigger_num = key1;
		smaller_num = key2;
	}

	if (bigger_num < key3) {

		array_temp[0] = smaller_num;
		array_temp[1] = bigger_num;
		array_temp[2] = key3;
	}
	else {

		if (smaller_num < key3) {

			array_temp[0] = smaller_num;
			array_temp[1] = key3;
			array_temp[2] = bigger_num;
		}
		else {

			array_temp[0] = key3;
			array_temp[1] = smaller_num;
			array_temp[2] = bigger_num;
		}
	}

	for (int i = 0; i < 3; i++) {
		array[i] = array_temp[i];
	}

	return true;
}
