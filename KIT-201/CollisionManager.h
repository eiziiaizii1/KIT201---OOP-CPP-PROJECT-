#pragma once

#include "SFML\Graphics.hpp"
#include "Entity.h"
#include "TileMap.h"
#include "Bullet.h"
#include "Enemy.h"
#include "PhysicsManager.h"

/**
 * @brief Manages collisions between entities and the environment.
 */
class CollisionManager
{
private:
    /**
     * @brief Handles collisions at the bottom of the entity.
     *
     * @param entity The entity to handle collisions for.
     * @param tileMap The tile map representing the environment.
     * @param leftTopY The y-coordinate of the top left corner.
     * @param leftBottomY The y-coordinate of the bottom left corner.
     */
    static void handleBottomCollisions(Entity& entity, std::vector<std::vector<short>>& tileMap, short leftTopY, short leftBottomY);

    /**
     * @brief Handles collisions at the top of the entity.
     *
     * @param entity The entity to handle collisions for.
     * @param tileMap The tile map representing the environment.
     * @param topCollided A flag indicating if collision occurred at the top.
     * @param leftTopX The x-coordinate of the top left corner.
     * @param leftTopY The y-coordinate of the top left corner.
     * @param rightTopX The x-coordinate of the top right corner.
     * @param rightTopY The y-coordinate of the top right corner.
     * @param midTopX The x-coordinate of the top center.
     * @param midTopY The y-coordinate of the top center.
     */
    static void handleTopCollisions(Entity& entity, std::vector<std::vector<short>>& tileMap, bool& topCollided,
        short leftTopX, short leftTopY, short rightTopX, short rightTopY, short midTopX, short midTopY);

    /**
     * @brief Handles collisions on the left side of the entity.
     *
     * @param entity The entity to handle collisions for.
     * @param tileMap The tile map representing the environment.
     * @param leftBottomX The x-coordinate of the bottom left corner.
     * @param leftBottomY The y-coordinate of the bottom left corner.
     * @param leftTopX The x-coordinate of the top left corner.
     * @param leftTopY The y-coordinate of the top left corner.
     */
    static void handleLeftCollisions(Entity& entity, std::vector<std::vector<short>>& tileMap, short leftBottomX, short leftBottomY, short leftTopX, short leftTopY);

    /**
     * @brief Handles collisions on the right side of the entity.
     *
     * @param entity The entity to handle collisions for.
     * @param tileMap The tile map representing the environment.
     * @param rightTopX The x-coordinate of the top right corner.
     * @param rightTopY The y-coordinate of the top right corner.
     * @param rightBottomX The x-coordinate of the bottom right corner.
     * @param rightBottomY The y-coordinate of the bottom right corner.
     */
    static void handleRightCollisions(Entity& entity, std::vector<std::vector<short>>& tileMap,
        short rightTopX, short rightTopY, short rightBottomX, short rightBottomY);

public:
    /**
     * @brief Constructs a CollisionManager object.
     *
     * @param tileMap Reference to the TileMap used for collisions.
     */
    CollisionManager(TileMap& tileMap);

    /**
     * @brief Handles collisions between bullets and entities.
     *
     * @param bullets Vector containing unique pointers to Bullet objects.
     * @param entities Vector containing unique pointers to Entity objects.
     */
    static void handleCollisions(std::vector<std::unique_ptr<Bullet>>& bullets, std::vector<std::unique_ptr<Entity>>& entities);

    /**
     * @brief Handles collisions among entities.
     *
     * @param entities Vector containing unique pointers to Entity objects.
     */
    static void handleCollisions(std::vector<std::unique_ptr<Entity>>& entities);

    /**
     * @brief Handles collisions between an entity and the tile map.
     *
     * @param entity The entity to handle collisions for.
     * @param tileMap Reference to the TileMap used for collisions.
     */
    static void handleCollisions(Entity& entity, TileMap& tileMap);
};

