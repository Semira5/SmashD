// Fill out your copyright notice in the Description page of Project Settings.


#include "OSY_HiHatFactory.h"
#include "OSY_NodeActor.h"

// Sets default values
AOSY_HiHatFactory::AOSY_HiHatFactory()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AOSY_HiHatFactory::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOSY_HiHatFactory::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	currentTime += DeltaTime;
#pragma region 13
	if (currentTime >= 14.9597f && (currentTime - DeltaTime) < 14.9597f)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 15.5703f && (currentTime - DeltaTime) < 15.5703f)
	{
		spawnHiHatNode();
	}
#pragma endregion 13
#pragma region 14
	if (currentTime >= 15.8756f && (currentTime - DeltaTime) < 15.8756f)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 16.1809f && (currentTime - DeltaTime) < 16.1809f)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 16.4862f && (currentTime - DeltaTime) < 16.4862f)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 16.7915f && (currentTime - DeltaTime) < 16.7915f)
	{
		spawnHiHatNode();
	}
#pragma endregion 14
#pragma region 15
	if (currentTime >= 17.0968f && (currentTime - DeltaTime) < 17.0968f)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 17.4021f && (currentTime - DeltaTime) < 17.4021f)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 17.7074f && (currentTime - DeltaTime) < 17.7074f)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 18.0127f && (currentTime - DeltaTime) < 18.0127f)
	{
		spawnHiHatNode();
	}
#pragma endregion 15
#pragma region 16
	if (currentTime >= 18.318 && (currentTime - DeltaTime) < 18.318)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 18.6233 && (currentTime - DeltaTime) < 18.6233)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 18.9286 && (currentTime - DeltaTime) < 18.9286)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 19.2339 && (currentTime - DeltaTime) < 19.2339)
	{
		spawnHiHatNode();
	}
#pragma endregion 16
#pragma region 18
	if (currentTime >= 21.0657 && (currentTime - DeltaTime) < 21.0657)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 21.21835 && (currentTime - DeltaTime) < 21.21835)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 21.371 && (currentTime - DeltaTime) < 21.371)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 21.52365 && (currentTime - DeltaTime) < 21.52365)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 21.6763 && (currentTime - DeltaTime) < 21.6763)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 21.82895 && (currentTime - DeltaTime) < 21.82895)
	{
		spawnHiHatNode();
	}
#pragma endregion 18
#pragma region 19
	if (currentTime >= 21.9816 && (currentTime - DeltaTime) < 21.9816)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 22.13425 && (currentTime - DeltaTime) < 22.13425)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 22.2869 && (currentTime - DeltaTime) < 22.2869)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 22.43955 && (currentTime - DeltaTime) < 22.43955)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 22.5922 && (currentTime - DeltaTime) < 22.5922)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 22.74485 && (currentTime - DeltaTime) < 22.74485)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 22.8975 && (currentTime - DeltaTime) < 22.8975)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 23.05015 && (currentTime - DeltaTime) < 23.05015)
	{
		spawnHiHatNode();
	}
#pragma endregion 19
#pragma region 20
	if (currentTime >= 23.2028 && (currentTime - DeltaTime) < 23.2028)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 23.35545 && (currentTime - DeltaTime) < 23.35545)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 23.5081 && (currentTime - DeltaTime) < 23.5081)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 23.66075 && (currentTime - DeltaTime) < 23.66075)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 23.8134 && (currentTime - DeltaTime) < 23.8134)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 23.96605 && (currentTime - DeltaTime) < 23.96605)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 24.1187 && (currentTime - DeltaTime) < 24.1187)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 24.27135 && (currentTime - DeltaTime) < 24.27135)
	{
		spawnHiHatNode();
	}
#pragma endregion 20
#pragma region 21
	if (currentTime >= 24.424 && (currentTime - DeltaTime) < 24.424)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 24.57665 && (currentTime - DeltaTime) < 24.57665)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 24.7293 && (currentTime - DeltaTime) < 24.7293)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 24.88195 && (currentTime - DeltaTime) < 24.88195)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 25.0346 && (currentTime - DeltaTime) < 25.0346)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 25.18725 && (currentTime - DeltaTime) < 25.18725)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 25.3399 && (currentTime - DeltaTime) < 25.3399)
	{
		spawnHiHatNode();
	}
#pragma endregion 21
#pragma region 22
	if (currentTime >= 25.6452 && (currentTime - DeltaTime) < 25.6452)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 25.79785 && (currentTime - DeltaTime) < 25.79785)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 25.9505 && (currentTime - DeltaTime) < 25.9505)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 26.10315 && (currentTime - DeltaTime) < 26.10315)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 26.2558 && (currentTime - DeltaTime) < 26.2558)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 26.40845 && (currentTime - DeltaTime) < 26.40845)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 26.5611 && (currentTime - DeltaTime) < 26.5611)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 26.71375 && (currentTime - DeltaTime) < 26.71375)
	{
		spawnHiHatNode();
	}
#pragma endregion 22
#pragma region 23
	if (currentTime >= 26.8664 && (currentTime - DeltaTime) < 26.8664)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 27.01905 && (currentTime - DeltaTime) < 27.01905)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 27.1717 && (currentTime - DeltaTime) < 27.1717)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 27.32435 && (currentTime - DeltaTime) < 27.32435)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 27.477 && (currentTime - DeltaTime) < 27.477)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 27.62965 && (currentTime - DeltaTime) < 27.62965)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 27.7823 && (currentTime - DeltaTime) < 27.7823)
	{
		spawnHiHatNode();
	}

#pragma endregion 23
#pragma region 24
	if (currentTime >= 28.0876 && (currentTime - DeltaTime) < 28.0876)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 28.3929 && (currentTime - DeltaTime) < 28.3929)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 28.6982 && (currentTime - DeltaTime) < 28.6982)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 29.0035 && (currentTime - DeltaTime) < 29.0035)
	{
		spawnHiHatNode();
	}
#pragma endregion 24
#pragma region 25
	if (currentTime >= 29.3088 && (currentTime - DeltaTime) < 29.3088)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 29.6141 && (currentTime - DeltaTime) < 29.6141)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 29.9194 && (currentTime - DeltaTime) < 29.9194)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 30.2247 && (currentTime - DeltaTime) < 30.2247)
	{
		spawnHiHatNode();
	}
#pragma endregion 25
#pragma region 26
	if (currentTime >= 30.8353 && (currentTime - DeltaTime) < 30.8353)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 31.1406 && (currentTime - DeltaTime) < 31.1406)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 31.4459 && (currentTime - DeltaTime) < 31.4459)
	{
		spawnHiHatNode();
	}
#pragma endregion 26
#pragma region 27
	if (currentTime >= 31.7512 && (currentTime - DeltaTime) < 31.7512)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 32.0565 && (currentTime - DeltaTime) < 32.0565)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 32.3618 && (currentTime - DeltaTime) < 32.3618)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 32.6671 && (currentTime - DeltaTime) < 32.6671)
	{
		spawnHiHatNode();
	}
#pragma endregion 27
#pragma region 28
	if (currentTime >= 32.9724 && (currentTime - DeltaTime) < 32.9724)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 33.2777 && (currentTime - DeltaTime) < 33.2777)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 33.583 && (currentTime - DeltaTime) < 33.583)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 33.8883 && (currentTime - DeltaTime) < 33.8883)
	{
		spawnHiHatNode();
	}
#pragma endregion 28
#pragma region 29
	if (currentTime >= 34.1936 && (currentTime - DeltaTime) < 34.1936)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 34.4989 && (currentTime - DeltaTime) < 34.4989)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 34.8042 && (currentTime - DeltaTime) < 34.8042)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 35.1095 && (currentTime - DeltaTime) < 35.1095)
	{
		spawnHiHatNode();
	}
#pragma endregion 29
#pragma region 30
	if (currentTime >= 35.7201 && (currentTime - DeltaTime) < 35.7201)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 36.0254 && (currentTime - DeltaTime) < 36.0254)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 36.3307 && (currentTime - DeltaTime) < 36.3307)
	{
		spawnHiHatNode();
	}
#pragma endregion 30
#pragma region 31
	if (currentTime >= 36.636 && (currentTime - DeltaTime) < 36.636)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 36.9413 && (currentTime - DeltaTime) < 36.9413)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 37.2466 && (currentTime - DeltaTime) < 37.2466)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 37.5519 && (currentTime - DeltaTime) < 37.5519)
	{
		spawnHiHatNode();
	}
#pragma endregion 31
#pragma region 32
	if (currentTime >= 37.8572 && (currentTime - DeltaTime) < 37.8572)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 38.1625 && (currentTime - DeltaTime) < 38.1625)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 38.4678 && (currentTime - DeltaTime) < 38.4678)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 38.7731 && (currentTime - DeltaTime) < 38.7731)
	{
		spawnHiHatNode();
	}
#pragma endregion 32
#pragma region 38
	if (currentTime >= 45.4897 && (currentTime - DeltaTime) < 45.4897)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 45.94765 && (currentTime - DeltaTime) < 45.94765)
	{
		spawnHiHatNode();
	}
#pragma endregion 38
#pragma region 42
	if (currentTime >= 50.3745 && (currentTime - DeltaTime) < 50.3745)
	{
		spawnHiHatNode();
	}
#pragma endregion 42
#pragma region 43
	if (currentTime >= 51.5957 && (currentTime - DeltaTime) < 51.5957)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 51.901 && (currentTime - DeltaTime) < 51.901)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 52.2063 && (currentTime - DeltaTime) < 52.2063)
	{
		spawnHiHatNode();
	}
#pragma endregion 43
#pragma region 44
	if (currentTime >= 52.5116 && (currentTime - DeltaTime) < 52.5116)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 52.8169 && (currentTime - DeltaTime) < 52.8169)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 53.1222 && (currentTime - DeltaTime) < 53.1222)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 53.4275 && (currentTime - DeltaTime) < 53.4275)
	{
		spawnHiHatNode();
	}
#pragma endregion 44
#pragma region 45
	if (currentTime >= 53.7328 && (currentTime - DeltaTime) < 53.7328)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 54.0381 && (currentTime - DeltaTime) < 54.0381)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 54.3434 && (currentTime - DeltaTime) < 54.3434)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 54.6487 && (currentTime - DeltaTime) < 54.6487)
	{
		spawnHiHatNode();
	}
#pragma endregion 45
#pragma region 46
	if (currentTime >= 54.954 && (currentTime - DeltaTime) < 54.954)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 55.2593 && (currentTime - DeltaTime) < 55.2593)
	{
		spawnHiHatNode();
	}
#pragma endregion 46
#pragma region 47
	if (currentTime >= 56.4805 && (currentTime - DeltaTime) < 56.4805)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 56.63315 && (currentTime - DeltaTime) < 56.63315)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 56.7858 && (currentTime - DeltaTime) < 56.7858)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 56.93845 && (currentTime - DeltaTime) < 56.93845)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 57.0911 && (currentTime - DeltaTime) < 57.0911)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 57.24375 && (currentTime - DeltaTime) < 57.24375)
	{
		spawnHiHatNode();
	}
#pragma endregion 47
#pragma region 48
	if (currentTime >= 57.3964 && (currentTime - DeltaTime) < 57.3964)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 57.54905 && (currentTime - DeltaTime) < 57.54905)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 57.7017 && (currentTime - DeltaTime) < 57.7017)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 57.85435 && (currentTime - DeltaTime) < 57.85435)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 58.007 && (currentTime - DeltaTime) < 58.007)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 58.15965 && (currentTime - DeltaTime) < 58.15965)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 58.3123 && (currentTime - DeltaTime) < 58.3123)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 58.46495 && (currentTime - DeltaTime) < 58.46495)
	{
		spawnHiHatNode();
	}
#pragma endregion 48
#pragma region 49
	if (currentTime >= 58.6176 && (currentTime - DeltaTime) < 58.6176)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 58.77025 && (currentTime - DeltaTime) < 58.77025)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 58.9229 && (currentTime - DeltaTime) < 58.9229)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 59.07555 && (currentTime - DeltaTime) < 59.07555)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 59.2282 && (currentTime - DeltaTime) < 59.2282)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 59.38085 && (currentTime - DeltaTime) < 59.38085)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 59.5335 && (currentTime - DeltaTime) < 59.5335)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 59.68615 && (currentTime - DeltaTime) < 59.68615)
	{
		spawnHiHatNode();
	}
#pragma endregion 49
#pragma region 50
	if (currentTime >= 59.8388 && (currentTime - DeltaTime) < 59.8388)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 59.99145 && (currentTime - DeltaTime) < 59.99145)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 60.1441 && (currentTime - DeltaTime) < 60.1441)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 60.29675 && (currentTime - DeltaTime) < 60.29675)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 60.4494 && (currentTime - DeltaTime) < 60.4494)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 60.60205 && (currentTime - DeltaTime) < 60.60205)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 60.7547 && (currentTime - DeltaTime) < 60.7547)
	{
		spawnHiHatNode();
	}
#pragma endregion 50
#pragma region 51
	if (currentTime >= 61.06 && (currentTime - DeltaTime) < 61.06)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 61.21265 && (currentTime - DeltaTime) < 61.21265)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 61.3653 && (currentTime - DeltaTime) < 61.3653)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 61.51795 && (currentTime - DeltaTime) < 61.51795)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 61.6706 && (currentTime - DeltaTime) < 61.6706)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 61.82325 && (currentTime - DeltaTime) < 61.82325)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 61.9759 && (currentTime - DeltaTime) < 61.9759)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 62.12855 && (currentTime - DeltaTime) < 62.12855)
	{
		spawnHiHatNode();
	}
#pragma endregion 51
#pragma region 52
	if (currentTime >= 62.2812 && (currentTime - DeltaTime) < 62.2812)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 62.43385 && (currentTime - DeltaTime) < 62.43385)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 62.5865 && (currentTime - DeltaTime) < 62.5865)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 62.73915 && (currentTime - DeltaTime) < 62.73915)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 62.8918 && (currentTime - DeltaTime) < 62.8918)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 63.04445 && (currentTime - DeltaTime) < 63.04445)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 63.1971 && (currentTime - DeltaTime) < 63.1971)
	{
		spawnHiHatNode();
	}
#pragma endregion 52
#pragma region 53
	if (currentTime >= 63.5024 && (currentTime - DeltaTime) < 63.5024)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 63.8077 && (currentTime - DeltaTime) < 63.8077)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 64.113 && (currentTime - DeltaTime) < 64.113)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 64.4183 && (currentTime - DeltaTime) < 64.4183)
	{
		spawnHiHatNode();
	}
#pragma endregion 53
#pragma region 54
	if (currentTime >= 64.7236 && (currentTime - DeltaTime) < 64.7236)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 65.0289 && (currentTime - DeltaTime) < 65.0289)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 65.3342 && (currentTime - DeltaTime) < 65.3342)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 65.6395 && (currentTime - DeltaTime) < 65.6395)
	{
		spawnHiHatNode();
	}
#pragma endregion 54
#pragma region 55
	if (currentTime >= 66.2501 && (currentTime - DeltaTime) < 66.2501)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 66.5554 && (currentTime - DeltaTime) < 66.5554)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 66.8607 && (currentTime - DeltaTime) < 66.8607)
	{
		spawnHiHatNode();
	}
#pragma endregion 55
#pragma region 56
	if (currentTime >= 67.166 && (currentTime - DeltaTime) < 67.166)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 67.4713 && (currentTime - DeltaTime) < 67.4713)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 67.7766 && (currentTime - DeltaTime) < 67.7766)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 68.0819 && (currentTime - DeltaTime) < 68.0819)
	{
		spawnHiHatNode();
	}
#pragma endregion 56
#pragma region 57
	if (currentTime >= 68.3872 && (currentTime - DeltaTime) < 68.3872)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 68.6925 && (currentTime - DeltaTime) < 68.6925)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 68.9978 && (currentTime - DeltaTime) < 68.9978)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 69.3031 && (currentTime - DeltaTime) < 69.3031)
	{
		spawnHiHatNode();
	}
#pragma endregion 57
#pragma region 58
	if (currentTime >= 69.6084 && (currentTime - DeltaTime) < 69.6084)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 69.9137 && (currentTime - DeltaTime) < 69.9137)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 70.219 && (currentTime - DeltaTime) < 70.219)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 70.5243 && (currentTime - DeltaTime) < 70.5243)
	{
		spawnHiHatNode();
	}
#pragma endregion 58
#pragma region 59
	if (currentTime >= 71.1349 && (currentTime - DeltaTime) < 71.1349)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 71.4402 && (currentTime - DeltaTime) < 71.4402)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 71.7455 && (currentTime - DeltaTime) < 71.7455)
	{
		spawnHiHatNode();
	}
#pragma endregion 59
#pragma region 60
	if (currentTime >= 72.0508 && (currentTime - DeltaTime) < 72.0508)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 72.3561 && (currentTime - DeltaTime) < 72.3561)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 72.6614 && (currentTime - DeltaTime) < 72.6614)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 72.9667 && (currentTime - DeltaTime) < 72.9667)
	{
		spawnHiHatNode();
	}
#pragma endregion 60
#pragma region 61
	if (currentTime >= 73.272 && (currentTime - DeltaTime) < 73.272)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 73.5773 && (currentTime - DeltaTime) < 73.5773)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 73.8826 && (currentTime - DeltaTime) < 73.8826)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 74.1879 && (currentTime - DeltaTime) < 74.1879)
	{
		spawnHiHatNode();
	}
#pragma endregion 61
#pragma region 67
	if (currentTime >= 80.9045 && (currentTime - DeltaTime) < 80.9045)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 81.5151 && (currentTime - DeltaTime) < 81.5151)
	{
		spawnHiHatNode();
	}
#pragma endregion 67
#pragma region 68
	if (currentTime >= 81.8204 && (currentTime - DeltaTime) < 81.8204)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 82.1257 && (currentTime - DeltaTime) < 82.1257)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 82.431 && (currentTime - DeltaTime) < 82.431)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 82.7363 && (currentTime - DeltaTime) < 82.7363)
	{
		spawnHiHatNode();
	}
#pragma endregion 68
#pragma region 69
	if (currentTime >= 83.0416 && (currentTime - DeltaTime) < 83.0416)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 83.3469 && (currentTime - DeltaTime) < 83.3469)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 83.6522 && (currentTime - DeltaTime) < 83.6522)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 83.9575 && (currentTime - DeltaTime) < 83.9575)
	{
		spawnHiHatNode();
	}
#pragma endregion 69
#pragma region 70
	if (currentTime >= 84.2628 && (currentTime - DeltaTime) < 84.2628)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 84.5681 && (currentTime - DeltaTime) < 84.5681)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 84.8734 && (currentTime - DeltaTime) < 84.8734)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 85.1787 && (currentTime - DeltaTime) < 85.1787)
	{
		spawnHiHatNode();
	}
#pragma endregion 70
#pragma region 71
	if (currentTime >= 85.484 && (currentTime - DeltaTime) < 85.484)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 85.7893 && (currentTime - DeltaTime) < 85.7893)
	{
		spawnHiHatNode();
	}
#pragma endregion 71
#pragma region 92
	if (currentTime >= 111.4345 && (currentTime - DeltaTime) < 111.4345)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 111.7398 && (currentTime - DeltaTime) < 111.7398)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 112.0451 && (currentTime - DeltaTime) < 112.0451)
	{
		spawnHiHatNode();
	}
#pragma endregion 92
#pragma region 93
	if (currentTime >= 112.3504 && (currentTime - DeltaTime) < 112.3504)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 112.6557 && (currentTime - DeltaTime) < 112.6557)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 112.961 && (currentTime - DeltaTime) < 112.961)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 113.2663 && (currentTime - DeltaTime) < 113.2663)
	{
		spawnHiHatNode();
	}
#pragma endregion 93
#pragma region 94
	if (currentTime >= 113.5716 && (currentTime - DeltaTime) < 113.5716)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 113.8769 && (currentTime - DeltaTime) < 113.8769)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 114.1822 && (currentTime - DeltaTime) < 114.1822)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 114.4875 && (currentTime - DeltaTime) < 114.4875)
	{
		spawnHiHatNode();
	}
#pragma endregion 94
#pragma region 95
	if (currentTime >= 114.7928 && (currentTime - DeltaTime) < 114.7928)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 115.0981 && (currentTime - DeltaTime) < 115.0981)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 115.55605 && (currentTime - DeltaTime) < 115.55605)
	{
		spawnHiHatNode();
	}
#pragma endregion 95
#pragma region 96
	if (currentTime >= 116.3193 && (currentTime - DeltaTime) < 116.3193)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 116.6246 && (currentTime - DeltaTime) < 116.6246)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 116.9299 && (currentTime - DeltaTime) < 116.9299)
	{
		spawnHiHatNode();
	}
#pragma endregion 96
#pragma region 97
	if (currentTime >= 117.2352 && (currentTime - DeltaTime) < 117.2352)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 117.5405 && (currentTime - DeltaTime) < 117.5405)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 117.8458 && (currentTime - DeltaTime) < 117.8458)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 118.1511 && (currentTime - DeltaTime) < 118.1511)
	{
		spawnHiHatNode();
	}
#pragma endregion 97
#pragma region 98
	if (currentTime >= 118.4564 && (currentTime - DeltaTime) < 118.4564)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 118.7617 && (currentTime - DeltaTime) < 118.7617)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 119.067 && (currentTime - DeltaTime) < 119.067)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 119.3723 && (currentTime - DeltaTime) < 119.3723)
	{
		spawnHiHatNode();
	}
#pragma endregion 98
#pragma region 99
	if (currentTime >= 119.6776 && (currentTime - DeltaTime) < 119.6776)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 119.9829 && (currentTime - DeltaTime) < 119.9829)
	{
		spawnHiHatNode();
	}
#pragma endregion 99
#pragma region 100
	if (currentTime >= 121.5094 && (currentTime - DeltaTime) < 121.5094)
	{
		spawnHiHatNode();
	}
#pragma endregion 100
#pragma region 101
	if (currentTime >= 122.7306 && (currentTime - DeltaTime) < 122.7306)
	{
		spawnHiHatNode();
	}
#pragma endregion 101
#pragma region 102
	if (currentTime >= 123.9518 && (currentTime - DeltaTime) < 123.9518)
	{
		spawnHiHatNode();
	}
#pragma endregion 102
#pragma region 103
	if (currentTime >= 125.4783 && (currentTime - DeltaTime) < 125.4783)
	{
		spawnHiHatNode();
	}
#pragma endregion 103
#pragma region 107
	if (currentTime >= 129.4472 && (currentTime - DeltaTime) < 129.4472)
	{
		spawnHiHatNode();
	}
#pragma endregion 107
#pragma region 112
	if (currentTime >= 135.8585 && (currentTime - DeltaTime) < 135.8585)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 136.4691 && (currentTime - DeltaTime) < 136.4691)
	{
		spawnHiHatNode();
	}
#pragma endregion 112
#pragma region 116
	if (currentTime >= 140.59065 && (currentTime - DeltaTime) < 140.59065)
	{
		spawnHiHatNode();
	}
#pragma endregion 116
#pragma region 120
	if (currentTime >= 145.6281 && (currentTime - DeltaTime) < 145.6281)
	{
		spawnHiHatNode();
	}
	if (currentTime >= 146.2387 && (currentTime - DeltaTime) < 146.2387)
	{
		spawnHiHatNode();
	}
#pragma endregion 120
#pragma region 125
	if (currentTime >= 151.7341 && (currentTime - DeltaTime) < 151.7341)
	{
		spawnHiHatNode();
	}
#pragma endregion 125


}

void AOSY_HiHatFactory::spawnHiHatNode()
{
	// 생성위치
	FVector FactoryLoc = GetActorLocation();

	GetWorld()->SpawnActor<AOSY_NodeActor>(NodeFactory, FactoryLoc, FRotator::ZeroRotator);
}

