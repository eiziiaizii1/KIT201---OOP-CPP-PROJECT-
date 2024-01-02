#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

enum class ANIMATION_STATES { IDLE = 0, MOVING_RIGHT, MOVING_LEFT };

class Entity {
protected:
    //Texture variables
    sf::Texture textureRun;
    sf::Texture textureIdle;
    sf::Sprite sprite;

    //Physics variables
    sf::Vector2f velocity;
    sf::Vector2f velocityMax;
    sf::Vector2f velocityMin;
    sf::Vector2f acceleration;
    sf::Vector2f drag; //drag.x is friction, drag.y is gravity
    sf::Vector2f moveDirection;
    float jumpForce;
    bool canJump;
    bool isGrounded;

    //Animation variables
    sf::Clock animationClock;
    sf::IntRect spriteFrame;
    ANIMATION_STATES animationState;

    virtual void initVariables() = 0;
    virtual void initTexture() = 0;
    virtual void initSprite() = 0;

    virtual void updateAnimations() = 0;
    virtual void updateMovement() = 0;

public:
    virtual ~Entity() {}

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

    virtual void setPosition(float x, float y);
    virtual void setVelocity(float x, float y);
    virtual void setIsGrounded(bool grounded);

    virtual void update() = 0;
    virtual void render(sf::RenderTarget& target) = 0;
};



