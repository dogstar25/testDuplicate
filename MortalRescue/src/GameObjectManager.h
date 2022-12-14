#pragma once
#include <stdio.h>
#include <string>
#include <map>


#include "GameObjectDefinition.h"
#include "TextObject.h"



using namespace std;

class GameObjectManager
{
public:
		
	static GameObjectManager& instance();

	bool init();
	void load(string);

	GameObjectDefinition* getDefinition(string);

	//Map of the definitions of all posible game objects in the game/level
	map<string, GameObjectDefinition*> gameObjectDefinitions;
	
	/*
	Template function that builds any type of GameObject that you pass it
	Has to be inline because its a templated function
	*/
	template <typename gameObjectType>
	inline gameObjectType* buildGameObject(string gameObjectId, float xMapPos, float yMapPos, float angle)
	{

		gameObjectType* gameObject = new gameObjectType(gameObjectId, xMapPos, yMapPos, angle);

		//string test = typeid(gameObject).name();
		return gameObject;
	}

private:
	GameObjectManager();
	~GameObjectManager();

	
};

