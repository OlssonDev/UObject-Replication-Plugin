// Copyright 2022 OlssonDev

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class IAssetTypeActions;
class IAssetTools;

class FObjectReplicationEditorModule : public IModuleInterface
{
    public:
    
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;

    void RegisterAssetTypeAction(IAssetTools& AssetTools, TSharedRef<IAssetTypeActions> Action);

    public:

    TArray<TSharedPtr<IAssetTypeActions>> CreatedAssetTypeActions;
    static uint32 ObjectReplicationCategory;
};
