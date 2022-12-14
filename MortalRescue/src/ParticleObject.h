#pragma once
#include "WorldObject.h"

#include <string>
#include <chrono>

class WorldObject;

using namespace std::chrono;

class ParticleObject :
	public WorldObject
{
public:
	ParticleObject();
	ParticleObject(string, float, float, float);
	~ParticleObject();

	void update();
	void render();

	duration<float, milli> lifetime;
	duration<float, milli> lifetimeRemaining;
	bool isLifetimeAlphaFade;
	bool hasInfiniteLifetime;
	bool isAvailable;
	string poolId;

	steady_clock::time_point time_snapshot;

};

