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
		true,   // �R���\�[���ɕ\�����邩
		true,   // ��ʏ�ɕ\�����邩
		FColor::Blue,
		5.0f    // �\�����ԁi�b�j
	);
}
// GetWorld(),TEXT(),FColor::
void CPP_FunctionLibrary::outputString(TObjectPtr<UObject> WorldContextObject, FString text, FColor text_color) {

	UKismetSystemLibrary::PrintString(
		WorldContextObject,
		text,
		true,   // �R���\�[���ɕ\�����邩
		true,   // ��ʏ�ɕ\�����邩
		text_color,
		5.0f    // �\�����ԁi�b�j
	);
}

