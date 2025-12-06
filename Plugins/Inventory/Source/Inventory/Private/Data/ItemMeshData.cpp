// Fill out your copyright notice in the Description page of Project Settings.

#include "Data/ItemMeshData.h"

#include "Inventory.h"

FItemMeshInfo UItemMeshData::FindItemMeshInfoForTag(const FGameplayTag& Tag, bool bLogNotFound) const
{
	if (ItemMeshInformation.Contains(Tag))
	{
		return ItemMeshInformation.FindRef(Tag);
	}

	if (bLogNotFound)
	{
		UE_LOG(LogInventory, Error, TEXT("Can't find info for Tag [%s] on Tag [%s]"), *Tag.ToString(), *GetNameSafe(this));
	}

	return FItemMeshInfo();
}
