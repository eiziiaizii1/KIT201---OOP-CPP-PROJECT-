#pragma once

#include "SFML\Graphics.hpp"
#include "Player.h"

/**
 * @brief Represents a bullet entity.
 */
class Bullet {
private:
    sf::Sprite sprite; /**< Sprite for the bullet. */
    bool toBeDestroyed; /**< Flag indicating if the bullet needs to be destroyed. */
    int damage; /**< Damage inflicted by the bullet. */

    float direction; /**< Direction that the bullet will move on the x-axis (1.f = right, -1.f = left). */
    float movementSpeed; /**< Speed at which the bullet moves. */

public:
    /**
     * @brief Constructs a Bullet object.
     *
     * @param texture Texture for the bullet.
     * @param player Reference to the player firing the bullet.
     */
    Bullet(sf::Texture& texture, Player& player);

    /**
     * @brief Destroys the Bullet object.
     */
    ~Bullet();

    // Getters
    const sf::FloatRect& getGlobalBounds();
    const int getDamage();
    const bool getToBeDestroyed();
    const sf::Vector2f& getPosition();

    // Setters
    void setToBeDestroyed(bool destroyStatus);

    /**
     * @brief Updates the bullet's position and behavior.
     */
    void update();

    /**
     * @brief Renders the bullet.
     *
     * @param target The render target to draw the bullet on.
     */
    void render(sf::RenderTarget& target);
};

