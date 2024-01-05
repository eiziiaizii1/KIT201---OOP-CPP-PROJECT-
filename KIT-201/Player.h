#pragma once

#include "Entity.h" // Include the base class header
#include "Camera.h"

/**
 * @brief Represents the player entity.
 */
class Player : public Entity {
private:
    float lookDirection; /**< Direction the player is looking at. */

    // Shooting variables could be moved to a ShooterEntity class, which is a subclass of Entity

    bool canShoot; /**< Indicates if the player can shoot. */
    sf::Clock shootClock; /**< Clock for shooting cooldown. */

    // Implementations of abstract methods
    void initVariables() override;
    void initTexture() override;
    void initSprite() override;

    /**
     * @brief Updates the shoot status based on left click.
     */
    void updateShootStatus();

    /**
     * @brief Updates animations for the player.
     */
    void updateAnimations() override;

    /**
     * @brief Updates movement for the player.
     */
    void updateMovement() override;

public:
    // Constructors - Destructor
    Player();
    ~Player();

    // Getter methods
    const bool getCanShoot();
    const float getLookDirection();

    // Method for identification
    const bool isEnemy() override;

    /**
     * @brief Updates the player entity.
     */
    void update() override;
};
