#pragma once
#include "SFML\Graphics.hpp"
#include "Player.h"
#include "TileMap.h"

class CollisionManager
{
private:

public:
	CollisionManager();
	~CollisionManager();

	void handleCollisions(Entity& player, TileMap& tileMap);
};

