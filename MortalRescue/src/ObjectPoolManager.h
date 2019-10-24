#pragma once
#include <string>
#include <map>
#include <vector>

class ParticleObject;

using namespace::std;

class ObjectPoolManager
{
public:
	ObjectPoolManager();
	~ObjectPoolManager();
	void init();
	void reset(shared_ptr<ParticleObject> particle);

	shared_ptr<ParticleObject> get(string);
	map <string, vector<shared_ptr<ParticleObject>>> objectPool;

};

