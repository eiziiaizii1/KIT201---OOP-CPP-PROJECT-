#pragma once

#include "Enemy.h"

/**
 * @brief Represents an Enemy of Type B.
 */
class EnemyTypeB :
    public Enemy
{
private:
    sf::Clock moveClock; /**< Clock for managing movement. */
    sf::IntRect spriteFrameRun; /**< Rectangle for sprite frame with different texture sheet sizes. */

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

    // Optional: add method descriptions when implemented
    //void dealDamage(int damage, Bullet& player) override;

    /**
     * @brief Updates EnemyTypeB.
     */
    void update();
};


