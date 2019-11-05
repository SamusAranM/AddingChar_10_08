// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class AddingChar_10_08EditorTarget : TargetRules
{
	public AddingChar_10_08EditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "AddingChar_10_08" } );
	}
}
