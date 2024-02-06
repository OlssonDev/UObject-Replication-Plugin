// Copyright 2022 OlssonDev


#include "ORManagerComponentFactory.h"

#include "ORManagerComponent.h"
#include "Kismet2/KismetEditorUtilities.h"

#define LOCTEXT_NAMESPACE "UORManagerComponentFactory"

UORManagerComponentFactory::UORManagerComponentFactory()
{
	bCreateNew = true;
	bEditAfterNew = true;

	#if ENGINE_MAJOR_VERSION == 5
	bSkipClassPicker = true;
	#endif
	
	SupportedClass = UORManagerComponent::StaticClass();
	ParentClass = UORManagerComponent::StaticClass();
}

UObject* UORManagerComponentFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn, FName CallingContext)
{
	return FKismetEditorUtilities::CreateBlueprint(ParentClass, InParent, Name, EBlueprintType::BPTYPE_Normal, UBlueprint::StaticClass(), UBlueprintGeneratedClass::StaticClass(), CallingContext);
}

UObject* UORManagerComponentFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	return Super::FactoryCreateNew(Class, InParent, Name, Flags, Context, Warn);
}

FString UORManagerComponentFactory::GetDefaultNewAssetName() const
{
	return FString(TEXT("NewReplicatedObjectManager"));
}

FText UORManagerComponentFactory::GetToolTip() const
{
	return LOCTEXT("ORManagerComponentFactory_Tooltip", "Manager that can be attached to any actor to replicate UObjects.");
}

FText UORManagerComponentFactory::GetDisplayName() const
{
	return LOCTEXT("ORManagerComponentFactory_DisplayName", "UObject Replication Manager");
}

#undef LOCTEXT_NAMESPACE
