// Copyright 2022 OlssonDev


#include "FAssetTypeActions_ORManagerComponent.h"
#include "ORManagerComponent.h"

#define LOCTEXT_NAMESPACE "FAssetTypeActions_ORManagerComponent"

FAssetTypeActions_ORManagerComponent::FAssetTypeActions_ORManagerComponent()
{
}

FText FAssetTypeActions_ORManagerComponent::GetName() const
{
	return LOCTEXT("AssetTypeActions_ORManagerComponent", "Objection Replication Manager");
}

UClass* FAssetTypeActions_ORManagerComponent::GetSupportedClass() const
{
	return UORManagerComponent::StaticClass();
}

#undef LOCTEXT_NAMESPACE
