// Copyright 2022 OlssonDev

#pragma once

#include "AssetTypeActions/AssetTypeActions_Blueprint.h"

class FAssetTypeActions_ObjectReplicationBase : public FAssetTypeActions_Blueprint
{
public:

	FAssetTypeActions_ObjectReplicationBase();
	
	// IAssetTypeActions interface
	virtual FColor GetTypeColor() const override;
	virtual uint32 GetCategories() override;
	// End of IAssetTypeActions interface
};
