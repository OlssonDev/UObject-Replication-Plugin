// Copyright 2022 OlssonDev

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FObjectReplicationModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
