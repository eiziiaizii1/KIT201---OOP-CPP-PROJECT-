#pragma once
#include "Player.h"
#include "TileMap.h"

class CollisionManager
{
private:

public:
	CollisionManager();
	~CollisionManager();

	static void handleCollisions(Player& player, TileMap& tileMap);
};

