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
 * @brief Class responsible for managing the game world.
 */
class World
{
private:
	Camera camera; /**< Camera object for controlling the view of the world. */
	std::vector<std::unique_ptr<Entity>> entities; /**< Vector containing entities in the world. */
	sf::Vector2f playerStartPosition; /**< Starting position for the player entity. */
	std::vector<std::unique_ptr<Bullet>> bullets; /**< Vector containing bullets fired in the world. */
	sf::Texture bulletTexture; /**< Texture used for rendering bullets. */
	TileMap tileMap; /**< TileMap object representing the game's environment. */

	/**
	 * @brief Initializes variables and entities in the world.
	 */
	void initVariables();

	/**
	 * @brief Initializes entities present in the world.
	 */
	void initEntities();

	/**
	 * @brief Updates the entities in the world.
	 */
	void updateEntities();

	/**
	 * @brief Shoots bullets in the world.
	 */
	void shootBullets();

	/**
	 * @brief Updates the bullets in the world.
	 */
	void updateBullets();

	/**
	 * @brief Renders bullets on the screen.
	 * @param target The target to render bullets onto.
	 */
	void renderBullets(sf::RenderTarget& target);

	/**
	 * @brief Renders entities on the screen.
	 * @param target The target to render entities onto.
	 */
	void renderEntities(sf::RenderTarget& target);

public:
	// Constructors

	/**
	 * @brief Default constructor for the World class.
	 */
	World();

	/**
	 * @brief Retrieves the player entity in the world.
	 * @return Reference to the player entity.
	 */
	Player& getPlayer();

	/**
	 * @brief Retrieves the camera object in the world.
	 * @return Reference to the camera object.
	 */
	Camera& getCamera();

	/**
	 * @brief Updates collisions in the world.
	 */
	void updateCollisions();

	/**
	 * @brief Updates physics in the world.
	 */
	void updatePhysics();

	/**
	 * @brief Updates the world.
	 */
	void update();

	/**
	 * @brief Renders the world onto the target.
	 * @param target The target to render the world onto.
	 */
	void render(sf::RenderTarget& target);

	/**
	 * @brief Retrieves the vector of entities in the world.
	 * @return Reference to the vector of entities.
	 */
	std::vector<std::unique_ptr<Entity>>& getEntities();
};


