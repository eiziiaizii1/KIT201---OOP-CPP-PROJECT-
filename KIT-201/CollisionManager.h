#pragma once
#include "SFML\Graphics.hpp"
#include "Player.h"
#include "TileMap.h"

class CollisionManager
{
private:
	sf::FloatRect tileBounds;


	void handleBottomCollisions(Player& player, std::vector<std::vector<short>>& tileMap,
		short leftTopY, short leftBottomX, short leftBottomY, short rightBottomX, short rightBottomY, short midBottomX, short midBottomY);

	void handleTopCollisions(Player& player, std::vector<std::vector<short>>& tileMap, bool& topCollided,
							 short leftTopX, short leftTopY, short rightTopX, short rightTopY, short midTopX, short midTopY);
	
	void handleLeftCollisions(Player& player, std::vector<std::vector<short>>& tileMap, short leftBottomX, short leftBottomY, short leftTopX, short leftTopY);
	
	void handleRightCollisions(Player& player, std::vector<std::vector<short>>& tileMap, 
							   short rightTopX, short rightTopY, short rightBottomX, short rightBottomY);

public:
	CollisionManager(TileMap& tileMap);


	void handleCollisions(Player& player, TileMap& tileMap);
};

