#pragma once

#include "Enemy.h"

/**
 * @brief Represents an Enemy of Type A.
 */
class EnemyTypeA :
    public Enemy
{
private:
    short turnBackCounter; /**< Counter for turning back. */
    bool turnBackBoolean; /**< Boolean for turning back. */

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


