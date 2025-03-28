// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_HUD.h"
#include <Kismet/GameplayStatics.h>
#include <Blueprint/WidgetBlueprintLibrary.h>
#include <Blueprint/UserWidget.h>

void ACPP_HUD::BeginPlay()
{
	// ウィジェットブループリントのクラスを取得する
	FString _path = TEXT("/Game/MyProject/BP/UI/WBP_HUD.WBP_HUD_C");
	TSubclassOf<UUserWidget> _widget_class = TSoftClassPtr<UUserWidget>(FSoftObjectPath(*_path)).LoadSynchronous();

	// プレイヤーコントローラを取得する
	TObjectPtr<APlayerController> _player_controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	// 
	TObjectPtr<UUserWidget> _HUD_widget = nullptr;
	// WidgetClassとPlayerControllerが取得できたか判定する
	if (_widget_class && _player_controller)
	{
		// ウィジェットを作成
		_HUD_widget = CreateWidget<UUserWidget>(_player_controller, _widget_class);
	}

	if (_HUD_widget) {

		// ウィジェットを表示する
		_HUD_widget->AddToViewport(0);
	}
}