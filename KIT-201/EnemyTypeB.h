#pragma once
#include "Enemy.h"

/**
 * @brief Represents an Enemy of type B, inheriting from Enemy class.
 */
class EnemyTypeB :
    public Enemy
{
private:
    sf::Clock moveClock;
    sf::IntRect spriteFrameRun; // Different sizes for run and idle texture-sheets, requiring another spriteFrame

    /**
     * @brief Initializes the variables for EnemyTypeB.
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
     * @brief Updates the animations for EnemyTypeB.
     */
    void updateAnimations() override;

    /**
     * @brief Updates the movement for EnemyTypeB.
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


