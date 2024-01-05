#pragma once
#include "SFML\Graphics.hpp"
#include "Entity.h"
#include "TileMap.h"
#include "Bullet.h"
#include "Enemy.h"
#include "PhysicsManager.h"

const sf::FloatRect tileBounds = sf::FloatRect(0.f, 0.f, 64.f, 64.f);

class CollisionManager
{
private:

	static void handleBottomCollisions(Entity& entity, std::vector<std::vector<short>>& tileMap, short leftTopY, short leftBottomY);

	static void handleTopCollisions(Entity& entity, std::vector<std::vector<short>>& tileMap, bool& topCollided,
							 short leftTopX, short leftTopY, short rightTopX, short rightTopY, short midTopX, short midTopY);
	
	static void handleLeftCollisions(Entity& entity, std::vector<std::vector<short>>& tileMap, short leftBottomX, short leftBottomY, short leftTopX, short leftTopY);
	
	static void handleRightCollisions(Entity& entity, std::vector<std::vector<short>>& tileMap,
							   short rightTopX, short rightTopY, short rightBottomX, short rightBottomY);

public:
	CollisionManager(TileMap& tileMap);
	
	// Handles collisions between bullets and entities
	static void handleCollisions(std::vector<std::unique_ptr<Bullet>>& bullets, std::vector<std::unique_ptr<Entity>>& entities);

	// Handles collisions between player and entities
	static void handleCollisions(std::vector<std::unique_ptr<Entity>>& entities);

	// Handles collisions between tile map and entities
	static void handleCollisions(Entity& entity, TileMap& tileMap);
};

