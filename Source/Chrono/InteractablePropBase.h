// Copyright 2019. All rights reserved. A prototype by Evangelos ("Vaggelis") Tsesmelidakis.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractablePropBase.generated.h"

/**
 * Base class to implement actor props that the player can interact with in the world (i.e. pick up them up and carry them, grab them or switch a component on etc.)
 */

UCLASS()
class CHRONO_API AInteractablePropBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractablePropBase();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintPure, Category = "Mesh")
	UStaticMeshComponent* GetMesh() const { return PropMesh; };

	UFUNCTION(BlueprintPure, Category = "Mesh")
	USphereComponent* GetTextTrigger() const { return TextTrigger; };

	UFUNCTION(BlueprintPure, Category = "Widget")
	FText GetPropName() const { return PropName; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* PropMesh; 

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "TextTrigger", meta = (AllowPrivateAccess = "true"))
	USphereComponent* TextTrigger; // forward declaration

	// Name this prop for text interface
	UPROPERTY(EditDefaultsOnly, Category = "Widget Setup", meta = (AllowPrivateAccess = "true"))
	FText PropName;
	
};