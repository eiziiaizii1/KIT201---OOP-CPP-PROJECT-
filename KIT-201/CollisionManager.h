#pragma once
#include "SFML\Graphics.hpp"
#include "Player.h"
#include "TileMap.h"

class CollisionManager
{
private:
	sf::FloatRect tileBounds;


	void handleBottomCollisions(Entity& player, std::vector<std::vector<short>>& tileMap, short leftTopY, short leftBottomY);

	void handleTopCollisions(Entity& player, std::vector<std::vector<short>>& tileMap, bool& topCollided,
							 short leftTopX, short leftTopY, short rightTopX, short rightTopY, short midTopX, short midTopY);
	
	void handleLeftCollisions(Entity& player, std::vector<std::vector<short>>& tileMap, short leftBottomX, short leftBottomY, short leftTopX, short leftTopY);
	
	void handleRightCollisions(Entity& player, std::vector<std::vector<short>>& tileMap,
							   short rightTopX, short rightTopY, short rightBottomX, short rightBottomY);

public:
	CollisionManager(TileMap& tileMap);


	void handleCollisions(Entity& player, TileMap& tileMap);
};

