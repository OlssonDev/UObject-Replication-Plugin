// Copyright 2022 OlssonDev

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ORReplicatedObject.generated.h"

UENUM(BlueprintType)
enum EORReplicationState
{
	//This UObject is considered for replication.
	Replicates,
	//This UObject is not considered for replication.
	DoNotReplicate,
};

/** 
 * The base class of all replicated UObjects in Object Replication Plugin.
 * This provides support for replicated UObjects.
 */
UCLASS(Blueprintable, BlueprintType, DisplayName = "Replicated UObject", Abstract)
class OBJECTREPLICATION_API UORReplicatedObject : public UObject
{
	GENERATED_BODY()

	public:

	//UObject interface implementation
	virtual UWorld* GetWorld() const override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual bool IsSupportedForNetworking() const override;
	virtual int32 GetFunctionCallspace(UFunction* Function, FFrame* Stack) override;
	virtual bool CallRemoteFunction(UFunction* Function, void* Parms, struct FOutParmRec* OutParms, FFrame* Stack) override;
	//End of implementation

	//Will mark this UObject as garbage and will eventually get cleaned by the garbage collector.
	//Should only execute this on the server.
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category = "Replicated UObject", DisplayName = "Destroy Replicated UObject")
	void DestroyObject();

	//Gets the Actor that "owns" this Replicated UObject.
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Replicated UObject")
	AActor* GetOwningActor() const;

	protected:

	//Will get called on the server once the Replicated UObject has been marked as garbage.
	UFUNCTION(BlueprintImplementableEvent, Category = "Replicated UObject", DisplayName = "On Replicated UObject Destroyed")
	void OnDestroyed();

	public:

	//Is this UObject replicated?
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Replicated UObject")
	TEnumAsByte<EORReplicationState> ReplicationState = EORReplicationState::Replicates;
	
};
