#pragma once

#include "Enemy.h"

/**
 * @brief Represents a specific type of enemy (EnemyTypeA).
 */
class EnemyTypeA :
    public Enemy
{
private:
    short turnBackCounter; /**< Counter for turning back behavior. */

    /**
     * @brief Initializes specific variables for EnemyTypeA.
     */
    void initVariables() override;

    /**
     * @brief Initializes the texture for EnemyTypeA.
     */
    void initTexture() override;

    /**
     * @brief Initializes the sprite for EnemyTypeA.
     */
    void initSprite() override;

    /**
     * @brief Updates animations for EnemyTypeA.
     */
    void updateAnimations() override;

    /**
     * @brief Updates movement for EnemyTypeA.
     */
    void updateMovement() override;

public:
    /**
     * @brief Constructs an EnemyTypeA object.
     */
    EnemyTypeA();

    /**
     * @brief Updates EnemyTypeA.
     */
    void update();
};


