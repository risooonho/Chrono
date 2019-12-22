// Copyright 2019. All rights reserved. A prototype by Evangelos ("Vaggelis") Tsesmelidakis.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimePortal.generated.h"

/*
 *Simple base class to implement time portals in the game. Main responsibilities include
 *sending out an event dispatch to inform of a time-travel event, and resetting scene or world
 *by moving objects or other actors to thei original location (or potential location of a specific
 * point in time dictated by player)
 */
UCLASS()
class CHRONO_API ATimePortal : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATimePortal();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	/* Set up components for the time portal in order to implement both the in-game functionality but also
	 * some additional elements to help setup and placement while working in the Editor
	 */

	// Bounds for the portal that triggers time travel
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Time Portal", meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* CollisionBox;

	// The teleport point that this portal is linked to (in space not in time; this is a location on the level)
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Time Portal", meta = (AllowPrivateAccess = "true"))
	class USceneComponent* TeleportLocation;

	// A "helper" text render so we can see exactly where the teleport spawn point is while working in the Editor
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Time Portal", meta = (AllowPrivateAccess = "true"))
	class UTextRenderComponent* TeleportLocationText;

	// An additional "helper" in the form of an arrow so we can see exactly where the teleport spawn point is while working in the Editor
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Time Portal", meta = (AllowPrivateAccess = "true"))
	class UArrowComponent* TeleportLocationArrow;

	// Boolean to toggle the portal
	UPROPERTY(EditAnywhere, Category = "Time Portal", meta = (AllowPrivateAccess = "true"))
	bool bIsActive = true;


};