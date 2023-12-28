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
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Vector2f velocityMax;
    sf::Vector2f velocityMin;
    sf::Vector2f acceleration;
    sf::Vector2f drag; //drag.x is friction, drag.y is gravity
    //float moveDirectionX;
    sf::Vector2f moveDirection;

    //Animation variables
    sf::Clock animationClock;
    sf::IntRect spriteFrame;
    short int animationFrameCount;
    ANIMATION_STATES animationState;

    virtual void initVariables() = 0;
    virtual void initTexture() = 0;
    virtual void initSprite() = 0;

    virtual void updateAnimations() = 0;
    virtual void updateMovement() = 0;

public:
    virtual ~Entity() {}

    virtual const sf::FloatRect& getGlobalBounds() = 0;
    virtual const sf::Vector2f& getPosition() = 0;
    virtual const sf::Vector2f& getVelocity() = 0;
    virtual const sf::Vector2f& getVelocityMax() = 0;
    virtual const sf::Vector2f& getVelocityMin() = 0;
    virtual const sf::Vector2f& getAcceleration() = 0;
    virtual const sf::Vector2f& getDrag() = 0;
    virtual const sf::Vector2f& getMoveDirection() = 0;

    virtual void setPosition(float x, float y) = 0;
    virtual void setVelocity(float x, float y) = 0;

    virtual void update() = 0;
    virtual void render(sf::RenderTarget& target) = 0;
};



