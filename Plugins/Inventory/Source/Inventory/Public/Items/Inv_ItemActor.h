// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFramework/Actor.h"
#include "Inv_ItemActor.generated.h"

struct FItemMeshInfo;
class UInv_ItemComponent;

UCLASS()
class INVENTORY_API AInv_ItemActor : public AActor
{
	GENERATED_BODY()
public:
	AInv_ItemActor();

protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void BeginPlay() override;
	
public:
	UInv_ItemComponent* GetItemComponent(){return ItemComponent;}
	void SetItemTag(FGameplayTag InTag){ItemTag=InTag;}
	
protected:
	void SetItemInfo();
	UFUNCTION(BlueprintImplementableEvent,meta = (DisplayName = "On Set Item Info"))
	void BP_SetItemInfo(UStaticMesh* InStaticMesh,USkeletalMesh* InSkeletalMesh, UMaterialInterface* InMaterial);
	
	void TryDestroyComponent(UActorComponent* Component) const;
	
protected:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UInv_ItemComponent> ItemComponent;
	
	UPROPERTY(Replicated,EditAnywhere, BlueprintReadOnly,Category="Item", meta = (Categories="GameItems"))
	FGameplayTag ItemTag;
};
