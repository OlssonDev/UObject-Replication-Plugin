// Copyright 2022 OlssonDev

#include "ObjectReplicationEditor.h"
#include "AssetToolsModule.h"
#include "AssetTools/FAssetTypeActions_ORManagerComponent.h"
#include "AssetTools/FAssetTypeActions_ORReplicatedObject.h"

#define LOCTEXT_NAMESPACE "FObjectReplicationEditorModule"

uint32 FObjectReplicationEditorModule::ObjectReplicationCategory;

void FObjectReplicationEditorModule::StartupModule()
{
	{
		IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
		ObjectReplicationCategory = AssetTools.RegisterAdvancedAssetCategory(FName(TEXT("UObject Replication")), LOCTEXT("ObjectReplicationCategory", "UObject Replication"));
		RegisterAssetTypeAction(AssetTools, MakeShareable(new FAssetTypeActions_ORManagerComponent()));
		RegisterAssetTypeAction(AssetTools, MakeShareable(new FAssetTypeActions_ORReplicatedObject()));
	}
}

void FObjectReplicationEditorModule::RegisterAssetTypeAction(IAssetTools& AssetTools, TSharedRef<IAssetTypeActions> Action)
{
	AssetTools.RegisterAssetTypeActions(Action);
	CreatedAssetTypeActions.Add(Action);
}

void FObjectReplicationEditorModule::ShutdownModule()
{

}

#undef LOCTEXT_NAMESPACE
    
IMPLEMENT_MODULE(FObjectReplicationEditorModule, ObjectReplicationEditor)