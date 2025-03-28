// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_HUD.h"
#include <Kismet/GameplayStatics.h>
#include <Blueprint/WidgetBlueprintLibrary.h>
#include <Blueprint/UserWidget.h>

void ACPP_HUD::BeginPlay()
{
	// �E�B�W�F�b�g�u���[�v�����g�̃N���X���擾����
	FString _path = TEXT("/Game/MyProject/BP/UI/WBP_HUD.WBP_HUD_C");
	TSubclassOf<UUserWidget> _widget_class = TSoftClassPtr<UUserWidget>(FSoftObjectPath(*_path)).LoadSynchronous();

	// �v���C���[�R���g���[�����擾����
	TObjectPtr<APlayerController> _player_controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	// 
	TObjectPtr<UUserWidget> _HUD_widget = nullptr;
	// WidgetClass��PlayerController���擾�ł��������肷��
	if (_widget_class && _player_controller)
	{
		// �E�B�W�F�b�g���쐬
		_HUD_widget = CreateWidget<UUserWidget>(_player_controller, _widget_class);
	}

	if (_HUD_widget) {

		// �E�B�W�F�b�g��\������
		_HUD_widget->AddToViewport(0);
	}
}