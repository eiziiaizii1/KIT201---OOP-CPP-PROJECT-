#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

/**
 * Enumerates the animation states for entities.
 */
enum class ANIMATION_STATES {
    IDLE = 0, /**< Represents the idle animation state. */
    MOVING_RIGHT, /**< Represents the right movement animation state. */
    MOVING_LEFT /**< Represents the left movement animation state. */
};

/**
 * @Represents the base class for entities.
 */
class Entity {
protected:
    // Texture variables
    sf::Texture textureRun; /**< Texture for running animation. */
    sf::Texture textureIdle; /**< Texture for idle animation. */
    sf::Sprite sprite; /**< Sprite representing the entity. */

    // Health, damage, etc.
    int health; /**< Current health of the entity. */
    int maxHealth; /**< Maximum health capacity of the entity. */
    bool isDead = false; /**< Flag indicating if the entity is dead. */
    bool isHit = false; /**< Flag indicating if the entity is hit. */

    // Physics variables
    sf::Vector2f velocity; /**< Current velocity of the entity. */
    sf::Vector2f velocityMax; /**< Maximum allowed velocity of the entity. */
    sf::Vector2f velocityMin; /**< Minimum allowed velocity of the entity. */
    sf::Vector2f acceleration; /**< Acceleration of the entity. */
    sf::Vector2f drag; /**< Drag affecting the entity's movement. (x: friction, y: gravity) */
    sf::Vector2f moveDirection; /**< Direction in which the entity is moving. */
    float jumpForce; /**< Force applied for jumping. */
    bool canJump; /**< Flag indicating if the entity can jump. */
    bool isGrounded; /**< Flag indicating if the entity is grounded. */

    // Animation variables
    sf::Clock animationClock; /**< Clock for managing animations. */
    sf::IntRect spriteFrame; /**< Rectangle defining the sprite frame. */
    ANIMATION_STATES animationState; /**< Current animation state of the entity. */

    virtual void initVariables() = 0; /**< Initializes entity-specific variables. */
    virtual void initTexture() = 0; /**< Initializes the entity's textures. */
    virtual void initSprite() = 0; /**< Initializes the entity's sprite. */

    virtual void updateAnimations() = 0; /**< Updates entity-specific animations. */
    virtual void updateMovement() = 0; /**< Updates entity movement. */

public:
    virtual ~Entity() {}

    // Getters
    /**
     * @brief Retrieves the global bounding rectangle of the entity.
     * @return The bounding rectangle.
     */
    virtual const sf::FloatRect getGlobalBounds();
    virtual const sf::Vector2f& getPosition(); /**< Retrieves the position of the entity. */
    virtual const sf::Vector2f& getVelocity(); /**< Retrieves the velocity of the entity. */
    virtual const sf::Vector2f& getVelocityMax(); /**< Retrieves the maximum velocity of the entity. */
    virtual const sf::Vector2f& getVelocityMin(); /**< Retrieves the minimum velocity of the entity. */
    virtual const sf::Vector2f& getAcceleration(); /**< Retrieves the acceleration of the entity. */
    virtual const sf::Vector2f& getDrag(); /**< Retrieves the drag affecting the entity. */
    virtual const sf::Vector2f& getMoveDirection(); /**< Retrieves the movement direction of the entity. */
    virtual const float& getJumpForce(); /**< Retrieves the force applied for jumping. */
    virtual const bool& getCanJump(); /**< Retrieves the flag indicating if the entity can jump. */
    virtual const bool& getIsGrounded(); /**< Retrieves the flag indicating if the entity is grounded. */
    virtual const bool getIsDead(); /**< Retrieves the flag indicating if the entity is dead. */
    virtual const bool getIsHit(); /**< Retrieves the flag indicating if the entity is hit. */
    virtual const int getHealth(); /**< Retrieves the current health of the entity. */
    virtual const int getMaxHealth(); /**< Retrieves the maximum health capacity of the entity. */

    // Polymorphic methods
    virtual const bool isEnemy() = 0; /**< Checks if the entity is an enemy. */

    virtual void setPosition(float x, float y); /**< Sets the position of the entity. */
    virtual void setVelocity(float x, float y); /**< Sets the velocity of the entity. */
    virtual void setIsGrounded(bool grounded); /**< Sets the grounded status of the entity. */
    virtual void setDead(); /**< Sets the entity as dead. */
    virtual void setIsHit(bool hitStatus); /**< Sets the hit status of the entity. */

    virtual void takeDamage(int damage); /**< Inflicts damage on the entity. */

    // Update and render methods
    virtual void update() = 0; /**< Updates the entity. */
    virtual void render(sf::RenderTarget& target); /**< Renders the entity. */
};
