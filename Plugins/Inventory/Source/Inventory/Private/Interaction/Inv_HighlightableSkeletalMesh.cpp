// Fill out your copyright notice in the Description page of Project Settings.

#include "Interaction/Inv_HighlightableSkeletalMesh.h"

UInv_HighlightableSkeletalMesh::UInv_HighlightableSkeletalMesh()
{
	HighlightColor=FColor::White;
}

void UInv_HighlightableSkeletalMesh::BeginPlay()
{
	Super::BeginPlay();
	DynamicHighlightMaterial = UMaterialInstanceDynamic::Create(HighlightMaterial, this);
	DynamicHighlightMaterial->SetVectorParameterValue(TEXT("HighlightColor"),HighlightColor);
}

void UInv_HighlightableSkeletalMesh::Highlight_Implementation()
{
	SetOverlayMaterial(DynamicHighlightMaterial);
}

void UInv_HighlightableSkeletalMesh::UnHighlight_Implementation()
{
	SetOverlayMaterial(nullptr);
}
