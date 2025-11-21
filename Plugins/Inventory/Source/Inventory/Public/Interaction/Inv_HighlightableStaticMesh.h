// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Inv_Highlightable.h"
#include "Components/StaticMeshComponent.h"
#include "Inv_HighlightableStaticMesh.generated.h"

UCLASS()
class INVENTORY_API UInv_HighlightableStaticMesh : public UStaticMeshComponent, public IInv_Highlightable
{
	GENERATED_BODY()
public:
	UInv_HighlightableStaticMesh();
protected:
	virtual void BeginPlay() override;
	
public:
	virtual void Highlight_Implementation() override;
	virtual void UnHighlight_Implementation() override;

private:
	UPROPERTY(EditAnywhere, Category = "Inventory")
	TObjectPtr<UMaterialInterface> HighlightMaterial;
	UPROPERTY()
	TObjectPtr<UMaterialInstanceDynamic> DynamicHighlightMaterial;
	UPROPERTY(EditAnywhere, Category = "Inventory")
	FLinearColor HighlightColor;
};
