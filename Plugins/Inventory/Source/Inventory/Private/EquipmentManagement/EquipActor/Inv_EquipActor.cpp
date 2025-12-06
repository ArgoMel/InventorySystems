// Fill out your copyright notice in the Description page of Project Settings.

#include "EquipmentManagement/EquipActor/Inv_EquipActor.h"

AInv_EquipActor::AInv_EquipActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bReplicates = true;
	
	GetSkeletalMeshComponent()->SetCollisionProfileName(TEXT("NoCollision"));
}

void AInv_EquipActor::SetEquipMesh(USkeletalMesh* NewMesh,UMaterialInterface* InMat) const
{
	GetSkeletalMeshComponent()->SetSkeletalMesh(NewMesh);
	if (IsValid(InMat))
	{
		GetSkeletalMeshComponent()->SetMaterial(0,InMat);
	}
}
