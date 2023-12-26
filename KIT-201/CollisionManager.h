#pragma once
#include "Player.h"
#include "TileMap.h"

class CollisionManager
{
private:

public:
	CollisionManager();
	~CollisionManager();

	void handleCollisions(Player& player, TileMap& tileMap);
};

