#pragma once
#include "Entity.h"

/**
 * @brief Manages the physics of entities.
 */
class PhysicsManager
{

public:
	/**
	 * @brief Constructs a PhysicsManager object.
	 */
	PhysicsManager();

	/**
	 * @brief Applies acceleration to the entity.
	 * @param entity The entity to which acceleration is applied.
	 */
	static void applyAcceleration(Entity& entity);

	/**
	 * @brief Applies drag to the entity.
	 * @param entity The entity to which drag is applied.
	 */
	static void applyDrag(Entity& entity);

	/**
	 * @brief Limits the velocity of the entity.
	 * @param entity The entity whose velocity is limited.
	 */
	static void limitVelocity(Entity& entity);

	/**
	 * @brief Limits the minimum velocity of the entity.
	 * @param entity The entity whose minimum velocity is limited.
	 */
	static void limitMinimumVelocity(Entity& entity);

	/**
	 * @brief Handles the jumping behavior of the entity.
	 * @param entity The entity for which jumping behavior is handled.
	 */
	static void handleJumping(Entity& entity);

	/**
	 * @brief Adds force to the entity.
	 * @param entity The entity to which force is added.
	 * @param amountX The amount of force on the X-axis.
	 * @param amountY The amount of force on the Y-axis.
	 */
	static void addForce(Entity& entity, float amountX, float amountY);

	/**
	 * @brief Updates the physics for the entity.
	 * @param entity The entity for which physics are updated.
	 */
	static void update(Entity& entity);
};

