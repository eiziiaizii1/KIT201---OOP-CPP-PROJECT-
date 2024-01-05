#pragma once
#include "Entity.h"
#include "Enemy.h"
#include "TileMap.h"
#include "CollisionManager.h"
#include "PhysicsManager.h"
#include "Camera.h"
#include "Bullet.h"
#include "EnemyTypeA.h"
#include "EnemyTypeB.h"

/**
 * The World class manages the game world and entities within it.
 */
class World {
private:
    Camera camera;

    // Collection of entities
    // Index 0 represents the player, other indices represent enemies
    std::vector<std::unique_ptr<Entity>> entities;

    // Collection of bullets
    std::vector<std::unique_ptr<Bullet>> bullets;
    sf::Texture bulletTexture;

    TileMap tileMap;

    /**
     * Initializes internal variables.
     */
    void initVariables();

    /**
     * Initializes the entities in the world.
     */
    void initEntities();

    /**
     * Updates the entities in the world.
     */
    void updateEntities();

    /**
     * Handles shooting bullets.
     */
    void shootBullets();

    /**
     * Updates the bullets.
     */
    void updateBullets();

    /**
     * Renders the bullets on the target.
     * @param target The rendering target.
     */
    void renderBullets(sf::RenderTarget& target);

    /**
     * Renders the entities on the target.
     * @param target The rendering target.
     */
    void renderEntities(sf::RenderTarget& target);

public:
    // Constructors
    World();

    /**
     * Retrieves a reference to the player entity.
     * @return A reference to the player entity.
     */
    Player& getPlayer();

    /**
     * Retrieves a reference to the camera.
     * @return A reference to the camera.
     */
    Camera& getCamera();

    /**
     * Updates collision handling for entities.
     */
    void updateCollisions();

    /**
     * Updates physics in the world.
     */
    void updatePhysics();

    /**
     * Updates the world.
     */
    void update();

    /**
     * Renders the world on the target.
     * @param target The rendering target.
     */
    void render(sf::RenderTarget& target);

    /**
     * Retrieves the collection of entities.
     * @return A reference to the collection of entities.
     */
    std::vector<std::unique_ptr<Entity>>& getEntities();
};


