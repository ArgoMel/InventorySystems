// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFramework/Actor.h"
#include "Inv_EquipActor.generated.h"

UCLASS()
class INVENTORY_API AInv_EquipActor : public AActor
{
	GENERATED_BODY()
public:
	AInv_EquipActor();
protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void BeginPlay() override;
	
public:
	FGameplayTag GetEquipmentType() const { return EquipmentType; }
	void SetEquipmentType(FGameplayTag Type) { EquipmentType = Type; }
	void SetItemTag(FGameplayTag Type) { ItemTag = Type; }

private:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USkeletalMeshComponent> SkeletalMeshComponent;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> StaticMeshComponent;
	
	UPROPERTY(VisibleAnywhere, Category = "Inventory")
	FGameplayTag EquipmentType;
	UPROPERTY(Replicated, VisibleAnywhere,Category = "Inventory")
	FGameplayTag ItemTag;
};
