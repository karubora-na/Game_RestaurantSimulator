// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <Components/BoxComponent.h>
#include "GameFramework/Actor.h"
#include "CPP_CookPlace.generated.h"

UCLASS()
class RESTAURANTSIMULATOR_API ACPP_CookPlace : public AActor
{
	GENERATED_BODY()
	
private:

	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> _mesh;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UBoxComponent> _collision;
public:	
	// Sets default values for this actor's propertie
	ACPP_CookPlace();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:

	UFUNCTION()
	void overlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
		bool bFromSweep, const FHitResult& SweepResult);
};
