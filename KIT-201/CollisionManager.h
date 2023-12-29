#pragma once
#include "SFML\Graphics.hpp"
#include "Player.h"
#include "TileMap.h"

class CollisionManager
{
private:
	sf::FloatRect tileBounds;
public:
	CollisionManager();
	CollisionManager(TileMap& tileMap);
	~CollisionManager();

	void handleCollisions(Player& player, TileMap& tileMap);
};

