// Copyright 2022 OlssonDev


#include "FAssetTypeActions_ORReplicatedObject.h"
#include "ORReplicatedObject.h"

#define LOCTEXT_NAMESPACE "FAssetTypeActions_ORReplicatedObject"

FAssetTypeActions_ORReplicatedObject::FAssetTypeActions_ORReplicatedObject()
{
}

FText FAssetTypeActions_ORReplicatedObject::GetName() const
{
	return FAssetTypeActions_ObjectReplicationBase::GetName();
}

UClass* FAssetTypeActions_ORReplicatedObject::GetSupportedClass() const
{
	return UORReplicatedObject::StaticClass();
}

#undef LOCTEXT_NAMESPACE
