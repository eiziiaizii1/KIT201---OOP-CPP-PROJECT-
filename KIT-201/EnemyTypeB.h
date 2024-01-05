#pragma once

#include "Enemy.h"

/**
 * @brief Represents another type of enemy (EnemyTypeB).
 */
class EnemyTypeB :
    public Enemy
{
private:
    sf::Clock moveClock; /**< Clock for movement timing. */
    sf::IntRect spriteFrameRun; /**< Different sized texture sheet frame for animations. */

    /**
     * @brief Initializes specific variables for EnemyTypeB.
     */
    void initVariables() override;

    /**
     * @brief Initializes the texture for EnemyTypeB.
     */
    void initTexture() override;

    /**
     * @brief Initializes the sprite for EnemyTypeB.
     */
    void initSprite() override;

    /**
     * @brief Updates animations for EnemyTypeB.
     */
    void updateAnimations() override;

    /**
     * @brief Updates movement for EnemyTypeB.
     */
    void updateMovement() override;

public:
    /**
     * @brief Constructs an EnemyTypeB object.
     */
    EnemyTypeB();

    /**
     * @brief Updates EnemyTypeB.
     */
    void update();
};


