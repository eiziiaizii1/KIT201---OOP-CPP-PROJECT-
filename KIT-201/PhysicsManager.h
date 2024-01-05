#pragma once

#include "Entity.h"

/**
 * @brief Manages physics-related operations for entities.
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
     *
     * @param entity The entity to apply acceleration to.
     */
    static void applyAcceleration(Entity& entity);

    /**
     * @brief Applies drag to the entity.
     *
     * @param entity The entity to apply drag to.
     */
    static void applyDrag(Entity& entity);

    /**
     * @brief Applies gravity to the entity.
     *
     * @param entity The entity to apply gravity to.
     */
    static void applyGravity(Entity& entity);

    /**
     * @brief Limits the velocity of the entity.
     *
     * @param entity The entity to limit the velocity of.
     */
    static void limitVelocity(Entity& entity);

    /**
     * @brief Limits the minimum velocity of the entity.
     *
     * @param entity The entity to limit the minimum velocity of.
     */
    static void limitMinimumVelocity(Entity& entity);

    /**
     * @brief Handles jumping for the entity.
     *
     * @param entity The entity to handle jumping for.
     */
    static void handleJumping(Entity& entity);

    /**
     * @brief Adds force to the entity in specified amounts along x and y axes.
     *
     * @param entity The entity to add force to.
     * @param amountX The amount of force along the x-axis.
     * @param amountY The amount of force along the y-axis.
     */
    static void addForce(Entity& entity, float amountX, float amountY);

    /**
     * @brief Updates the physics for the entity.
     *
     * @param entity The entity to update physics for.
     */
    static void update(Entity& entity);
};

