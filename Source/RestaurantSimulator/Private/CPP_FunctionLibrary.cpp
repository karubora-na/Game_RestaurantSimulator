// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_FunctionLibrary.h"
#include "Kismet/KismetSystemLibrary.h"

CPP_FunctionLibrary::CPP_FunctionLibrary()
{
}

CPP_FunctionLibrary::~CPP_FunctionLibrary()
{
}
// GetWorld(),TEXT()
void CPP_FunctionLibrary::outputString(TObjectPtr<UObject> WorldContextObject, FString text) {

	UKismetSystemLibrary::PrintString(
		WorldContextObject,
		text,
		true,   // コンソールに表示するか
		true,   // 画面上に表示するか
		FColor::Blue,
		5.0f    // 表示時間（秒）
	);
}
// GetWorld(),TEXT(),FColor::
void CPP_FunctionLibrary::outputString(TObjectPtr<UObject> WorldContextObject, FString text, FColor text_color) {

	UKismetSystemLibrary::PrintString(
		WorldContextObject,
		text,
		true,   // コンソールに表示するか
		true,   // 画面上に表示するか
		text_color,
		5.0f    // 表示時間（秒）
	);
}

