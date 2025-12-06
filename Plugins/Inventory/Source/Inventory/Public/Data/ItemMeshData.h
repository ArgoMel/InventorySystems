// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "Items/Manifest/Inv_ItemManifest.h"
#include "ItemMeshData.generated.h"

UCLASS(Blueprintable)
class INVENTORY_API UItemMeshData : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "ItemMeshInformation", meta = (Categories="GameItems"))
	TMap<FGameplayTag,FItemMeshInfo> ItemMeshInformation;
	
public:
	FItemMeshInfo FindItemMeshInfoForTag(const FGameplayTag& Tag, bool bLogNotFound = false) const;
};
