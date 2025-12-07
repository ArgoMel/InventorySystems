// Fill out your copyright notice in the Description page of Project Settings.

#include "EquipmentManagement/EquipActor/Inv_EquipActor.h"

#include "InventoryManagement/Utils/Inv_InventoryStatics.h"
#include "Items/Manifest/Inv_ItemManifest.h"
#include "Net/UnrealNetwork.h"

AInv_EquipActor::AInv_EquipActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bReplicates = true;
	
	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");
	
	SkeletalMeshComponent= CreateDefaultSubobject<USkeletalMeshComponent>("SkeletalMesh");
	SkeletalMeshComponent->SetupAttachment(RootComponent);
	SkeletalMeshComponent->SetCollisionProfileName(TEXT("NoCollision"));
	
	StaticMeshComponent= CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	StaticMeshComponent->SetupAttachment(RootComponent);
	StaticMeshComponent->SetCollisionProfileName(TEXT("NoCollision"));
}

void AInv_EquipActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	//DOREPLIFETIME(ThisClass, ItemTag);
	DOREPLIFETIME_CONDITION(ThisClass, ItemTag,COND_InitialOnly);
}

void AInv_EquipActor::BeginPlay()
{
	Super::BeginPlay();
	const FItemMeshInfo itemInfo=UInv_InventoryStatics::GetItemMeshByTag(ItemTag);
	
	if (IsValid(itemInfo.StaticMesh))
	{
		SkeletalMeshComponent->DestroyComponent();
		StaticMeshComponent->SetStaticMesh(itemInfo.StaticMesh);
		StaticMeshComponent->SetMaterial(0,itemInfo.Material);
	}
	else
	{
		StaticMeshComponent->DestroyComponent();
		SkeletalMeshComponent->SetSkeletalMesh(itemInfo.SkeletalMesh);
		SkeletalMeshComponent->SetMaterial(0,itemInfo.Material);
	}
}
