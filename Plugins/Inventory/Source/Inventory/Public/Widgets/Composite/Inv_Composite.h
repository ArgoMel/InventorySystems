// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Inv_CompositeBase.h"
#include "Inv_Composite.generated.h"

UCLASS(Abstract)
class INVENTORY_API UInv_Composite : public UInv_CompositeBase
{
	GENERATED_BODY()
protected:
	virtual void NativeOnInitialized() override;
	
public:
	virtual void Collapse() override;
	virtual void ApplyFunction(FuncType Function) override;
	
public:
	TArray<UInv_CompositeBase*> GetChildren() { return Children; }
	
private:
	UPROPERTY()
	TArray<TObjectPtr<UInv_CompositeBase>> Children;
};
