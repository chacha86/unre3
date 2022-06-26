// Copyright Epic Games, Inc. All Rights Reserved.


#include "collisionGameModeBase.h"
#include "MyPawn.h"

AcollisionGameModeBase::AcollisionGameModeBase()
{
	DefaultPawnClass = AMyPawn::StaticClass();
}
