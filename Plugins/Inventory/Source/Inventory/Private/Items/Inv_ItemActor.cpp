// Fill out your copyright notice in the Description page of Project Settings.

#include "Items/Inv_ItemActor.h"

#include "Interaction/Inv_HighlightableSkeletalMesh.h"
#include "Interaction/Inv_HighlightableStaticMesh.h"
#include "InventoryManagement/Utils/Inv_InventoryStatics.h"
#include "Items/Inv_ItemTags.h"
#include "Items/Components/Inv_ItemComponent.h"
#include "Items/Manifest/Inv_ItemManifest.h"
#include "Net/UnrealNetwork.h"

AInv_ItemActor::AInv_ItemActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bReplicates=true;
	
	ItemTag=GameItems::Consumables::Potions::Red::Small;
	
	ItemComponent = CreateDefaultSubobject<UInv_ItemComponent>("ItemComponent");
}

void AInv_ItemActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	//DOREPLIFETIME(ThisClass, ItemTag);
	DOREPLIFETIME_CONDITION(ThisClass, ItemTag,COND_InitialOnly);
}

void AInv_ItemActor::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	SetItemInfo();
}

void AInv_ItemActor::BeginPlay()
{
	Super::BeginPlay();
	SetItemInfo();
}

void AInv_ItemActor::SetItemInfo()
{
	const FItemMeshInfo itemInfo=UInv_InventoryStatics::GetItemMeshByTag(ItemTag);
	ItemComponent->InitItemManifest(itemInfo.ItemManifest);
	
	UInv_HighlightableSkeletalMesh* skeletalComp=FindComponentByClass<UInv_HighlightableSkeletalMesh>();
	UInv_HighlightableStaticMesh* staticComp=FindComponentByClass<UInv_HighlightableStaticMesh>();
	if (IsValid(itemInfo.StaticMesh))
	{
		TryDestroyComponent(skeletalComp);
		staticComp->SetStaticMesh(itemInfo.StaticMesh);
		staticComp->SetMaterial(0,itemInfo.Material);
		staticComp->SetRelativeScale3D(itemInfo.Scale);
	}
	else
	{
		TryDestroyComponent(staticComp);
		skeletalComp->SetSkeletalMesh(itemInfo.SkeletalMesh);
		skeletalComp->SetMaterial(0,itemInfo.Material);
		skeletalComp->SetRelativeScale3D(itemInfo.Scale);
	}
	BP_SetItemInfo(itemInfo.StaticMesh,itemInfo.SkeletalMesh,itemInfo.Material);
}

void AInv_ItemActor::TryDestroyComponent(UActorComponent* Component) const
{
	if (IsValid(Component))
	{
		Component->DestroyComponent();
	}
}
