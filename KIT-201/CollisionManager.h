#pragma once
#include "SFML\Graphics.hpp"
#include "Entity.h"
#include "TileMap.h"
#include "Bullet.h"
#include "Enemy.h"

class CollisionManager
{
private:
	sf::FloatRect tileBounds;


	void handleBottomCollisions(Entity& entity, std::vector<std::vector<short>>& tileMap, short leftTopY, short leftBottomY);

	void handleTopCollisions(Entity& entity, std::vector<std::vector<short>>& tileMap, bool& topCollided,
							 short leftTopX, short leftTopY, short rightTopX, short rightTopY, short midTopX, short midTopY);
	
	void handleLeftCollisions(Entity& entity, std::vector<std::vector<short>>& tileMap, short leftBottomX, short leftBottomY, short leftTopX, short leftTopY);
	
	void handleRightCollisions(Entity& entity, std::vector<std::vector<short>>& tileMap,
							   short rightTopX, short rightTopY, short rightBottomX, short rightBottomY);

public:
	CollisionManager(TileMap& tileMap);

	//void handleBulletEnemyCollisions (std::vector<std::unique_ptr<Bullet>>& bullets, std::vector<std::unique_ptr<Enemy>>& enemies);

	void handleCollisions(std::vector<std::unique_ptr<Bullet>>& bullets, std::vector<std::unique_ptr<Entity>>& entities);

	void handleCollisions(Entity& player, TileMap& tileMap);
};

