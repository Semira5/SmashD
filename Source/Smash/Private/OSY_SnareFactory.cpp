// Fill out your copyright notice in the Description page of Project Settings.


#include "OSY_SnareFactory.h"
#include "OSY_NodeActor.h"
#include "OSY_SnareNodeActor.h"

// Sets default values
AOSY_SnareFactory::AOSY_SnareFactory()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AOSY_SnareFactory::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOSY_SnareFactory::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	currentTime += DeltaTime;
	UE_LOG(LogTemp, Warning, TEXT("currentTime : %f"), currentTime);

	TArray<float> spawnTimes =
	{ 15.3125f,15.9375f,16.09375f,16.171875f,16.5625f,17.1875f,17.8125f,18.4375f,19.0625f,19.6875f,20.f,20.078125f,20.15625f,20.3125f,20.46875f,20.625f,20.703125f,20.78125f,20.9375f,21.09375f,21.71875f,22.1875f,22.8125f,23.4375f,24.0625f,24.6875f,25.3125f,25.9375f,26.5625f,27.1875f,27.8125f,28.4375f,29.0625f,29.6875f,30.3125f,30.9375f,31.015625f,31.09375f,31.171875f,31.5625f,32.1875f,32.8125f,33.4375f,34.0625f,34.6875f,35.3125f,35.9375f,36.5625f,37.1875f,37.8125f,38.4375f,39.0625f,39.6875f,40.f,40.078125f,40.15625f,40.234375f,40.3125f,40.390625f,40.46875f,40.546875f,40.625f,40.703125f,40.78125f,40.859375f,40.9375f,41.015625f,41.09375f,41.171875f,41.25f,41.328125f,41.40625f,41.484375f,41.5625f,41.640625f,41.71875f,41.796875f,41.875f,41.953125f,42.03125f,42.109375f,42.1875f,42.265625f,42.34375f,42.421875f,42.8125f,43.4375f,44.0625f,44.6875f,45.3125f,45.9375f,46.5625f,47.03125f,47.8125f,48.4375f,49.0625f,49.6875f,50.3125f,50.9375f,51.5625f,51.875f,51.953125f,52.03125f,52.109375f,52.1875f,52.34375f,52.8125f,53.4375f,54.0625f,54.6875f,55.3125f,55.9375f,56.5625f,57.03125f,57.8125f,58.4375f,59.0625f,59.6875f,60.3125f,60.9375f,61.5625f,62.1875f,62.8125f,63.4375f,64.0625f,64.6875f,65.3125f,65.9375f,66.5625f,67.03125f,67.109375f,67.34375f,67.421875f,67.8125f,68.4375f,69.0625f,69.6875f,70.3125f,70.9375f,71.5625f,72.1875f,72.8125f,73.4375f,74.0625f,74.6875f,75.3125f,75.9375f,76.25f,76.328125f,76.40625f,76.484375f,76.5625f,76.640625f,76.71875f,76.796875f,76.875f,76.953125f,77.03125f,77.109375f,77.1875f,77.265625f,77.34375f,77.421875f,77.5f,77.578125f,77.65625f,77.734375f,77.8125f,77.890625f,77.96875f,78.046875f,78.125f,78.203125f,78.28125f,78.359375f,78.4375f,78.515625f,78.59375f,78.671875f,79.0625f,79.6875f,80.3125f,80.9375f,81.5625f,82.1875f,82.8125f,83.4375f,84.0625f,84.6875f,85.3125f,85.9375f,86.5625f,87.1875f,87.8125f,88.125f,88.28125f,88.4375f,88.59375f,88.90625f,89.375f,89.84375f,90.15625f,90.625f,91.25f,91.875f,92.65625f,92.734375f,92.8125f,92.890625f,92.96875f,93.046875f,93.28125f,93.359375f,93.4375f,93.515625f,93.59375f,93.671875f,93.90625f,94.375f,94.84375f,95.15625f,95.625f,96.25f,96.875f,97.5f,97.65625f,97.8125f,98.125f,98.203125f,98.4375f,98.59375f,98.75f,99.375f,100.f,100.625f,100.9375f,101.015625f,101.25f,101.875f,102.5f,103.125f,103.4375f,103.515625f,103.59375f,103.75f,104.375f,105.f,105.625f,105.9375f,106.015625f,106.25f,106.875f,107.5f,108.125f,108.4375f,108.515625f,108.75f,108.90625f,109.0625f,110.f,110.15625f,110.3125f,111.25f,111.40625f,111.5625f,112.5f,112.65625f,112.8125f,113.125f,113.203125f,114.375f,115.625f,116.875f,118.125f,118.59375f,119.375f,120.625f,121.875f,123.125f,123.203125f,123.4375f,123.515625f,124.375f,125.625f,126.875f,128.125f,128.203125f,128.28125f,128.4375f,129.375f,130.625f,131.875f,132.65625f,132.734375f,132.8125f,132.890625f,132.96875f,133.046875f,133.125f,133.203125f,133.28125f,133.359375f,133.4375f,133.515625f,133.59375f,133.671875f,133.75f,133.828125f,133.90625f,133.984375f,134.0625f,134.140625f,134.21875f,134.296875f,134.375f,134.453125f,134.53125f,134.609375f,134.6875f,134.765625f,134.84375f,134.921875f,135.3125f,135.9375f,136.5625f,137.1875f,137.8125f,138.4375f,139.0625f,139.6875f,140.3125f,140.9375f,141.5625f,142.1875f,142.8125f,143.4375f,143.90625f,144.0625f,144.140625f,144.21875f,144.296875f,144.375f,144.453125f,144.53125f,144.609375f,145.3125f,145.9375f,146.5625f,147.1875f,147.8125f,148.4375f,149.0625f,149.6875f,150.3125f,150.9375f,151.5625f,152.1875f,152.8125f,153.4375f,154.0625f,154.6875f,155.f,155.3125f,155.625f,155.703125f,155.78125f,155.9375f,156.015625f,
	};

	for (float spawnTime : spawnTimes)
	{
		if (currentTime >= spawnTime && currentTime - DeltaTime < spawnTime)
		{
			spawnSnareNode();
		}
	}
	/*
#pragma region 9
	if (currentTime >= 10.3802 && (currentTime - DeltaTime) < 10.3802)
	{
		spawnSnareNode();
	}
#pragma endregion 9
#pragma region 10
	if (currentTime >= 11.2961 && (currentTime - DeltaTime) < 11.2961)
	{
		spawnSnareNode();
	}
	if (currentTime >= 11.9067 && (currentTime - DeltaTime) < 11.9067)
	{
		spawnSnareNode();
	}
#pragma endregion 10
#pragma region 11
	if (currentTime >= 12.5173 && (currentTime - DeltaTime) < 12.5173)
	{
		spawnSnareNode();
	}
	if (currentTime >= 13.1279 && (currentTime - DeltaTime) < 13.1279)
	{
		spawnSnareNode();
	}
#pragma endregion 11
#pragma region 12
	if (currentTime >= 13.7385 && (currentTime - DeltaTime) < 13.7385)
	{
		spawnSnareNode();
	}
	if (currentTime >= 14.3491 && (currentTime - DeltaTime) < 14.3491)
	{
		spawnSnareNode();
	}
#pragma endregion 12
#pragma region 13
	if (currentTime >= 14.9597 && (currentTime - DeltaTime) < 14.9597)
	{
		spawnSnareNode();
	}
	if (currentTime >= 15.5703 && (currentTime - DeltaTime) < 15.5703)
	{
		spawnSnareNode();
	}
	if (currentTime >= 15.72295 && (currentTime - DeltaTime) < 15.72295)
	{
		spawnSnareNode();
	}
	if (currentTime >= 15.799275 && (currentTime - DeltaTime) < 15.799275)
	{
		spawnSnareNode();
	}
#pragma endregion 13
#pragma region 14
	if (currentTime >= 16.1809 && (currentTime - DeltaTime) < 16.1809)
	{
		spawnSnareNode();
	}
	if (currentTime >= 16.7915 && (currentTime - DeltaTime) < 16.7915)
	{
		spawnSnareNode();
	}
#pragma endregion 14
#pragma region 15
	if (currentTime >= 17.4021 && (currentTime - DeltaTime) < 17.4021)
	{
		spawnSnareNode();
	}
	if (currentTime >= 18.0127 && (currentTime - DeltaTime) < 18.0127)
	{
		spawnSnareNode();
	}
#pragma endregion 15
#pragma region 16
	if (currentTime >= 18.6233 && (currentTime - DeltaTime) < 18.6233)
	{
		spawnSnareNode();
	}
	if (currentTime >= 19.2339 && (currentTime - DeltaTime) < 19.2339)
	{
		spawnSnareNode();
	}
#pragma endregion 16
#pragma region 17
	if (currentTime >= 19.5392 && (currentTime - DeltaTime) < 19.5392)
	{
		spawnSnareNode();
	}
	if (currentTime >= 19.615525 && (currentTime - DeltaTime) < 19.615525)
	{
		spawnSnareNode();
	}
	if (currentTime >= 19.69185 && (currentTime - DeltaTime) < 19.69185)
	{
		spawnSnareNode();
	}
	if (currentTime >= 19.8445 && (currentTime - DeltaTime) < 19.8445)
	{
		spawnSnareNode();
	}
	if (currentTime >= 19.99715 && (currentTime - DeltaTime) < 19.99715)
	{
		spawnSnareNode();
	}
	if (currentTime >= 20.1498 && (currentTime - DeltaTime) < 20.1498)
	{
		spawnSnareNode();
	}
	if (currentTime >= 20.226125 && (currentTime - DeltaTime) < 20.226125)
	{
		spawnSnareNode();
	}
	if (currentTime >= 20.30245 && (currentTime - DeltaTime) < 20.30245)
	{
		spawnSnareNode();
	}
	if (currentTime >= 20.4551 && (currentTime - DeltaTime) < 20.4551)
	{
		spawnSnareNode();
	}
	if (currentTime >= 20.60775 && (currentTime - DeltaTime) < 20.60775)
	{
		spawnSnareNode();
	}
#pragma endregion 17
#pragma region 18
	if (currentTime >= 21.21835 && (currentTime - DeltaTime) < 21.21835)
	{
		spawnSnareNode();
	}
	if (currentTime >= 21.6763 && (currentTime - DeltaTime) < 21.6763)
	{
		spawnSnareNode();
	}
#pragma endregion 18
#pragma region 19
	if (currentTime >= 22.2869 && (currentTime - DeltaTime) < 22.2869)
	{
		spawnSnareNode();
	}
	if (currentTime >= 22.8975 && (currentTime - DeltaTime) < 22.8975)
	{
		spawnSnareNode();
	}
#pragma endregion 19
#pragma region 20
	if (currentTime >= 23.5081 && (currentTime - DeltaTime) < 23.5081)
	{
		spawnSnareNode();
	}
	if (currentTime >= 24.1187 && (currentTime - DeltaTime) < 24.1187)
	{
		spawnSnareNode();
	}
#pragma endregion 20
#pragma region 21
	if (currentTime >= 24.7293 && (currentTime - DeltaTime) < 24.7293)
	{
		spawnSnareNode();
	}
	if (currentTime >= 25.3399 && (currentTime - DeltaTime) < 25.3399)
	{
		spawnSnareNode();
	}
#pragma endregion 21
#pragma region 22
	if (currentTime >= 25.9505 && (currentTime - DeltaTime) < 25.9505)
	{
		spawnSnareNode();
	}
	if (currentTime >= 26.5611 && (currentTime - DeltaTime) < 26.5611)
	{
		spawnSnareNode();
	}
#pragma endregion 22
#pragma region 23
	if (currentTime >= 27.1717 && (currentTime - DeltaTime) < 27.1717)
	{
		spawnSnareNode();
	}
	if (currentTime >= 27.7823 && (currentTime - DeltaTime) < 27.7823)
	{
		spawnSnareNode();
	}
#pragma endregion 23
#pragma region 24
	if (currentTime >= 28.3929 && (currentTime - DeltaTime) < 28.3929)
	{
		spawnSnareNode();
	}
	if (currentTime >= 29.0035 && (currentTime - DeltaTime) < 29.0035)
	{
		spawnSnareNode();
	}
#pragma endregion 24
#pragma region 25
	if (currentTime >= 29.6141 && (currentTime - DeltaTime) < 29.6141)
	{
		spawnSnareNode();
	}
	if (currentTime >= 30.2247 && (currentTime - DeltaTime) < 30.2247)
	{
		spawnSnareNode();
	}
	if (currentTime >= 30.301025 && (currentTime - DeltaTime) < 30.301025)
	{
		spawnSnareNode();
	}
	if (currentTime >= 30.37735 && (currentTime - DeltaTime) < 30.37735)
	{
		spawnSnareNode();
	}
	if (currentTime >= 30.453675 && (currentTime - DeltaTime) < 30.453675)
	{
		spawnSnareNode();
	}
#pragma endregion 25
#pragma region 26
	if (currentTime >= 30.8353 && (currentTime - DeltaTime) < 30.8353)
	{
		spawnSnareNode();
	}
	if (currentTime >= 31.4459 && (currentTime - DeltaTime) < 31.4459)
	{
		spawnSnareNode();
	}
#pragma endregion 26
#pragma region 27
	if (currentTime >= 32.0565 && (currentTime - DeltaTime) < 32.0565)
	{
		spawnSnareNode();
	}
	if (currentTime >= 32.6671 && (currentTime - DeltaTime) < 32.6671)
	{
		spawnSnareNode();
	}
#pragma endregion 27
#pragma region 28
	if (currentTime >= 33.2777 && (currentTime - DeltaTime) < 33.2777)
	{
		spawnSnareNode();
	}
	if (currentTime >= 33.8883 && (currentTime - DeltaTime) < 33.8883)
	{
		spawnSnareNode();
	}
#pragma endregion 28
#pragma region 29
	if (currentTime >= 34.4989 && (currentTime - DeltaTime) < 34.4989)
	{
		spawnSnareNode();
	}
	if (currentTime >= 35.1095 && (currentTime - DeltaTime) < 35.1095)
	{
		spawnSnareNode();
	}
#pragma endregion 29
#pragma region 30
	if (currentTime >= 35.7201 && (currentTime - DeltaTime) < 35.7201)
	{
		spawnSnareNode();
	}
	if (currentTime >= 36.3307 && (currentTime - DeltaTime) < 36.3307)
	{
		spawnSnareNode();
	}
#pragma endregion 30
#pragma region 31
	if (currentTime >= 36.9413 && (currentTime - DeltaTime) < 36.9413)
	{
		spawnSnareNode();
	}
	if (currentTime >= 37.5519 && (currentTime - DeltaTime) < 37.5519)
	{
		spawnSnareNode();
	}
#pragma endregion 31
#pragma region 32
	if (currentTime >= 38.1625 && (currentTime - DeltaTime) < 38.1625)
	{
		spawnSnareNode();
	}
	if (currentTime >= 38.7731 && (currentTime - DeltaTime) < 38.7731)
	{
		spawnSnareNode();
	}
#pragma endregion 32
#pragma region 33
	if (currentTime >= 39.0784 && (currentTime - DeltaTime) < 39.0784)
	{
		spawnSnareNode();
	}
	if (currentTime >= 39.154725 && (currentTime - DeltaTime) < 39.154725)
	{
		spawnSnareNode();
	}
	if (currentTime >= 39.23105 && (currentTime - DeltaTime) < 39.23105)
	{
		spawnSnareNode();
	}
	if (currentTime >= 39.307375 && (currentTime - DeltaTime) < 39.307375)
	{
		spawnSnareNode();
	}
	if (currentTime >= 39.3837 && (currentTime - DeltaTime) < 39.3837)
	{
		spawnSnareNode();
	}
	if (currentTime >= 39.460025 && (currentTime - DeltaTime) < 39.460025)
	{
		spawnSnareNode();
	}
	if (currentTime >= 39.53635 && (currentTime - DeltaTime) < 39.53635)
	{
		spawnSnareNode();
	}
	if (currentTime >= 39.612675 && (currentTime - DeltaTime) < 39.612675)
	{
		spawnSnareNode();
	}
	if (currentTime >= 39.689 && (currentTime - DeltaTime) < 39.689)
	{
		spawnSnareNode();
	}
	if (currentTime >= 39.765325 && (currentTime - DeltaTime) < 39.765325)
	{
		spawnSnareNode();
	}
	if (currentTime >= 39.84165 && (currentTime - DeltaTime) < 39.84165)
	{
		spawnSnareNode();
	}
	if (currentTime >= 39.917975 && (currentTime - DeltaTime) < 39.917975)
	{
		spawnSnareNode();
	}
	if (currentTime >= 39.9943 && (currentTime - DeltaTime) < 39.9943)
	{
		spawnSnareNode();
	}
	if (currentTime >= 40.070625 && (currentTime - DeltaTime) < 40.070625)
	{
		spawnSnareNode();
	}
	if (currentTime >= 40.14695 && (currentTime - DeltaTime) < 40.14695)
	{
		spawnSnareNode();
	}
	if (currentTime >= 40.223275 && (currentTime - DeltaTime) < 40.223275)
	{
		spawnSnareNode();
	}
#pragma endregion 33
#pragma region 34
	if (currentTime >= 40.2996 && (currentTime - DeltaTime) < 40.2996)
	{
		spawnSnareNode();
	}
	if (currentTime >= 40.375925 && (currentTime - DeltaTime) < 40.375925)
	{
		spawnSnareNode();
	}
	if (currentTime >= 40.45225 && (currentTime - DeltaTime) < 40.45225)
	{
		spawnSnareNode();
	}
	if (currentTime >= 40.528575 && (currentTime - DeltaTime) < 40.528575)
	{
		spawnSnareNode();
	}
	if (currentTime >= 40.6049 && (currentTime - DeltaTime) < 40.6049)
	{
		spawnSnareNode();
	}
	if (currentTime >= 40.681225 && (currentTime - DeltaTime) < 40.681225)
	{
		spawnSnareNode();
	}
	if (currentTime >= 40.75755 && (currentTime - DeltaTime) < 40.75755)
	{
		spawnSnareNode();
	}
	if (currentTime >= 40.833875 && (currentTime - DeltaTime) < 40.833875)
	{
		spawnSnareNode();
	}
	if (currentTime >= 40.9102 && (currentTime - DeltaTime) < 40.9102)
	{
		spawnSnareNode();
	}
	if (currentTime >= 40.986525 && (currentTime - DeltaTime) < 40.986525)
	{
		spawnSnareNode();
	}
	if (currentTime >= 41.06285 && (currentTime - DeltaTime) < 41.06285)
	{
		spawnSnareNode();
	}
	if (currentTime >= 41.139175 && (currentTime - DeltaTime) < 41.139175)
	{
		spawnSnareNode();
	}
	if (currentTime >= 41.2155 && (currentTime - DeltaTime) < 41.2155)
	{
		spawnSnareNode();
	}
	if (currentTime >= 41.291825 && (currentTime - DeltaTime) < 41.291825)
	{
		spawnSnareNode();
	}
	if (currentTime >= 41.36815 && (currentTime - DeltaTime) < 41.36815)
	{
		spawnSnareNode();
	}
	if (currentTime >= 41.444475 && (currentTime - DeltaTime) < 41.444475)
	{
		spawnSnareNode();
	}
#pragma endregion 34
#pragma region 35
	if (currentTime >= 41.8261 && (currentTime - DeltaTime) < 41.8261)
	{
		spawnSnareNode();
	}
	if (currentTime >= 42.4367 && (currentTime - DeltaTime) < 42.4367)
	{
		spawnSnareNode();
	}
#pragma endregion 35
#pragma region 36
	if (currentTime >= 43.0473 && (currentTime - DeltaTime) < 43.0473)
	{
		spawnSnareNode();
	}
	if (currentTime >= 43.6579 && (currentTime - DeltaTime) < 43.6579)
	{
		spawnSnareNode();
	}
#pragma endregion 36
#pragma region 37
	if (currentTime >= 44.2685 && (currentTime - DeltaTime) < 44.2685)
	{
		spawnSnareNode();
	}
	if (currentTime >= 44.8791 && (currentTime - DeltaTime) < 44.8791)
	{
		spawnSnareNode();
	}
#pragma endregion 37
#pragma region 38
	if (currentTime >= 45.4897 && (currentTime - DeltaTime) < 45.4897)
	{
		spawnSnareNode();
	}
	if (currentTime >= 45.94765 && (currentTime - DeltaTime) < 45.94765)
	{
		spawnSnareNode();
	}
#pragma endregion 38
#pragma region 39
	if (currentTime >= 46.7109 && (currentTime - DeltaTime) < 46.7109)
	{
		spawnSnareNode();
	}
	if (currentTime >= 47.3215 && (currentTime - DeltaTime) < 47.3215)
	{
		spawnSnareNode();
	}
#pragma endregion 39
#pragma region 40
	if (currentTime >= 47.9321 && (currentTime - DeltaTime) < 47.9321)
	{
		spawnSnareNode();
	}
	if (currentTime >= 48.5427 && (currentTime - DeltaTime) < 48.5427)
	{
		spawnSnareNode();
	}
#pragma endregion 40
#pragma region 41
	if (currentTime >= 49.1533 && (currentTime - DeltaTime) < 49.1533)
	{
		spawnSnareNode();
	}
	if (currentTime >= 49.7639 && (currentTime - DeltaTime) < 49.7639)
	{
		spawnSnareNode();
	}
#pragma endregion 41
#pragma region 42
	if (currentTime >= 50.3745 && (currentTime - DeltaTime) < 50.3745)
	{
		spawnSnareNode();
	}
	if (currentTime >= 50.6798 && (currentTime - DeltaTime) < 50.6798)
	{
		spawnSnareNode();
	}
	if (currentTime >= 50.756125 && (currentTime - DeltaTime) < 50.756125)
	{
		spawnSnareNode();
	}
	if (currentTime >= 50.83245 && (currentTime - DeltaTime) < 50.83245)
	{
		spawnSnareNode();
	}
	if (currentTime >= 50.908775 && (currentTime - DeltaTime) < 50.908775)
	{
		spawnSnareNode();
	}
	if (currentTime >= 50.9851 && (currentTime - DeltaTime) < 50.9851)
	{
		spawnSnareNode();
	}
	if (currentTime >= 51.13775 && (currentTime - DeltaTime) < 51.13775)
	{
		spawnSnareNode();
	}
#pragma endregion 42
#pragma region 43
	if (currentTime >= 51.5957 && (currentTime - DeltaTime) < 51.5957)
	{
		spawnSnareNode();
	}
	if (currentTime >= 52.2063 && (currentTime - DeltaTime) < 52.2063)
	{
		spawnSnareNode();
	}
#pragma endregion 43
#pragma region 44
	if (currentTime >= 52.8169 && (currentTime - DeltaTime) < 52.8169)
	{
		spawnSnareNode();
	}
	if (currentTime >= 53.4275 && (currentTime - DeltaTime) < 53.4275)
	{
		spawnSnareNode();
	}
#pragma endregion 44
#pragma region 45
	if (currentTime >= 54.0381 && (currentTime - DeltaTime) < 54.0381)
	{
		spawnSnareNode();
	}
	if (currentTime >= 54.6487 && (currentTime - DeltaTime) < 54.6487)
	{
		spawnSnareNode();
	}
#pragma endregion 45
#pragma region 46
	if (currentTime >= 55.2593 && (currentTime - DeltaTime) < 55.2593)
	{
		spawnSnareNode();
	}
	if (currentTime >= 55.71725 && (currentTime - DeltaTime) < 55.71725)
	{
		spawnSnareNode();
	}
#pragma endregion 46
#pragma region 47
	if (currentTime >= 56.4805 && (currentTime - DeltaTime) < 56.4805)
	{
		spawnSnareNode();
	}
	if (currentTime >= 57.0911 && (currentTime - DeltaTime) < 57.0911)
	{
		spawnSnareNode();
	}
#pragma endregion 47
#pragma region 48
	if (currentTime >= 57.7017 && (currentTime - DeltaTime) < 57.7017)
	{
		spawnSnareNode();
	}
	if (currentTime >= 58.3123 && (currentTime - DeltaTime) < 58.3123)
	{
		spawnSnareNode();
	}
#pragma endregion 48
#pragma region 49
	if (currentTime >= 58.9229 && (currentTime - DeltaTime) < 58.9229)
	{
		spawnSnareNode();
	}
	if (currentTime >= 59.5335 && (currentTime - DeltaTime) < 59.5335)
	{
		spawnSnareNode();
	}
#pragma endregion 49
#pragma region 50
	if (currentTime >= 60.1441 && (currentTime - DeltaTime) < 60.1441)
	{
		spawnSnareNode();
	}
	if (currentTime >= 60.7547 && (currentTime - DeltaTime) < 60.7547)
	{
		spawnSnareNode();
	}
#pragma endregion 50
#pragma region 51
	if (currentTime >= 61.3653 && (currentTime - DeltaTime) < 61.3653)
	{
		spawnSnareNode();
	}
	if (currentTime >= 61.9759 && (currentTime - DeltaTime) < 61.9759)
	{
		spawnSnareNode();
	}
#pragma endregion 51
#pragma region 52
	if (currentTime >= 62.5865 && (currentTime - DeltaTime) < 62.5865)
	{
		spawnSnareNode();
	}
	if (currentTime >= 63.1971 && (currentTime - DeltaTime) < 63.1971)
	{
		spawnSnareNode();
	}
#pragma endregion 52
#pragma region 53
	if (currentTime >= 63.8077 && (currentTime - DeltaTime) < 63.8077)
	{
		spawnSnareNode();
	}
	if (currentTime >= 64.4183 && (currentTime - DeltaTime) < 64.4183)
	{
		spawnSnareNode();
	}
#pragma endregion 53
#pragma region 54
	if (currentTime >= 65.0289 && (currentTime - DeltaTime) < 65.0289)
	{
		spawnSnareNode();
	}
	if (currentTime >= 65.48685 && (currentTime - DeltaTime) < 65.48685)
	{
		spawnSnareNode();
	}
	if (currentTime >= 65.563175 && (currentTime - DeltaTime) < 65.563175)
	{
		spawnSnareNode();
	}
	if (currentTime >= 65.79215 && (currentTime - DeltaTime) < 65.79215)
	{
		spawnSnareNode();
	}
	if (currentTime >= 65.868475 && (currentTime - DeltaTime) < 65.868475)
	{
		spawnSnareNode();
	}
#pragma endregion 54
#pragma region 55
	if (currentTime >= 66.2501 && (currentTime - DeltaTime) < 66.2501)
	{
		spawnSnareNode();
	}
	if (currentTime >= 66.8607 && (currentTime - DeltaTime) < 66.8607)
	{
		spawnSnareNode();
	}
#pragma endregion 55
#pragma region 56
	if (currentTime >= 67.4713 && (currentTime - DeltaTime) < 67.4713)
	{
		spawnSnareNode();
	}
	if (currentTime >= 68.0819 && (currentTime - DeltaTime) < 68.0819)
	{
		spawnSnareNode();
	}
#pragma endregion 56
#pragma region 57
	if (currentTime >= 68.6925 && (currentTime - DeltaTime) < 68.6925)
	{
		spawnSnareNode();
	}
	if (currentTime >= 69.3031 && (currentTime - DeltaTime) < 69.3031)
	{
		spawnSnareNode();
	}
#pragma endregion 57
#pragma region 58
	if (currentTime >= 69.9137 && (currentTime - DeltaTime) < 69.9137)
	{
		spawnSnareNode();
	}
	if (currentTime >= 70.5243 && (currentTime - DeltaTime) < 70.5243)
	{
		spawnSnareNode();
	}
#pragma endregion 58
#pragma region 59
	if (currentTime >= 71.1349 && (currentTime - DeltaTime) < 71.1349)
	{
		spawnSnareNode();
	}
	if (currentTime >= 71.7455 && (currentTime - DeltaTime) < 71.7455)
	{
		spawnSnareNode();
	}
#pragma endregion 59
#pragma region 60
	if (currentTime >= 72.3561 && (currentTime - DeltaTime) < 72.3561)
	{
		spawnSnareNode();
	}
	if (currentTime >= 72.9667 && (currentTime - DeltaTime) < 72.9667)
	{
		spawnSnareNode();
	}
#pragma endregion 60
#pragma region 61
	if (currentTime >= 73.5773 && (currentTime - DeltaTime) < 73.5773)
	{
		spawnSnareNode();
	}
	if (currentTime >= 74.1879 && (currentTime - DeltaTime) < 74.1879)
	{
		spawnSnareNode();
	}
#pragma endregion 61
#pragma region 62
	if (currentTime >= 74.4932 && (currentTime - DeltaTime) < 74.4932)
	{
		spawnSnareNode();
	}
	if (currentTime >= 74.569525 && (currentTime - DeltaTime) < 74.569525)
	{
		spawnSnareNode();
	}
	if (currentTime >= 74.64585 && (currentTime - DeltaTime) < 74.64585)
	{
		spawnSnareNode();
	}
	if (currentTime >= 74.722175 && (currentTime - DeltaTime) < 74.722175)
	{
		spawnSnareNode();
	}
	if (currentTime >= 74.7985 && (currentTime - DeltaTime) < 74.7985)
	{
		spawnSnareNode();
	}
	if (currentTime >= 74.874825 && (currentTime - DeltaTime) < 74.874825)
	{
		spawnSnareNode();
	}
	if (currentTime >= 74.95115 && (currentTime - DeltaTime) < 74.95115)
	{
		spawnSnareNode();
	}
	if (currentTime >= 75.027475 && (currentTime - DeltaTime) < 75.027475)
	{
		spawnSnareNode();
	}
	if (currentTime >= 75.1038 && (currentTime - DeltaTime) < 75.1038)
	{
		spawnSnareNode();
	}
	if (currentTime >= 75.180125 && (currentTime - DeltaTime) < 75.180125)
	{
		spawnSnareNode();
	}
	if (currentTime >= 75.25645 && (currentTime - DeltaTime) < 75.25645)
	{
		spawnSnareNode();
	}
	if (currentTime >= 75.332775 && (currentTime - DeltaTime) < 75.332775)
	{
		spawnSnareNode();
	}
	if (currentTime >= 75.4091 && (currentTime - DeltaTime) < 75.4091)
	{
		spawnSnareNode();
	}
	if (currentTime >= 75.485425 && (currentTime - DeltaTime) < 75.485425)
	{
		spawnSnareNode();
	}
	if (currentTime >= 75.56175 && (currentTime - DeltaTime) < 75.56175)
	{
		spawnSnareNode();
	}
	if (currentTime >= 75.638075 && (currentTime - DeltaTime) < 75.638075)
	{
		spawnSnareNode();
	}
#pragma endregion 62
#pragma region 63
	if (currentTime >= 75.7144 && (currentTime - DeltaTime) < 75.7144)
	{
		spawnSnareNode();
	}
	if (currentTime >= 75.790725 && (currentTime - DeltaTime) < 75.790725)
	{
		spawnSnareNode();
	}
	if (currentTime >= 75.86705 && (currentTime - DeltaTime) < 75.86705)
	{
		spawnSnareNode();
	}
	if (currentTime >= 75.943375 && (currentTime - DeltaTime) < 75.943375)
	{
		spawnSnareNode();
	}
	if (currentTime >= 76.0197 && (currentTime - DeltaTime) < 76.0197)
	{
		spawnSnareNode();
	}
	if (currentTime >= 76.096025 && (currentTime - DeltaTime) < 76.096025)
	{
		spawnSnareNode();
	}
	if (currentTime >= 76.17235 && (currentTime - DeltaTime) < 76.17235)
	{
		spawnSnareNode();
	}
	if (currentTime >= 76.248675 && (currentTime - DeltaTime) < 76.248675)
	{
		spawnSnareNode();
	}
	if (currentTime >= 76.325 && (currentTime - DeltaTime) < 76.325)
	{
		spawnSnareNode();
	}
	if (currentTime >= 76.401325 && (currentTime - DeltaTime) < 76.401325)
	{
		spawnSnareNode();
	}
	if (currentTime >= 76.47765 && (currentTime - DeltaTime) < 76.47765)
	{
		spawnSnareNode();
	}
	if (currentTime >= 76.553975 && (currentTime - DeltaTime) < 76.553975)
	{
		spawnSnareNode();
	}
	if (currentTime >= 76.6303 && (currentTime - DeltaTime) < 76.6303)
	{
		spawnSnareNode();
	}
	if (currentTime >= 76.706625 && (currentTime - DeltaTime) < 76.706625)
	{
		spawnSnareNode();
	}
	if (currentTime >= 76.78295 && (currentTime - DeltaTime) < 76.78295)
	{
		spawnSnareNode();
	}
	if (currentTime >= 76.859275 && (currentTime - DeltaTime) < 76.859275)
	{
		spawnSnareNode();
	}
#pragma endregion 63
#pragma region 64
	if (currentTime >= 77.2409 && (currentTime - DeltaTime) < 77.2409)
	{
		spawnSnareNode();
	}
	if (currentTime >= 77.8515 && (currentTime - DeltaTime) < 77.8515)
	{
		spawnSnareNode();
	}
#pragma endregion 64
#pragma region 65
	if (currentTime >= 78.4621 && (currentTime - DeltaTime) < 78.4621)
	{
		spawnSnareNode();
	}
	if (currentTime >= 79.0727 && (currentTime - DeltaTime) < 79.0727)
	{
		spawnSnareNode();
	}
#pragma endregion 65
#pragma region 66
	if (currentTime >= 79.6833 && (currentTime - DeltaTime) < 79.6833)
	{
		spawnSnareNode();
	}
	if (currentTime >= 80.2939 && (currentTime - DeltaTime) < 80.2939)
	{
		spawnSnareNode();
	}
#pragma endregion 66
#pragma region 67
	if (currentTime >= 80.9045 && (currentTime - DeltaTime) < 80.9045)
	{
		spawnSnareNode();
	}
	if (currentTime >= 81.5151 && (currentTime - DeltaTime) < 81.5151)
	{
		spawnSnareNode();
	}
#pragma endregion 67
#pragma region 68
	if (currentTime >= 82.1257 && (currentTime - DeltaTime) < 82.1257)
	{
		spawnSnareNode();
	}
	if (currentTime >= 82.7363 && (currentTime - DeltaTime) < 82.7363)
	{
		spawnSnareNode();
	}
#pragma endregion 68
#pragma region 69
	if (currentTime >= 83.3469 && (currentTime - DeltaTime) < 83.3469)
	{
		spawnSnareNode();
	}
	if (currentTime >= 83.9575 && (currentTime - DeltaTime) < 83.9575)
	{
		spawnSnareNode();
	}
#pragma endregion 69
#pragma region 70
	if (currentTime >= 84.5681 && (currentTime - DeltaTime) < 84.5681)
	{
		spawnSnareNode();
	}
	if (currentTime >= 85.1787 && (currentTime - DeltaTime) < 85.1787)
	{
		spawnSnareNode();
	}
#pragma endregion 70
#pragma region 71
	if (currentTime >= 85.7893 && (currentTime - DeltaTime) < 85.7893)
	{
		spawnSnareNode();
	}
	if (currentTime >= 86.0946 && (currentTime - DeltaTime) < 86.0946)
	{
		spawnSnareNode();
	}
	if (currentTime >= 86.24725 && (currentTime - DeltaTime) < 86.24725)
	{
		spawnSnareNode();
	}
	if (currentTime >= 86.3999 && (currentTime - DeltaTime) < 86.3999)
	{
		spawnSnareNode();
	}
	if (currentTime >= 86.55255 && (currentTime - DeltaTime) < 86.55255)
	{
		spawnSnareNode();
	}
#pragma endregion 71
#pragma region 72
	if (currentTime >= 86.85785 && (currentTime - DeltaTime) < 86.85785)
	{
		spawnSnareNode();
	}
	if (currentTime >= 87.3158 && (currentTime - DeltaTime) < 87.3158)
	{
		spawnSnareNode();
	}
	if (currentTime >= 87.77375 && (currentTime - DeltaTime) < 87.77375)
	{
		spawnSnareNode();
	}
#pragma endregion 72
#pragma region 73
	if (currentTime >= 88.07905 && (currentTime - DeltaTime) < 88.07905)
	{
		spawnSnareNode();
	}
	if (currentTime >= 88.537 && (currentTime - DeltaTime) < 88.537)
	{
		spawnSnareNode();
	}
#pragma endregion 73
#pragma region 74
	if (currentTime >= 89.1476 && (currentTime - DeltaTime) < 89.1476)
	{
		spawnSnareNode();
	}
	if (currentTime >= 89.7582 && (currentTime - DeltaTime) < 89.7582)
	{
		spawnSnareNode();
	}
#pragma endregion 74
#pragma region 75
	if (currentTime >= 90.52145 && (currentTime - DeltaTime) < 90.52145)
	{
		spawnSnareNode();
	}
	if (currentTime >= 90.597775 && (currentTime - DeltaTime) < 90.597775)
	{
		spawnSnareNode();
	}
	if (currentTime >= 90.6741 && (currentTime - DeltaTime) < 90.6741)
	{
		spawnSnareNode();
	}
	if (currentTime >= 90.750425 && (currentTime - DeltaTime) < 90.750425)
	{
		spawnSnareNode();
	}
	if (currentTime >= 90.82675 && (currentTime - DeltaTime) < 90.82675)
	{
		spawnSnareNode();
	}
	if (currentTime >= 90.903075 && (currentTime - DeltaTime) < 90.903075)
	{
		spawnSnareNode();
	}
	if (currentTime >= 91.13205 && (currentTime - DeltaTime) < 91.13205)
	{
		spawnSnareNode();
	}
	if (currentTime >= 91.208375 && (currentTime - DeltaTime) < 91.208375)
	{
		spawnSnareNode();
	}
	if (currentTime >= 91.2847 && (currentTime - DeltaTime) < 91.2847)
	{
		spawnSnareNode();
	}
	if (currentTime >= 91.361025 && (currentTime - DeltaTime) < 91.361025)
	{
		spawnSnareNode();
	}
	if (currentTime >= 91.43735 && (currentTime - DeltaTime) < 91.43735)
	{
		spawnSnareNode();
	}
	if (currentTime >= 91.513675 && (currentTime - DeltaTime) < 91.513675)
	{
		spawnSnareNode();
	}
#pragma endregion 75
#pragma region 76
	if (currentTime >= 91.74265 && (currentTime - DeltaTime) < 91.74265)
	{
		spawnSnareNode();
	}
	if (currentTime >= 92.2006 && (currentTime - DeltaTime) < 92.2006)
	{
		spawnSnareNode();
	}
	if (currentTime >= 92.65855 && (currentTime - DeltaTime) < 92.65855)
	{
		spawnSnareNode();
	}
#pragma endregion 76
#pragma region 77
	if (currentTime >= 92.96385 && (currentTime - DeltaTime) < 92.96385)
	{
		spawnSnareNode();
	}
	if (currentTime >= 93.4218 && (currentTime - DeltaTime) < 93.4218)
	{
		spawnSnareNode();
	}
#pragma endregion 77
#pragma region 78
	if (currentTime >= 94.0324 && (currentTime - DeltaTime) < 94.0324)
	{
		spawnSnareNode();
	}
	if (currentTime >= 94.643 && (currentTime - DeltaTime) < 94.643)
	{
		spawnSnareNode();
	}
#pragma endregion 78
#pragma region 79
	if (currentTime >= 95.2536 && (currentTime - DeltaTime) < 95.2536)
	{
		spawnSnareNode();
	}
	if (currentTime >= 95.40625 && (currentTime - DeltaTime) < 95.40625)
	{
		spawnSnareNode();
	}
	if (currentTime >= 95.5589 && (currentTime - DeltaTime) < 95.5589)
	{
		spawnSnareNode();
	}
	if (currentTime >= 95.8642 && (currentTime - DeltaTime) < 95.8642)
	{
		spawnSnareNode();
	}
	if (currentTime >= 95.940525 && (currentTime - DeltaTime) < 95.940525)
	{
		spawnSnareNode();
	}
	if (currentTime >= 96.1695 && (currentTime - DeltaTime) < 96.1695)
	{
		spawnSnareNode();
	}
	if (currentTime >= 96.32215 && (currentTime - DeltaTime) < 96.32215)
	{
		spawnSnareNode();
	}
#pragma endregion 79
#pragma region 80
	if (currentTime >= 96.4748 && (currentTime - DeltaTime) < 96.4748)
	{
		spawnSnareNode();
	}
	if (currentTime >= 97.0854 && (currentTime - DeltaTime) < 97.0854)
	{
		spawnSnareNode();
	}
#pragma endregion 80
#pragma region 81
	if (currentTime >= 97.696 && (currentTime - DeltaTime) < 97.696)
	{
		spawnSnareNode();
	}
	if (currentTime >= 98.3066 && (currentTime - DeltaTime) < 98.3066)
	{
		spawnSnareNode();
	}
	if (currentTime >= 98.6119 && (currentTime - DeltaTime) < 98.6119)
	{
		spawnSnareNode();
	}
	if (currentTime >= 98.688225 && (currentTime - DeltaTime) < 98.688225)
	{
		spawnSnareNode();
	}
#pragma endregion 81
#pragma region 82
	if (currentTime >= 98.9172 && (currentTime - DeltaTime) < 98.9172)
	{
		spawnSnareNode();
	}
	if (currentTime >= 99.5278 && (currentTime - DeltaTime) < 99.5278)
	{
		spawnSnareNode();
	}
#pragma endregion 82
#pragma region 83
	if (currentTime >= 100.1384 && (currentTime - DeltaTime) < 100.1384)
	{
		spawnSnareNode();
	}
	if (currentTime >= 100.749 && (currentTime - DeltaTime) < 100.749)
	{
		spawnSnareNode();
	}
	if (currentTime >= 101.0543 && (currentTime - DeltaTime) < 101.0543)
	{
		spawnSnareNode();
	}
	if (currentTime >= 101.130625 && (currentTime - DeltaTime) < 101.130625)
	{
		spawnSnareNode();
	}
	if (currentTime >= 101.20695 && (currentTime - DeltaTime) < 101.20695)
	{
		spawnSnareNode();
	}
#pragma endregion 83
#pragma region 84
	if (currentTime >= 101.3596 && (currentTime - DeltaTime) < 101.3596)
	{
		spawnSnareNode();
	}
	if (currentTime >= 101.9702 && (currentTime - DeltaTime) < 101.9702)
	{
		spawnSnareNode();
	}
#pragma endregion 84
#pragma region 85
	if (currentTime >= 102.5808 && (currentTime - DeltaTime) < 102.5808)
	{
		spawnSnareNode();
	}
	if (currentTime >= 103.1914 && (currentTime - DeltaTime) < 103.1914)
	{
		spawnSnareNode();
	}
	if (currentTime >= 103.4967 && (currentTime - DeltaTime) < 103.4967)
	{
		spawnSnareNode();
	}
	if (currentTime >= 103.573025 && (currentTime - DeltaTime) < 103.573025)
	{
		spawnSnareNode();
	}
#pragma endregion 85
#pragma region 86
	if (currentTime >= 103.802 && (currentTime - DeltaTime) < 103.802)
	{
		spawnSnareNode();
	}
	if (currentTime >= 104.4126 && (currentTime - DeltaTime) < 104.4126)
	{
		spawnSnareNode();
	}
#pragma endregion 86
#pragma region 87
	if (currentTime >= 105.0232 && (currentTime - DeltaTime) < 105.0232)
	{
		spawnSnareNode();
	}
	if (currentTime >= 105.6338 && (currentTime - DeltaTime) < 105.6338)
	{
		spawnSnareNode();
	}
	if (currentTime >= 105.9391 && (currentTime - DeltaTime) < 105.9391)
	{
		spawnSnareNode();
	}
	if (currentTime >= 106.015425 && (currentTime - DeltaTime) < 106.015425)
	{
		spawnSnareNode();
	}
#pragma endregion 87
#pragma region 88
	if (currentTime >= 106.2444 && (currentTime - DeltaTime) < 106.2444)
	{
		spawnSnareNode();
	}
	if (currentTime >= 106.39705 && (currentTime - DeltaTime) < 106.39705)
	{
		spawnSnareNode();
	}
	if (currentTime >= 106.5497 && (currentTime - DeltaTime) < 106.5497)
	{
		spawnSnareNode();
	}
#pragma endregion 88
#pragma region 89
	if (currentTime >= 107.4656 && (currentTime - DeltaTime) < 107.4656)
	{
		spawnSnareNode();
	}
	if (currentTime >= 107.61825 && (currentTime - DeltaTime) < 107.61825)
	{
		spawnSnareNode();
	}
	if (currentTime >= 107.7709 && (currentTime - DeltaTime) < 107.7709)
	{
		spawnSnareNode();
	}
#pragma endregion 89
#pragma region 90
	if (currentTime >= 108.6868 && (currentTime - DeltaTime) < 108.6868)
	{
		spawnSnareNode();
	}
	if (currentTime >= 108.83945 && (currentTime - DeltaTime) < 108.83945)
	{
		spawnSnareNode();
	}
	if (currentTime >= 108.9921 && (currentTime - DeltaTime) < 108.9921)
	{
		spawnSnareNode();
	}
#pragma endregion 90
#pragma region 91
	if (currentTime >= 109.908 && (currentTime - DeltaTime) < 109.908)
	{
		spawnSnareNode();
	}
	if (currentTime >= 110.06065 && (currentTime - DeltaTime) < 110.06065)
	{
		spawnSnareNode();
	}
	if (currentTime >= 110.2133 && (currentTime - DeltaTime) < 110.2133)
	{
		spawnSnareNode();
	}
	if (currentTime >= 110.5186 && (currentTime - DeltaTime) < 110.5186)
	{
		spawnSnareNode();
	}
	if (currentTime >= 110.594925 && (currentTime - DeltaTime) < 110.594925)
	{
		spawnSnareNode();
	}
#pragma endregion 91
#pragma region 92
	if (currentTime >= 111.7398 && (currentTime - DeltaTime) < 111.7398)
	{
		spawnSnareNode();
	}
#pragma endregion 92
#pragma region 93
	if (currentTime >= 112.961 && (currentTime - DeltaTime) < 112.961)
	{
		spawnSnareNode();
	}
#pragma endregion 93
#pragma region 94
	if (currentTime >= 114.1822 && (currentTime - DeltaTime) < 114.1822)
	{
		spawnSnareNode();
	}
#pragma endregion 94
#pragma region 95
	if (currentTime >= 115.4034 && (currentTime - DeltaTime) < 115.4034)
	{
		spawnSnareNode();
	}
	if (currentTime >= 115.86135 && (currentTime - DeltaTime) < 115.86135)
	{
		spawnSnareNode();
	}
#pragma endregion 95
#pragma region 96
	if (currentTime >= 116.6246 && (currentTime - DeltaTime) < 116.6246)
	{
		spawnSnareNode();
	}
#pragma endregion 96
#pragma region 97
	if (currentTime >= 117.8458 && (currentTime - DeltaTime) < 117.8458)
	{
		spawnSnareNode();
	}
#pragma endregion 97
#pragma region 98
	if (currentTime >= 119.067 && (currentTime - DeltaTime) < 119.067)
	{
		spawnSnareNode();
	}
#pragma endregion 98
#pragma region 99
	if (currentTime >= 120.2882 && (currentTime - DeltaTime) < 120.2882)
	{
		spawnSnareNode();
	}
	if (currentTime >= 120.364525 && (currentTime - DeltaTime) < 120.364525)
	{
		spawnSnareNode();
	}
	if (currentTime >= 120.5935 && (currentTime - DeltaTime) < 120.5935)
	{
		spawnSnareNode();
	}
	if (currentTime >= 120.669825 && (currentTime - DeltaTime) < 120.669825)
	{
		spawnSnareNode();
	}
#pragma endregion 99
#pragma region 100
	if (currentTime >= 121.5094 && (currentTime - DeltaTime) < 121.5094)
	{
		spawnSnareNode();
	}
#pragma endregion 100
#pragma region 101
	if (currentTime >= 122.7306 && (currentTime - DeltaTime) < 122.7306)
	{
		spawnSnareNode();
	}
#pragma endregion 101
#pragma region 102
	if (currentTime >= 123.9518 && (currentTime - DeltaTime) < 123.9518)
	{
		spawnSnareNode();
	}
#pragma endregion 102
#pragma region 103
	if (currentTime >= 125.173 && (currentTime - DeltaTime) < 125.173)
	{
		spawnSnareNode();
	}
	if (currentTime >= 125.249325 && (currentTime - DeltaTime) < 125.249325)
	{
		spawnSnareNode();
	}
	if (currentTime >= 125.32565 && (currentTime - DeltaTime) < 125.32565)
	{
		spawnSnareNode();
	}
	if (currentTime >= 125.4783 && (currentTime - DeltaTime) < 125.4783)
	{
		spawnSnareNode();
	}
#pragma endregion 103
#pragma region 104
	if (currentTime >= 126.3942 && (currentTime - DeltaTime) < 126.3942)
	{
		spawnSnareNode();
	}
#pragma endregion 104
#pragma region 105
	if (currentTime >= 127.6154 && (currentTime - DeltaTime) < 127.6154)
	{
		spawnSnareNode();
	}
#pragma endregion 105
#pragma region 106
	if (currentTime >= 128.8366 && (currentTime - DeltaTime) < 128.8366)
	{
		spawnSnareNode();
	}
#pragma endregion 106
#pragma region 107
	if (currentTime >= 129.59985 && (currentTime - DeltaTime) < 129.59985)
	{
		spawnSnareNode();
	}
	if (currentTime >= 129.676175 && (currentTime - DeltaTime) < 129.676175)
	{
		spawnSnareNode();
	}
	if (currentTime >= 129.7525 && (currentTime - DeltaTime) < 129.7525)
	{
		spawnSnareNode();
	}
	if (currentTime >= 129.828825 && (currentTime - DeltaTime) < 129.828825)
	{
		spawnSnareNode();
	}
	if (currentTime >= 129.90515 && (currentTime - DeltaTime) < 129.90515)
	{
		spawnSnareNode();
	}
	if (currentTime >= 129.981475 && (currentTime - DeltaTime) < 129.981475)
	{
		spawnSnareNode();
	}
	if (currentTime >= 130.0578 && (currentTime - DeltaTime) < 130.0578)
	{
		spawnSnareNode();
	}
	if (currentTime >= 130.134125 && (currentTime - DeltaTime) < 130.134125)
	{
		spawnSnareNode();
	}
	if (currentTime >= 130.21045 && (currentTime - DeltaTime) < 130.21045)
	{
		spawnSnareNode();
	}
	if (currentTime >= 130.286775 && (currentTime - DeltaTime) < 130.286775)
	{
		spawnSnareNode();
	}
	if (currentTime >= 130.3631 && (currentTime - DeltaTime) < 130.3631)
	{
		spawnSnareNode();
	}
	if (currentTime >= 130.439425 && (currentTime - DeltaTime) < 130.439425)
	{
		spawnSnareNode();
	}
	if (currentTime >= 130.51575 && (currentTime - DeltaTime) < 130.51575)
	{
		spawnSnareNode();
	}
	if (currentTime >= 130.592075 && (currentTime - DeltaTime) < 130.592075)
	{
		spawnSnareNode();
	}
#pragma endregion 107
#pragma region 108
	if (currentTime >= 130.6684 && (currentTime - DeltaTime) < 130.6684)
	{
		spawnSnareNode();
	}
	if (currentTime >= 130.744725 && (currentTime - DeltaTime) < 130.744725)
	{
		spawnSnareNode();
	}
	if (currentTime >= 130.82105 && (currentTime - DeltaTime) < 130.82105)
	{
		spawnSnareNode();
	}
	if (currentTime >= 130.897375 && (currentTime - DeltaTime) < 130.897375)
	{
		spawnSnareNode();
	}
	if (currentTime >= 130.9737 && (currentTime - DeltaTime) < 130.9737)
	{
		spawnSnareNode();
	}
	if (currentTime >= 131.050025 && (currentTime - DeltaTime) < 131.050025)
	{
		spawnSnareNode();
	}
	if (currentTime >= 131.12635 && (currentTime - DeltaTime) < 131.12635)
	{
		spawnSnareNode();
	}
	if (currentTime >= 131.202675 && (currentTime - DeltaTime) < 131.202675)
	{
		spawnSnareNode();
	}
	if (currentTime >= 131.279 && (currentTime - DeltaTime) < 131.279)
	{
		spawnSnareNode();
	}
	if (currentTime >= 131.355325 && (currentTime - DeltaTime) < 131.355325)
	{
		spawnSnareNode();
	}
	if (currentTime >= 131.43165 && (currentTime - DeltaTime) < 131.43165)
	{
		spawnSnareNode();
	}
	if (currentTime >= 131.507975 && (currentTime - DeltaTime) < 131.507975)
	{
		spawnSnareNode();
	}
	if (currentTime >= 131.5843 && (currentTime - DeltaTime) < 131.5843)
	{
		spawnSnareNode();
	}
	if (currentTime >= 131.660625 && (currentTime - DeltaTime) < 131.660625)
	{
		spawnSnareNode();
	}
	if (currentTime >= 131.73695 && (currentTime - DeltaTime) < 131.73695)
	{
		spawnSnareNode();
	}
	if (currentTime >= 131.813275 && (currentTime - DeltaTime) < 131.813275)
	{
		spawnSnareNode();
	}
#pragma endregion 108
#pragma region 109
	if (currentTime >= 132.1949 && (currentTime - DeltaTime) < 132.1949)
	{
		spawnSnareNode();
	}
	if (currentTime >= 132.8055 && (currentTime - DeltaTime) < 132.8055)
	{
		spawnSnareNode();
	}
#pragma endregion 109
#pragma region 110
	if (currentTime >= 133.4161 && (currentTime - DeltaTime) < 133.4161)
	{
		spawnSnareNode();
	}
	if (currentTime >= 134.0267 && (currentTime - DeltaTime) < 134.0267)
	{
		spawnSnareNode();
	}
#pragma endregion 110
#pragma region 111
	if (currentTime >= 134.6373 && (currentTime - DeltaTime) < 134.6373)
	{
		spawnSnareNode();
	}
	if (currentTime >= 135.2479 && (currentTime - DeltaTime) < 135.2479)
	{
		spawnSnareNode();
	}
#pragma endregion 111
#pragma region 112
	if (currentTime >= 135.8585 && (currentTime - DeltaTime) < 135.8585)
	{
		spawnSnareNode();
	}
	if (currentTime >= 136.4691 && (currentTime - DeltaTime) < 136.4691)
	{
		spawnSnareNode();
	}
#pragma endregion 112
#pragma region 113
	if (currentTime >= 137.0797 && (currentTime - DeltaTime) < 137.0797)
	{
		spawnSnareNode();
	}
	if (currentTime >= 137.6903 && (currentTime - DeltaTime) < 137.6903)
	{
		spawnSnareNode();
	}
#pragma endregion 113
#pragma region 114
	if (currentTime >= 138.3009 && (currentTime - DeltaTime) < 138.3009)
	{
		spawnSnareNode();
	}
	if (currentTime >= 138.9115 && (currentTime - DeltaTime) < 138.9115)
	{
		spawnSnareNode();
	}
#pragma endregion 114
#pragma region 115
	if (currentTime >= 139.5221 && (currentTime - DeltaTime) < 139.5221)
	{
		spawnSnareNode();
	}
	if (currentTime >= 140.1327 && (currentTime - DeltaTime) < 140.1327)
	{
		spawnSnareNode();
	}
#pragma endregion 115
#pragma region 116
	if (currentTime >= 140.59065 && (currentTime - DeltaTime) < 140.59065)
	{
		spawnSnareNode();
	}
	if (currentTime >= 140.7433 && (currentTime - DeltaTime) < 140.7433)
	{
		spawnSnareNode();
	}
	if (currentTime >= 140.819625 && (currentTime - DeltaTime) < 140.819625)
	{
		spawnSnareNode();
	}
	if (currentTime >= 140.89595 && (currentTime - DeltaTime) < 140.89595)
	{
		spawnSnareNode();
	}
	if (currentTime >= 140.972275 && (currentTime - DeltaTime) < 140.972275)
	{
		spawnSnareNode();
	}
	if (currentTime >= 141.0486 && (currentTime - DeltaTime) < 141.0486)
	{
		spawnSnareNode();
	}
	if (currentTime >= 141.124925 && (currentTime - DeltaTime) < 141.124925)
	{
		spawnSnareNode();
	}
	if (currentTime >= 141.20125 && (currentTime - DeltaTime) < 141.20125)
	{
		spawnSnareNode();
	}
	if (currentTime >= 141.277575 && (currentTime - DeltaTime) < 141.277575)
	{
		spawnSnareNode();
	}
#pragma endregion 116
#pragma region 117
	if (currentTime >= 141.9645 && (currentTime - DeltaTime) < 141.9645)
	{
		spawnSnareNode();
	}
	if (currentTime >= 142.5751 && (currentTime - DeltaTime) < 142.5751)
	{
		spawnSnareNode();
	}
#pragma endregion 117
#pragma region 118
	if (currentTime >= 143.1857 && (currentTime - DeltaTime) < 143.1857)
	{
		spawnSnareNode();
	}
	if (currentTime >= 143.7963 && (currentTime - DeltaTime) < 143.7963)
	{
		spawnSnareNode();
	}
#pragma endregion 118
#pragma region 119
	if (currentTime >= 144.4069 && (currentTime - DeltaTime) < 144.4069)
	{
		spawnSnareNode();
	}
	if (currentTime >= 145.0175 && (currentTime - DeltaTime) < 145.0175)
	{
		spawnSnareNode();
	}
#pragma endregion 119
#pragma region 120
	if (currentTime >= 145.6281 && (currentTime - DeltaTime) < 145.6281)
	{
		spawnSnareNode();
	}
	if (currentTime >= 146.2387 && (currentTime - DeltaTime) < 146.2387)
	{
		spawnSnareNode();
	}
#pragma endregion 120
#pragma region 121
	if (currentTime >= 146.8493 && (currentTime - DeltaTime) < 146.8493)
	{
		spawnSnareNode();
	}
	if (currentTime >= 147.4599 && (currentTime - DeltaTime) < 147.4599)
	{
		spawnSnareNode();
	}
#pragma endregion 121
#pragma region 122
	if (currentTime >= 148.0705 && (currentTime - DeltaTime) < 148.0705)
	{
		spawnSnareNode();
	}
	if (currentTime >= 148.6811 && (currentTime - DeltaTime) < 148.6811)
	{
		spawnSnareNode();
	}
#pragma endregion 122
#pragma region 123
	if (currentTime >= 149.2917 && (currentTime - DeltaTime) < 149.2917)
	{
		spawnSnareNode();
	}
	if (currentTime >= 149.9023 && (currentTime - DeltaTime) < 149.9023)
	{
		spawnSnareNode();
	}
#pragma endregion 123
#pragma region 124
	if (currentTime >= 150.5129 && (currentTime - DeltaTime) < 150.5129)
	{
		spawnSnareNode();
	}
	if (currentTime >= 151.1235 && (currentTime - DeltaTime) < 151.1235)
	{
		spawnSnareNode();
	}
#pragma endregion 124
#pragma region 125
	if (currentTime >= 151.4288 && (currentTime - DeltaTime) < 151.4288)
	{
		spawnSnareNode();
	}
	if (currentTime >= 151.7341 && (currentTime - DeltaTime) < 151.7341)
	{
		spawnSnareNode();
	}
	if (currentTime >= 152.0394 && (currentTime - DeltaTime) < 152.0394)
	{
		spawnSnareNode();
	}
	if (currentTime >= 152.115725 && (currentTime - DeltaTime) < 152.115725)
	{
		spawnSnareNode();
	}
	if (currentTime >= 152.19205 && (currentTime - DeltaTime) < 152.19205)
	{
		spawnSnareNode();
	}
	if (currentTime >= 152.3447 && (currentTime - DeltaTime) < 152.3447)
	{
		spawnSnareNode();
	}
	if (currentTime >= 152.421025 && (currentTime - DeltaTime) < 152.421025)
	{
		spawnSnareNode();
	}
#pragma endregion 125
*/
}

void AOSY_SnareFactory::spawnSnareNode()
{
	// 생성위치
	FVector FactoryLoc = GetActorLocation();

	GetWorld()->SpawnActor<AOSY_SnareNodeActor>(NodeFactory, FactoryLoc, FRotator::ZeroRotator);

}

