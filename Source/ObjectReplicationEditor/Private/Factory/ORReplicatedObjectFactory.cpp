// Copyright 2022 OlssonDev


#include "ORReplicatedObjectFactory.h"

#include "ORReplicatedObject.h"
#include "Kismet2/KismetEditorUtilities.h"

#define LOCTEXT_NAMESPACE "ORReplicatedObjectFactory"

UORReplicatedObjectFactory::UORReplicatedObjectFactory()
{
	bCreateNew = true;
	bEditAfterNew = true;

	#if ENGINE_MAJOR_VERSION == 5
	bSkipClassPicker = true;
	#endif
	
	SupportedClass = UORReplicatedObject::StaticClass();
	ParentClass = UORReplicatedObject::StaticClass();
}

UObject* UORReplicatedObjectFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn, FName CallingContext)
{
	return FKismetEditorUtilities::CreateBlueprint(ParentClass, InParent, Name, EBlueprintType::BPTYPE_Normal, UBlueprint::StaticClass(), UBlueprintGeneratedClass::StaticClass(), CallingContext);
}

UObject* UORReplicatedObjectFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	return Super::FactoryCreateNew(Class, InParent, Name, Flags, Context, Warn);
}

FString UORReplicatedObjectFactory::GetDefaultNewAssetName() const
{
	return FString(TEXT("NewReplicatedUObject"));
}

FText UORReplicatedObjectFactory::GetToolTip() const
{
	return LOCTEXT("ORReplicatedObjectFactory_Tooltip", "UObject that can be replicated by a Object Replication Manager.");
}

FText UORReplicatedObjectFactory::GetDisplayName() const
{
	return LOCTEXT("ORReplicatedObjectFactory_DisplayName", "Replicated UObject");
}

#undef LOCTEXT_NAMESPACE
