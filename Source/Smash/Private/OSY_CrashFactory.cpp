// Fill out your copyright notice in the Description page of Project Settings.


#include "OSY_CrashFactory.h"
#include "OSY_NodeActor.h"
#include "OSY_CrashNodeActor.h"

// Sets default values
AOSY_CrashFactory::AOSY_CrashFactory()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AOSY_CrashFactory::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOSY_CrashFactory::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	currentTime += DeltaTime;
	UE_LOG(LogTemp, Warning, TEXT("currentTime : %f"), currentTime);

	TArray<float> spawnTimes = 
	{ 9.25f,9.5625f,9.875f,10.1875f,10.5f,10.8125f,11.125f,11.4375f,11.75f,12.0625f,12.375f,12.6875f,13.f,13.3125f,13.625f,13.9375f,14.25f,14.5625f,14.875f,15.1875f,15.5f,15.8125f,16.125f,16.4375f,16.75f,17.0625f,17.375f,17.6875f,19.25f,29.25f,33.9375f,34.25f,40.5f,40.8125f,41.125f,41.4375f,41.75f,42.0625f,42.375f,42.6875f,43.f,43.3125f,43.625f,43.9375f,44.25f,44.5625f,44.875f,45.1875f,45.5f,45.8125f,46.125f,46.4375f,46.75f,47.0625f,47.375f,47.6875f,48.f,48.3125f,48.625f,48.9375f,49.25f,49.5625f,49.875f,50.5f,55.5f,65.5f,70.1875f,70.5f,76.75f,77.0625f,77.375f,77.6875f,78.f,78.3125f,78.625f,78.9375f,79.25f,79.5625f,79.875f,80.1875f,80.5f,80.8125f,81.125f,81.4375f,81.75f,82.0625f,82.375f,82.6875f,83.f,83.3125f,83.625f,83.9375f,84.25f,84.5625f,84.875f,85.1875f,85.5f,85.8125f,86.75f,87.0625f,87.375f,87.6875f,88.f,88.3125f,88.625f,88.9375f,89.25f,89.5625f,89.875f,90.1875f,90.5f,91.125f,91.75f,92.0625f,92.375f,92.6875f,93.f,93.3125f,93.625f,93.9375f,94.25f,94.5625f,94.875f,95.1875f,96.75f,97.0625f,97.375f,97.6875f,98.f,98.3125f,98.625f,99.25f,99.5625f,99.875f,100.1875f,100.5f,100.8125f,101.125f,101.75f,102.0625f,102.375f,102.6875f,103.f,103.3125f,103.625f,104.25f,104.5625f,104.875f,105.1875f,105.5f,105.8125f,106.125f,111.75f,116.28125f,116.75f,121.75f,122.0625f,122.375f,122.6875f,123.f,123.3125f,123.625f,123.9375f,124.25f,124.5625f,124.875f,125.1875f,125.5f,125.8125f,126.125f,126.4375f,126.75f,127.0625f,127.375f,127.6875f,128.f,128.3125f,128.625f,128.9375f,129.25f,129.5625f,129.875f,130.1875f,130.5f,133.f,133.3125f,133.625f,133.9375f,134.25f,134.5625f,134.875f,135.1875f,135.5f,135.8125f,136.125f,136.4375f,136.75f,137.0625f,137.375f,137.6875f,138.f,138.3125f,138.625f,138.9375f,139.25f,139.5625f,139.875f,140.1875f,140.5f,140.8125f,141.125f,141.4375f,141.75f,141.90625f,143.f,143.3125f,143.625f,143.9375f,144.25f,144.5625f,144.875f,145.1875f,145.5f,145.8125f,146.125f,146.4375f,146.75f,147.0625f,147.375f,147.6875f,148.f,148.3125f,148.625f,148.9375f,149.25f,149.5625f,149.875f,150.1875f,150.5f,150.8125f,151.125f,151.4375f,151.75f,152.0625f,152.375f,152.6875f,153.f,153.3125f,154.25f

	};

	for (float spawnTime : spawnTimes)
	{
		if (currentTime >= spawnTime && currentTime - DeltaTime < spawnTime)
		{
			spawnCrashNode();
		}
	}


/*
#pragma region 10
	if (currentTime >= 10.9908 && (currentTime - DeltaTime) < 10.9908)
	{
		spawnCrashNode();
	}
	if (currentTime >= 11.2961 && (currentTime - DeltaTime) < 11.2961)
	{
		spawnCrashNode();
	}
	if (currentTime >= 11.6014 && (currentTime - DeltaTime) < 11.6014)
	{
		spawnCrashNode();
	}
	if (currentTime >= 11.9067 && (currentTime - DeltaTime) < 11.9067)
	{
		spawnCrashNode();
	}
#pragma endregion 10
#pragma region 11
	if (currentTime >= 12.212 && (currentTime - DeltaTime) < 12.212)
	{
		spawnCrashNode();
	}
	if (currentTime >= 12.5173 && (currentTime - DeltaTime) < 12.5173)
	{
		spawnCrashNode();
	}
	if (currentTime >= 12.8226 && (currentTime - DeltaTime) < 12.8226)
	{
		spawnCrashNode();
	}
	if (currentTime >= 13.1279 && (currentTime - DeltaTime) < 13.1279)
	{
		spawnCrashNode();
	}
#pragma endregion 11
#pragma region 12
	if (currentTime >= 13.4332 && (currentTime - DeltaTime) < 13.4332)
	{
		spawnCrashNode();
	}
	if (currentTime >= 13.7385 && (currentTime - DeltaTime) < 13.7385)
	{
		spawnCrashNode();
	}
	if (currentTime >= 14.0438 && (currentTime - DeltaTime) < 14.0438)
	{
		spawnCrashNode();
	}
	if (currentTime >= 14.3491 && (currentTime - DeltaTime) < 14.3491)
	{
		spawnCrashNode();
	}
	if (currentTime >= 14.425425 && (currentTime - DeltaTime) < 14.425425)
	{
		spawnCrashNode();
	}
#pragma endregion 12
#pragma region 13
	if (currentTime >= 14.6544 && (currentTime - DeltaTime) < 14.6544)
	{
		spawnCrashNode();
	}
	if (currentTime >= 15.265 && (currentTime - DeltaTime) < 15.265)
	{
		spawnCrashNode();
	}
#pragma endregion 13
#pragma region 18
	if (currentTime >= 20.7604 && (currentTime - DeltaTime) < 20.7604)
	{
		spawnCrashNode();
	}
#pragma endregion 18
#pragma region 26
	if (currentTime >= 30.53 && (currentTime - DeltaTime) < 30.53)
	{
		spawnCrashNode();
	}
#pragma endregion 26
#pragma region 30
	if (currentTime >= 35.4148 && (currentTime - DeltaTime) < 35.4148)
	{
		spawnCrashNode();
	}
#pragma endregion 30
#pragma region 35
	if (currentTime >= 41.5208 && (currentTime - DeltaTime) < 41.5208)
	{
		spawnCrashNode();
	}
	if (currentTime >= 41.8261 && (currentTime - DeltaTime) < 41.8261)
	{
		spawnCrashNode();
	}
	if (currentTime >= 42.1314 && (currentTime - DeltaTime) < 42.1314)
	{
		spawnCrashNode();
	}
	if (currentTime >= 42.4367 && (currentTime - DeltaTime) < 42.4367)
	{
		spawnCrashNode();
	}
#pragma endregion 35
#pragma region 36
	if (currentTime >= 42.742 && (currentTime - DeltaTime) < 42.742)
	{
		spawnCrashNode();
	}
	if (currentTime >= 43.0473 && (currentTime - DeltaTime) < 43.0473)
	{
		spawnCrashNode();
	}
	if (currentTime >= 43.3526 && (currentTime - DeltaTime) < 43.3526)
	{
		spawnCrashNode();
	}
	if (currentTime >= 43.6579 && (currentTime - DeltaTime) < 43.6579)
	{
		spawnCrashNode();
	}
#pragma endregion 36
#pragma region 37
	if (currentTime >= 43.9632 && (currentTime - DeltaTime) < 43.9632)
	{
		spawnCrashNode();
	}
	if (currentTime >= 44.2685 && (currentTime - DeltaTime) < 44.2685)
	{
		spawnCrashNode();
	}
	if (currentTime >= 44.5738 && (currentTime - DeltaTime) < 44.5738)
	{
		spawnCrashNode();
	}
	if (currentTime >= 44.8791 && (currentTime - DeltaTime) < 44.8791)
	{
		spawnCrashNode();
	}
#pragma endregion 37
#pragma region 38
	if (currentTime >= 45.1844 && (currentTime - DeltaTime) < 45.1844)
	{
		spawnCrashNode();
	}
	if (currentTime >= 45.795 && (currentTime - DeltaTime) < 45.795)
	{
		spawnCrashNode();
	}
#pragma endregion 38
#pragma region 39
	if (currentTime >= 46.4056 && (currentTime - DeltaTime) < 46.4056)
	{
		spawnCrashNode();
	}
	if (currentTime >= 46.7109 && (currentTime - DeltaTime) < 46.7109)
	{
		spawnCrashNode();
	}
	if (currentTime >= 47.0162 && (currentTime - DeltaTime) < 47.0162)
	{
		spawnCrashNode();
	}
	if (currentTime >= 47.3215 && (currentTime - DeltaTime) < 47.3215)
	{
		spawnCrashNode();
	}
#pragma endregion 39
#pragma region 40
	if (currentTime >= 47.6268 && (currentTime - DeltaTime) < 47.6268)
	{
		spawnCrashNode();
	}
	if (currentTime >= 47.9321 && (currentTime - DeltaTime) < 47.9321)
	{
		spawnCrashNode();
	}
	if (currentTime >= 48.2374 && (currentTime - DeltaTime) < 48.2374)
	{
		spawnCrashNode();
	}
	if (currentTime >= 48.5427 && (currentTime - DeltaTime) < 48.5427)
	{
		spawnCrashNode();
	}
#pragma endregion 40
#pragma region 41
	if (currentTime >= 48.848 && (currentTime - DeltaTime) < 48.848)
	{
		spawnCrashNode();
	}
	if (currentTime >= 49.1533 && (currentTime - DeltaTime) < 49.1533)
	{
		spawnCrashNode();
	}
	if (currentTime >= 49.4586 && (currentTime - DeltaTime) < 49.4586)
	{
		spawnCrashNode();
	}
	if (currentTime >= 49.7639 && (currentTime - DeltaTime) < 49.7639)
	{
		spawnCrashNode();
	}
#pragma endregion 41
#pragma region 42
	if (currentTime >= 50.0692 && (currentTime - DeltaTime) < 50.0692)
	{
		spawnCrashNode();
	}
#pragma endregion 42
#pragma region 43
	if (currentTime >= 51.2904 && (currentTime - DeltaTime) < 51.2904)
	{
		spawnCrashNode();
	}
#pragma endregion 43
#pragma region 43
	if (currentTime >= 56.1752 && (currentTime - DeltaTime) < 56.1752)
	{
		spawnCrashNode();
	}
#pragma endregion 43
#pragma region 47
	if (currentTime >= 56.1752 && (currentTime - DeltaTime) < 56.1752)
	{
		spawnCrashNode();
	}
#pragma endregion 47
#pragma region 55
	if (currentTime >= 65.9448 && (currentTime - DeltaTime) < 65.9448)
	{
		spawnCrashNode();
	}
#pragma endregion 55
#pragma region 59
	if (currentTime >= 70.8296 && (currentTime - DeltaTime) < 70.8296)
	{
		spawnCrashNode();
	}
#pragma endregion 59
#pragma region 64
	if (currentTime >= 76.9356 && (currentTime - DeltaTime) < 76.9356)
	{
		spawnCrashNode();
	}
	if (currentTime >= 77.2409 && (currentTime - DeltaTime) < 77.2409)
	{
		spawnCrashNode();
	}
	if (currentTime >= 77.5462 && (currentTime - DeltaTime) < 77.5462)
	{
		spawnCrashNode();
	}
	if (currentTime >= 77.8515 && (currentTime - DeltaTime) < 77.8515)
	{
		spawnCrashNode();
	}
#pragma endregion 64
#pragma region 65
	if (currentTime >= 78.1568 && (currentTime - DeltaTime) < 78.1568)
	{
		spawnCrashNode();
	}
	if (currentTime >= 78.4621 && (currentTime - DeltaTime) < 78.4621)
	{
		spawnCrashNode();
	}
	if (currentTime >= 78.7674 && (currentTime - DeltaTime) < 78.7674)
	{
		spawnCrashNode();
	}
	if (currentTime >= 79.0727 && (currentTime - DeltaTime) < 79.0727)
	{
		spawnCrashNode();
	}
#pragma endregion 65
#pragma region 66
	if (currentTime >= 79.378 && (currentTime - DeltaTime) < 79.378)
	{
		spawnCrashNode();
	}
	if (currentTime >= 79.6833 && (currentTime - DeltaTime) < 79.6833)
	{
		spawnCrashNode();
	}
	if (currentTime >= 79.9886 && (currentTime - DeltaTime) < 79.9886)
	{
		spawnCrashNode();
	}
	if (currentTime >= 80.2939 && (currentTime - DeltaTime) < 80.2939)
	{
		spawnCrashNode();
	}
#pragma endregion 66
#pragma region 67
	if (currentTime >= 80.5992 && (currentTime - DeltaTime) < 80.5992)
	{
		spawnCrashNode();
	}
	if (currentTime >= 81.2098 && (currentTime - DeltaTime) < 81.2098)
	{
		spawnCrashNode();
	}
#pragma endregion 67
#pragma region 72
	if (currentTime >= 86.7052 && (currentTime - DeltaTime) < 86.7052)
	{
		spawnCrashNode();
	}
	if (currentTime >= 87.0105 && (currentTime - DeltaTime) < 87.0105)
	{
		spawnCrashNode();
	}
	if (currentTime >= 87.3158 && (currentTime - DeltaTime) < 87.3158)
	{
		spawnCrashNode();
	}
	if (currentTime >= 87.6211 && (currentTime - DeltaTime) < 87.6211)
	{
		spawnCrashNode();
	}
#pragma endregion 72
#pragma region 73
	if (currentTime >= 87.9264 && (currentTime - DeltaTime) < 87.9264)
	{
		spawnCrashNode();
	}
	if (currentTime >= 88.2317 && (currentTime - DeltaTime) < 88.2317)
	{
		spawnCrashNode();
	}
	if (currentTime >= 88.537 && (currentTime - DeltaTime) < 88.537)
	{
		spawnCrashNode();
	}
	if (currentTime >= 88.8423 && (currentTime - DeltaTime) < 88.8423)
	{
		spawnCrashNode();
	}
#pragma endregion 73
#pragma region 74
	if (currentTime >= 89.1476 && (currentTime - DeltaTime) < 89.1476)
	{
		spawnCrashNode();
	}
	if (currentTime >= 89.4529 && (currentTime - DeltaTime) < 89.4529)
	{
		spawnCrashNode();
	}
	if (currentTime >= 89.7582 && (currentTime - DeltaTime) < 89.7582)
	{
		spawnCrashNode();
	}
	if (currentTime >= 90.0635 && (currentTime - DeltaTime) < 90.0635)
	{
		spawnCrashNode();
	}
#pragma endregion 74
#pragma region 75
	if (currentTime >= 90.3688 && (currentTime - DeltaTime) < 90.3688)
	{
		spawnCrashNode();
	}
	if (currentTime >= 90.9794 && (currentTime - DeltaTime) < 90.9794)
	{
		spawnCrashNode();
	}
#pragma endregion 75
#pragma region 76
	if (currentTime >= 91.59 && (currentTime - DeltaTime) < 91.59)
	{
		spawnCrashNode();
	}
	if (currentTime >= 91.8953 && (currentTime - DeltaTime) < 91.8953)
	{
		spawnCrashNode();
	}
	if (currentTime >= 92.2006 && (currentTime - DeltaTime) < 92.2006)
	{
		spawnCrashNode();
	}
	if (currentTime >= 92.5059 && (currentTime - DeltaTime) < 92.5059)
	{
		spawnCrashNode();
	}
#pragma endregion 76
#pragma region 77
	if (currentTime >= 92.8112 && (currentTime - DeltaTime) < 92.8112)
	{
		spawnCrashNode();
	}
	if (currentTime >= 93.1165 && (currentTime - DeltaTime) < 93.1165)
	{
		spawnCrashNode();
	}
	if (currentTime >= 93.4218 && (currentTime - DeltaTime) < 93.4218)
	{
		spawnCrashNode();
	}
	if (currentTime >= 93.7271 && (currentTime - DeltaTime) < 93.7271)
	{
		spawnCrashNode();
	}
#pragma endregion 77
#pragma region 78
	if (currentTime >= 94.0324 && (currentTime - DeltaTime) < 94.0324)
	{
		spawnCrashNode();
	}
	if (currentTime >= 94.3377 && (currentTime - DeltaTime) < 94.3377)
	{
		spawnCrashNode();
	}
	if (currentTime >= 94.643 && (currentTime - DeltaTime) < 94.643)
	{
		spawnCrashNode();
	}
	if (currentTime >= 94.9483 && (currentTime - DeltaTime) < 94.9483)
	{
		spawnCrashNode();
	}
#pragma endregion 78
#pragma region 80
	if (currentTime >= 96.4748 && (currentTime - DeltaTime) < 96.4748)
	{
		spawnCrashNode();
	}
	if (currentTime >= 96.7801 && (currentTime - DeltaTime) < 96.7801)
	{
		spawnCrashNode();
	}
	if (currentTime >= 97.0854 && (currentTime - DeltaTime) < 97.0854)
	{
		spawnCrashNode();
	}
	if (currentTime >= 97.3907 && (currentTime - DeltaTime) < 97.3907)
	{
		spawnCrashNode();
	}
#pragma endregion 80
#pragma region 81
	if (currentTime >= 97.696 && (currentTime - DeltaTime) < 97.696)
	{
		spawnCrashNode();
	}
	if (currentTime >= 98.0013 && (currentTime - DeltaTime) < 98.0013)
	{
		spawnCrashNode();
	}
	if (currentTime >= 98.3066 && (currentTime - DeltaTime) < 98.3066)
	{
		spawnCrashNode();
	}
#pragma endregion 81
#pragma region 82
	if (currentTime >= 98.9172 && (currentTime - DeltaTime) < 98.9172)
	{
		spawnCrashNode();
	}
	if (currentTime >= 99.2225 && (currentTime - DeltaTime) < 99.2225)
	{
		spawnCrashNode();
	}
	if (currentTime >= 99.5278 && (currentTime - DeltaTime) < 99.5278)
	{
		spawnCrashNode();
	}
#pragma endregion 82
#pragma region 83
	if (currentTime >= 100.1384 && (currentTime - DeltaTime) < 100.1384)
	{
		spawnCrashNode();
	}
	if (currentTime >= 100.4437 && (currentTime - DeltaTime) < 100.4437)
	{
		spawnCrashNode();
	}
	if (currentTime >= 100.749 && (currentTime - DeltaTime) < 100.749)
	{
		spawnCrashNode();
	}
#pragma endregion 83
#pragma region 84
	if (currentTime >= 101.3596 && (currentTime - DeltaTime) < 101.3596)
	{
		spawnCrashNode();
	}
	if (currentTime >= 101.6649 && (currentTime - DeltaTime) < 101.6649)
	{
		spawnCrashNode();
	}
	if (currentTime >= 101.9702 && (currentTime - DeltaTime) < 101.9702)
	{
		spawnCrashNode();
	}
	if (currentTime >= 102.2755 && (currentTime - DeltaTime) < 102.2755)
	{
		spawnCrashNode();
	}
#pragma endregion 84
#pragma region 85
	if (currentTime >= 102.5808 && (currentTime - DeltaTime) < 102.5808)
	{
		spawnCrashNode();
	}
	if (currentTime >= 102.8861 && (currentTime - DeltaTime) < 102.8861)
	{
		spawnCrashNode();
	}
	if (currentTime >= 103.1914 && (currentTime - DeltaTime) < 103.1914)
	{
		spawnCrashNode();
	}
#pragma endregion 85
#pragma region 86
	if (currentTime >= 103.802 && (currentTime - DeltaTime) < 103.802)
	{
		spawnCrashNode();
	}
	if (currentTime >= 104.1073 && (currentTime - DeltaTime) < 104.1073)
	{
		spawnCrashNode();
	}
	if (currentTime >= 104.4126 && (currentTime - DeltaTime) < 104.4126)
	{
		spawnCrashNode();
	}
	if (currentTime >= 104.7179 && (currentTime - DeltaTime) < 104.7179)
	{
		spawnCrashNode();
	}
#pragma endregion 86
#pragma region 87
	if (currentTime >= 105.0232 && (currentTime - DeltaTime) < 105.0232)
	{
		spawnCrashNode();
	}
	if (currentTime >= 105.3285 && (currentTime - DeltaTime) < 105.3285)
	{
		spawnCrashNode();
	}
	if (currentTime >= 105.6338 && (currentTime - DeltaTime) < 105.6338)
	{
		spawnCrashNode();
	}
#pragma endregion 87
#pragma region 92
	if (currentTime >= 111.1292 && (currentTime - DeltaTime) < 111.1292)
	{
		spawnCrashNode();
	}
#pragma endregion 92
#pragma region 96
	if (currentTime >= 116.014 && (currentTime - DeltaTime) < 116.014)
	{
		spawnCrashNode();
	}
#pragma endregion 96
#pragma region 100
	if (currentTime >= 120.8988 && (currentTime - DeltaTime) < 120.8988)
	{
		spawnCrashNode();
	}
	if (currentTime >= 121.2041 && (currentTime - DeltaTime) < 121.2041)
	{
		spawnCrashNode();
	}
	if (currentTime >= 121.8147 && (currentTime - DeltaTime) < 121.8147)
	{
		spawnCrashNode();
	}
#pragma endregion 100
#pragma region 101
	if (currentTime >= 122.12 && (currentTime - DeltaTime) < 122.12)
	{
		spawnCrashNode();
	}
	if (currentTime >= 122.4253 && (currentTime - DeltaTime) < 122.4253)
	{
		spawnCrashNode();
	}
	if (currentTime >= 123.0359 && (currentTime - DeltaTime) < 123.0359)
	{
		spawnCrashNode();
	}
#pragma endregion 101
#pragma region 102
	if (currentTime >= 123.3412 && (currentTime - DeltaTime) < 123.3412)
	{
		spawnCrashNode();
	}
	if (currentTime >= 123.6465 && (currentTime - DeltaTime) < 123.6465)
	{
		spawnCrashNode();
	}
	if (currentTime >= 124.2571 && (currentTime - DeltaTime) < 124.2571)
	{
		spawnCrashNode();
	}
#pragma endregion 102
#pragma region 103
	if (currentTime >= 124.5624 && (currentTime - DeltaTime) < 124.5624)
	{
		spawnCrashNode();
	}
	if (currentTime >= 124.8677 && (currentTime - DeltaTime) < 124.8677)
	{
		spawnCrashNode();
	}
#pragma endregion 103
#pragma region 104
	if (currentTime >= 125.7836 && (currentTime - DeltaTime) < 125.7836)
	{
		spawnCrashNode();
	}
	if (currentTime >= 126.0889 && (currentTime - DeltaTime) < 126.0889)
	{
		spawnCrashNode();
	}
	if (currentTime >= 126.6995 && (currentTime - DeltaTime) < 126.6995)
	{
		spawnCrashNode();
	}
#pragma endregion 104
#pragma region 105
	if (currentTime >= 127.0048 && (currentTime - DeltaTime) < 127.0048)
	{
		spawnCrashNode();
	}
	if (currentTime >= 127.3101 && (currentTime - DeltaTime) < 127.3101)
	{
		spawnCrashNode();
	}
	if (currentTime >= 127.9207 && (currentTime - DeltaTime) < 127.9207)
	{
		spawnCrashNode();
	}
#pragma endregion 105
#pragma region 106
	if (currentTime >= 128.226 && (currentTime - DeltaTime) < 128.226)
	{
		spawnCrashNode();
	}
	if (currentTime >= 128.5313 && (currentTime - DeltaTime) < 128.5313)
	{
		spawnCrashNode();
	}
#pragma endregion 106
#pragma region 109
	if (currentTime >= 131.8896 && (currentTime - DeltaTime) < 131.8896)
	{
		spawnCrashNode();
	}
	if (currentTime >= 132.1949 && (currentTime - DeltaTime) < 132.1949)
	{
		spawnCrashNode();
	}
	if (currentTime >= 132.5002 && (currentTime - DeltaTime) < 132.5002)
	{
		spawnCrashNode();
	}
	if (currentTime >= 132.8055 && (currentTime - DeltaTime) < 132.8055)
	{
		spawnCrashNode();
	}
#pragma endregion 109
#pragma region 110
	if (currentTime >= 133.1108 && (currentTime - DeltaTime) < 133.1108)
	{
		spawnCrashNode();
	}
	if (currentTime >= 133.4161 && (currentTime - DeltaTime) < 133.4161)
	{
		spawnCrashNode();
	}
	if (currentTime >= 133.7214 && (currentTime - DeltaTime) < 133.7214)
	{
		spawnCrashNode();
	}
	if (currentTime >= 134.0267 && (currentTime - DeltaTime) < 134.0267)
	{
		spawnCrashNode();
	}
#pragma endregion 110
#pragma region 111
	if (currentTime >= 134.332 && (currentTime - DeltaTime) < 134.332)
	{
		spawnCrashNode();
	}
	if (currentTime >= 134.6373 && (currentTime - DeltaTime) < 134.6373)
	{
		spawnCrashNode();
	}
	if (currentTime >= 134.9426 && (currentTime - DeltaTime) < 134.9426)
	{
		spawnCrashNode();
	}
	if (currentTime >= 135.2479 && (currentTime - DeltaTime) < 135.2479)
	{
		spawnCrashNode();
	}
#pragma endregion 111
#pragma region 112
	if (currentTime >= 135.5532 && (currentTime - DeltaTime) < 135.5532)
	{
		spawnCrashNode();
	}
	if (currentTime >= 136.1638 && (currentTime - DeltaTime) < 136.1638)
	{
		spawnCrashNode();
	}
#pragma endregion 112
#pragma region 113
	if (currentTime >= 136.7744 && (currentTime - DeltaTime) < 136.7744)
	{
		spawnCrashNode();
	}
	if (currentTime >= 137.0797 && (currentTime - DeltaTime) < 137.0797)
	{
		spawnCrashNode();
	}
	if (currentTime >= 137.385 && (currentTime - DeltaTime) < 137.385)
	{
		spawnCrashNode();
	}
	if (currentTime >= 137.6903 && (currentTime - DeltaTime) < 137.6903)
	{
		spawnCrashNode();
	}
#pragma endregion 113
#pragma region 114
	if (currentTime >= 137.9956 && (currentTime - DeltaTime) < 137.9956)
	{
		spawnCrashNode();
	}
	if (currentTime >= 138.3009 && (currentTime - DeltaTime) < 138.3009)
	{
		spawnCrashNode();
	}
	if (currentTime >= 138.6062 && (currentTime - DeltaTime) < 138.6062)
	{
		spawnCrashNode();
	}
	if (currentTime >= 138.9115 && (currentTime - DeltaTime) < 138.9115)
	{
		spawnCrashNode();
	}
#pragma endregion 114
#pragma region 115
	if (currentTime >= 139.2168 && (currentTime - DeltaTime) < 139.2168)
	{
		spawnCrashNode();
	}
	if (currentTime >= 139.5221 && (currentTime - DeltaTime) < 139.5221)
	{
		spawnCrashNode();
	}
	if (currentTime >= 139.8274 && (currentTime - DeltaTime) < 139.8274)
	{
		spawnCrashNode();
	}
	if (currentTime >= 140.1327 && (currentTime - DeltaTime) < 140.1327)
	{
		spawnCrashNode();
	}
#pragma endregion 115
#pragma region 116
	if (currentTime >= 140.438 && (currentTime - DeltaTime) < 140.438)
	{
		spawnCrashNode();
	}
#pragma endregion 116
#pragma region 117
	if (currentTime >= 141.6592 && (currentTime - DeltaTime) < 141.6592)
	{
		spawnCrashNode();
	}
	if (currentTime >= 141.9645 && (currentTime - DeltaTime) < 141.9645)
	{
		spawnCrashNode();
	}
	if (currentTime >= 142.2698 && (currentTime - DeltaTime) < 142.2698)
	{
		spawnCrashNode();
	}
	if (currentTime >= 142.5751 && (currentTime - DeltaTime) < 142.5751)
	{
		spawnCrashNode();
	}
#pragma endregion 117
#pragma region 118
	if (currentTime >= 142.8804 && (currentTime - DeltaTime) < 142.8804)
	{
		spawnCrashNode();
	}
	if (currentTime >= 143.1857 && (currentTime - DeltaTime) < 143.1857)
	{
		spawnCrashNode();
	}
	if (currentTime >= 143.491 && (currentTime - DeltaTime) < 143.491)
	{
		spawnCrashNode();
	}
	if (currentTime >= 143.7963 && (currentTime - DeltaTime) < 143.7963)
	{
		spawnCrashNode();
	}
#pragma endregion 118
#pragma region 119
	if (currentTime >= 144.1016 && (currentTime - DeltaTime) < 144.1016)
	{
		spawnCrashNode();
	}
	if (currentTime >= 144.4069 && (currentTime - DeltaTime) < 144.4069)
	{
		spawnCrashNode();
	}
	if (currentTime >= 144.7122 && (currentTime - DeltaTime) < 144.7122)
	{
		spawnCrashNode();
	}
	if (currentTime >= 145.0175 && (currentTime - DeltaTime) < 145.0175)
	{
		spawnCrashNode();
	}
#pragma endregion 119
#pragma region 120
	if (currentTime >= 145.3228 && (currentTime - DeltaTime) < 145.3228)
	{
		spawnCrashNode();
	}
	if (currentTime >= 145.9334 && (currentTime - DeltaTime) < 145.9334)
	{
		spawnCrashNode();
	}
#pragma endregion 120
#pragma region 120
	if (currentTime >= 146.544 && (currentTime - DeltaTime) < 146.544)
	{
		spawnCrashNode();
	}
	if (currentTime >= 146.8493 && (currentTime - DeltaTime) < 146.8493)
	{
		spawnCrashNode();
	}
	if (currentTime >= 147.1546 && (currentTime - DeltaTime) < 147.1546)
	{
		spawnCrashNode();
	}
	if (currentTime >= 147.4599 && (currentTime - DeltaTime) < 147.4599)
	{
		spawnCrashNode();
	}
#pragma endregion 121
#pragma region 122
	if (currentTime >= 147.7652 && (currentTime - DeltaTime) < 147.7652)
	{
		spawnCrashNode();
	}
	if (currentTime >= 148.0705 && (currentTime - DeltaTime) < 148.0705)
	{
		spawnCrashNode();
	}
	if (currentTime >= 148.3758 && (currentTime - DeltaTime) < 148.3758)
	{
		spawnCrashNode();
	}
	if (currentTime >= 148.6811 && (currentTime - DeltaTime) < 148.6811)
	{
		spawnCrashNode();
	}
#pragma endregion 122
#pragma region 123
	if (currentTime >= 148.9864 && (currentTime - DeltaTime) < 148.9864)
	{
		spawnCrashNode();
	}
	if (currentTime >= 149.2917 && (currentTime - DeltaTime) < 149.2917)
	{
		spawnCrashNode();
	}
	if (currentTime >= 149.597 && (currentTime - DeltaTime) < 149.597)
	{
		spawnCrashNode();
	}
	if (currentTime >= 149.9023 && (currentTime - DeltaTime) < 149.9023)
	{
		spawnCrashNode();
	}
#pragma endregion 123
#pragma region 124
	if (currentTime >= 150.2076 && (currentTime - DeltaTime) < 150.2076)
	{
		spawnCrashNode();
	}
	if (currentTime >= 150.5129 && (currentTime - DeltaTime) < 150.5129)
	{
		spawnCrashNode();
	}
	if (currentTime >= 150.8182 && (currentTime - DeltaTime) < 150.8182)
	{
		spawnCrashNode();
	}
	if (currentTime >= 151.1235 && (currentTime - DeltaTime) < 151.1235)
	{
		spawnCrashNode();
	}
#pragma endregion 124
#pragma region 125
	if (currentTime >= 151.4288 && (currentTime - DeltaTime) < 151.4288)
	{
		spawnCrashNode();
	}
#pragma endregion 125
#pragma region 126
	if (currentTime >= 152.65 && (currentTime - DeltaTime) < 152.65)
	{
		spawnCrashNode();
	}
#pragma endregion 126

*/

}

void AOSY_CrashFactory::spawnCrashNode()
{	
	// ������ġ
	FVector FactoryLoc = GetActorLocation();

	GetWorld()->SpawnActor<AOSY_CrashNodeActor>(NodeFactory, FactoryLoc, FRotator::ZeroRotator);


}

