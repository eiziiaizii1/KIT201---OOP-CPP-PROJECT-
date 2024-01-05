#pragma once
#include "Entity.h"

/**
 * @brief Manages the physics behavior of entities.
 */
class PhysicsManager
{

public:
	/**
	 * @brief Default constructor for PhysicsManager class.
	 */
	PhysicsManager();

	/**
	 * @brief Applies acceleration to the entity.
	 * @param entity The entity to apply acceleration to.
	 */
	static void applyAcceleration(Entity& entity);

	/**
	 * @brief Applies drag to the entity.
	 * @param entity The entity to apply drag to.
	 */
	static void applyDrag(Entity& entity);

	/**
	 * @brief Applies gravity to the entity.
	 * @param entity The entity to apply gravity to.
	 */
	static void applyGravity(Entity& entity);

	/**
	 * @brief Limits the velocity of the entity.
	 * @param entity The entity to limit velocity for.
	 */
	static void limitVelocity(Entity& entity);

	/**
	 * @brief Sets a minimum velocity for the entity.
	 * @param entity The entity to limit the minimum velocity for.
	 */
	static void limitMinimumVelocity(Entity& entity);

	/**
	 * @brief Handles jumping for the entity, fixing BUG1.
	 * @param entity The entity to handle jumping for.
	 */
	static void handleJumping(Entity& entity);

	/**
	 * @brief Adds force to the entity.
	 * @param entity The entity to add force to.
	 * @param amountX The force on the X-axis.
	 * @param amountY The force on the Y-axis.
	 */
	static void addForce(Entity& entity, float amountX, float amountY);

	/**
	 * @brief Updates the entity's physics state.
	 * @param entity The entity to update physics for.
	 */
	static void update(Entity& entity);
};

// BUGFIX: Fixed issue where jumping near walls caused super jump (BUG1)
// BUGFIX: Fixed issue where jumping while falling down allowed jumping in mid-air (BUG2)
