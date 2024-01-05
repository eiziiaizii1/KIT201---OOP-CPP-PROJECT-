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
     * @return true as this is an enemy entity.
     */
    virtual const bool isEnemy();
};

