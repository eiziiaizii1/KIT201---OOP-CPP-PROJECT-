#pragma once
#include "Entity.h" // Include the base class header
#include "Camera.h"
//#include 

/**
 * @brief Represents the player entity inheriting from Entity class.
 */
class Player : public Entity {
private:
    float lookDirection; /**< Direction the player is looking at. */
    sf::Vector2f startPosition; /**< Starting position of the player. */

    // Shooting variables could potentially be moved to a ShooterEntity subclass.

    bool canShoot; /**< Flag indicating if the player can shoot. */
    sf::Clock shootClock; /**< Clock managing shooting intervals. */

    // Implementations of abstract methods
    void initVariables() override;
    void initTexture() override;
    void initSprite() override;

    /**
     * @brief Updates the shoot status based on mouse input.
     * Updates the canShoot status based on left click.
     */
    void updateShootStatus();

    void updateAnimations() override;
    void updateMovement() override;

public:
    // Constructors - Destructor

    /**
     * @brief Default constructor for Player class.
     */
    Player();

    /**
     * @brief Destructor for Player class.
     */
    ~Player();

    /**
     * @brief Gets the canShoot status.
     * @return true if the player can shoot, false otherwise.
     */
    const bool getCanShoot();

    /**
     * @brief Gets the direction the player is looking at.
     * @return Direction in degrees.
     */
    const float getLookDirection();

    /**
     * @brief Revives the player at a specified position.
     * @param startPos The position to revive the player at.
     */
    void revive(sf::Vector2f& startPos);

    /**
     * @brief Checks if the entity is an enemy.
     * @return false as the Player is not an enemy.
     */
    const bool isEnemy() override;

    /**
     * @brief Updates the player entity.
     */
    void update() override;
};


