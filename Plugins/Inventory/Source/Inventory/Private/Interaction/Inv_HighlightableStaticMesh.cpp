// Fill out your copyright notice in the Description page of Project Settings.

#include "Interaction/Inv_HighlightableStaticMesh.h"

UInv_HighlightableStaticMesh::UInv_HighlightableStaticMesh()
{
	HighlightColor=FColor::White;
}

void UInv_HighlightableStaticMesh::BeginPlay()
{
	Super::BeginPlay();
	DynamicHighlightMaterial = UMaterialInstanceDynamic::Create(HighlightMaterial, this);
	DynamicHighlightMaterial->SetVectorParameterValue(TEXT("HighlightColor"),HighlightColor);
}

void UInv_HighlightableStaticMesh::Highlight_Implementation()
{
	SetOverlayMaterial(DynamicHighlightMaterial);
}

void UInv_HighlightableStaticMesh::UnHighlight_Implementation()
{
	SetOverlayMaterial(nullptr);
}
