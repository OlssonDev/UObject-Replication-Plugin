// Copyright 2022 OlssonDev

#pragma once

#include "CoreMinimal.h"
#include "FAssetTypeActions_ObjectReplicationBase.h"

class FAssetTypeActions_ORManagerComponent : public FAssetTypeActions_ObjectReplicationBase
{
	public:
	
	FAssetTypeActions_ORManagerComponent();
	
	// IAssetTypeActions interface
	virtual FText GetName() const override;
	virtual UClass* GetSupportedClass() const override;
	// End of IAssetTypeActions interface
};
