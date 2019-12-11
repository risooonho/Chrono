// A prototype by Evangelos ("Vaggelis") Tsesmelidakis. All rights reserved. 2019

#pragma once

#include "CoreMinimal.h"
#include "ChronoCharacter.h"
#include "TimeTraveller.generated.h"

// Forward declerations
class UHistoryRecorder;

/**
 * 
 */
UCLASS()
class CHRONO_API ATimeTraveller : public AChronoCharacter
{
	GENERATED_BODY()

	ATimeTraveller();

public:
	UHistoryRecorder* GetTimeTravelComponent() const;

private:
	/** Component to implement character's time-travelling ability	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Time Travel", meta = (AllowPrivateAccess = "true"))
	UHistoryRecorder* TimeTravel;
	
};
