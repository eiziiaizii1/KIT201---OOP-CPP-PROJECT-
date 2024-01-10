#pragma once

#include "SFML\Graphics.hpp"
#include "Entity.h"
#include "TileMap.h"
#include "Bullet.h"
#include "Enemy.h"
#include "PhysicsManager.h"

/**
 * @brief Handles the collisions for the game.
 */
const sf::FloatRect tileBounds = sf::FloatRect(0.f, 0.f, 64.f, 64.f);

class CollisionManager
{
private:

	/**
	 * @brief Handles collisions at the bottom of the entity.
	 * @param entity The entity for collision handling.
	 * @param tileMap The tile map representing the environment.
	 * @param leftTopY The Y-coordinate at the left top of the entity.
	 *
	 */
	static void handleBottomCollisions(Entity& entity, std::vector<std::vector<short>>& tileMap, short leftTopY, short leftBottomY);

	/**
	 * @brief Handles collisions at the top of the entity.
	 * @param entity The entity for collision handling.
	 * @param tileMap The tile map representing the environment.
	 * @param topCollided Indicates if collision occurred at the top.
	 * @param leftTopX The X-coordinate at the left top of the entity.
	 * @param leftTopY The Y-coordinate at the left top of the entity.
	 * @param rightTopX The X-coordinate at the right top of the entity.
	 * @param rightTopY The Y-coordinate at the right top of the entity.
	 */
	static void handleTopCollisions(Entity& entity, std::vector<std::vector<short>>& tileMap, bool& topCollided,
		short leftTopX, short leftTopY, short rightTopX, short rightTopY);

	/**
	 * @brief Handles collisions on the left side of the entity.
	 * @param entity The entity for collision handling.
	 * @param tileMap The tile map representing the environment.
	 * @param leftBottomX The X-coordinate at the left bottom of the entity.
	 * @param leftBottomY The Y-coordinate at the left bottom of the entity.
	 * @param leftTopX The X-coordinate at the left top of the entity.
	 * @param leftTopY The Y-coordinate at the left top of the entity.
	 */
	static void handleLeftCollisions(Entity& entity, std::vector<std::vector<short>>& tileMap, short leftBottomX, short leftBottomY, short leftTopX, short leftTopY);

	/**
	 * @brief Handles collisions on the right side of the entity.
	 * @param entity The entity for collision handling.
	 * @param tileMap The tile map representing the environment.
	 * @param rightTopX The X-coordinate at the right top of the entity.
	 * @param rightTopY The Y-coordinate at the right top of the entity.
	 * @param rightBottomX The X-coordinate at the right bottom of the entity.
	 * @param rightBottomY The Y-coordinate at the right bottom of the entity.
	 */
	static void handleRightCollisions(Entity& entity, std::vector<std::vector<short>>& tileMap,
		short rightTopX, short rightTopY, short rightBottomX, short rightBottomY);

public:

	/**
	 * @brief Constructs a CollisionManager object.
	 * @param tileMap The tile map representing the environment.
	 */
	CollisionManager(TileMap& tileMap);

	/**
	 * @brief Handles collisions between bullets and entities.
	 * @param bullets The vector containing bullets.
	 * @param entities The vector containing entities.
	 */
	static void handleCollisions(std::vector<std::unique_ptr<Bullet>>& bullets, std::vector<std::unique_ptr<Entity>>& entities);

	/**
	 * @brief Handles collisions between player and entities.
	 * @param entities The vector containing entities.
	 */
	static void handleCollisions(std::vector<std::unique_ptr<Entity>>& entities);

	/**
	 * @brief Handles collisions between the tile map and entities.
	 * @param entity The entity for collision handling.
	 * @param tileMap The tile map representing the environment.
	 */
	static void handleCollisions(Entity& entity, TileMap& tileMap);
};

