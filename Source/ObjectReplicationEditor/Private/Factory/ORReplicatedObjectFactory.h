// Copyright 2022 OlssonDev

#pragma once

#include "CoreMinimal.h"
#include "Factories/BlueprintFactory.h"
#include "ORReplicatedObjectFactory.generated.h"

UCLASS()
class UORReplicatedObjectFactory : public UBlueprintFactory
{
	GENERATED_BODY()

	public:

	UORReplicatedObjectFactory();

	// UFactory interface
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn, FName CallingContext) override;
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	virtual FString GetDefaultNewAssetName() const override;
	virtual FText GetToolTip() const override;
	virtual FText GetDisplayName() const override;
	#if ENGINE_MAJOR_VERSION == 4
	virtual bool ConfigureProperties() override
	{
		return true;
	};
	#endif
	//End of implementation
};
