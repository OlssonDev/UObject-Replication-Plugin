// Copyright 2022 OlssonDev


#include "FAssetTypeActions_ObjectReplicationBase.h"

#include "ObjectReplicationEditor.h"

FAssetTypeActions_ObjectReplicationBase::FAssetTypeActions_ObjectReplicationBase()
{
}

FColor FAssetTypeActions_ObjectReplicationBase::GetTypeColor() const
{
	return FAssetTypeActions_Blueprint::GetTypeColor();
}

uint32 FAssetTypeActions_ObjectReplicationBase::GetCategories()
{
	return FModuleManager::LoadModuleChecked<FObjectReplicationEditorModule>("ObjectReplicationEditor").ObjectReplicationCategory;
}
