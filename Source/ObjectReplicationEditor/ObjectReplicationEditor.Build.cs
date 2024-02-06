// Copyright 2022 OlssonDev

using UnrealBuildTool;

public class ObjectReplicationEditor : ModuleRules
{
    public ObjectReplicationEditor(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore", 
                "ObjectReplication",
                "AssetTools",
                "UnrealEd"
            }
        );
    }
}