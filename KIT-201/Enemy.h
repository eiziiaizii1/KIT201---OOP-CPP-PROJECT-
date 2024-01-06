#pragma once

#include "Entity.h"
#include "Bullet.h"

/**
 * @brief Represents an enemy entity.
 */
class Enemy :
    public Entity
{
protected:
    int damage; /**< Damage inflicted by the enemy. */

public:
    /**
     * @brief Indicates if the entity is an enemy.
     *
     * @return true if the entity is an enemy.
     */
    virtual const bool isEnemy();

    /**
     * @brief Gets the damage inflicted by the enemy.
     *
     * @return The damage value.
     */
    virtual const int getDamage();
};


