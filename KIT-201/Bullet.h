#pragma once
#include "SFML\Graphics.hpp"
#include "Player.h"

/**
 * The Bullet class represents projectiles fired by the player.
 */
class Bullet {
private:
    sf::Sprite sprite;
    bool toBeDestroyed;
    int damage;

    // direction that the bullet will move on x-axis (1.f = right, -1.f = left)
    float direction;
    float movementSpeed;

public:
    /**
     * Constructs a Bullet object.
     * @param texture The texture for the bullet.
     * @param player Reference to the player object.
     */
    Bullet(sf::Texture& texture, Player& player);

    /**
     * Destructor for the Bullet class.
     */
    ~Bullet();

    // Getters

    /**
     * Gets the global bounding rectangle of the bullet's sprite.
     * @return The global bounding rectangle of the bullet's sprite.
     */
    const sf::FloatRect& getGlobalBounds();

    /**
     * Gets the damage inflicted by the bullet.
     * @return The damage inflicted by the bullet.
     */
    const int getDamage();

    /**
     * Checks if the bullet is flagged to be destroyed.
     * @return True if the bullet is to be destroyed, false otherwise.
     */
    const bool getToBeDestroyed();

    /**
     * Gets the position of the bullet.
     * @return The position of the bullet.
     */
    const sf::Vector2f& getPosition();

    // Setters

    /**
     * Sets the status of the bullet for destruction.
     * @param destroyStatus The status for destruction.
     */
    void setToBeDestroyed(bool destroyStatus);

    /**
     * Updates the bullet's behavior.
     */
    void update();

    /**
     * Renders the bullet on the target.
     * @param target The rendering target.
     */
    void render(sf::RenderTarget& target);
};

