#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

/**
 * @brief States for entity animations.
 */
enum class ANIMATION_STATES {
    IDLE = 0, /**< Idle state. */
    MOVING_RIGHT, /**< Moving right state. */
    MOVING_LEFT /**< Moving left state. */
};

/**
 * @brief Represents a generic entity.
 */
class Entity {
protected:
    // Texture variables
    sf::Texture textureRun;
    sf::Texture textureIdle;
    sf::Sprite sprite;

    // Health, damage, etc.
    int health;
    bool isDead = false;
    bool isHit = false;

    // Physics variables
    sf::Vector2f velocity;
    sf::Vector2f velocityMax;
    sf::Vector2f velocityMin;
    sf::Vector2f acceleration;
    sf::Vector2f drag; // drag.x is friction, drag.y is gravity
    sf::Vector2f moveDirection;
    float jumpForce;
    bool canJump;
    bool isGrounded;

    // Animation variables
    sf::Clock animationClock;
    sf::IntRect spriteFrame;
    ANIMATION_STATES animationState;

    /**
     * @brief Initializes specific variables for the entity.
     */
    virtual void initVariables() = 0;

    /**
     * @brief Initializes the texture for the entity.
     */
    virtual void initTexture() = 0;

    /**
     * @brief Initializes the sprite for the entity.
     */
    virtual void initSprite() = 0;

    /**
     * @brief Updates animations for the entity.
     */
    virtual void updateAnimations() = 0;

    /**
     * @brief Updates movement for the entity.
     */
    virtual void updateMovement() = 0;

public:
    virtual ~Entity() {}

    // Getter methods
    virtual const sf::FloatRect& getGlobalBounds();
    virtual const sf::Vector2f& getPosition();
    virtual const sf::Vector2f& getVelocity();
    virtual const sf::Vector2f& getVelocityMax();
    virtual const sf::Vector2f& getVelocityMin();
    virtual const sf::Vector2f& getAcceleration();
    virtual const sf::Vector2f& getDrag();
    virtual const sf::Vector2f& getMoveDirection();
    virtual const float& getJumpForce();
    virtual const bool& getCanJump();
    virtual const bool& getIsGrounded();
    virtual const bool getIsDead();
    virtual const int getHealth();
    virtual const bool getIsHit();

    // Setter methods
    virtual void setPosition(float x, float y);
    virtual void setVelocity(float x, float y);
    virtual void setIsGrounded(bool grounded);
    virtual void setDead();
    virtual void setIsHit(bool hitStatus);

    // Methods for interaction
    virtual void takeDamage(int damage);
    virtual void dealDamage(int damage, Entity& entity);

    // Update and rendering methods
    virtual void update() = 0;
    virtual void render(sf::RenderTarget& target);

    /**
     * @brief Indicates if the entity is an enemy.
     *
     * @return true if the entity is an enemy.
     */
    virtual const bool isEnemy() = 0;
};

