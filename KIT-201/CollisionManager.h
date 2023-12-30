#pragma once
#include "SFML\Graphics.hpp"
#include "Player.h"
#include "TileMap.h"

class CollisionManager
{
private:
	sf::FloatRect tileBounds;


	void handleBottomCollisions(Player& player, std::vector<std::vector<short>>& tileMap);
	void handleTopCollisions(Player& player, std::vector<std::vector<short>>& tileMap);
	void handleLeftCollisions(Player& player, std::vector<std::vector<short>>& tileMap);
	void handleRightCollisions(Player& player, std::vector<std::vector<short>>& tileMap);

public:
	CollisionManager(TileMap& tileMap);


	void handleCollisions(Player& player, TileMap& tileMap);
};

