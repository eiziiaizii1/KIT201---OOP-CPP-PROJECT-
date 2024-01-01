#pragma once
#include "Entity.h" // Include the base class header
#include "Camera.h"

class Player : public Entity {
private:

    bool isGrounded;
    bool canJump;
    float jumpForce;

    float lookDirection;

    // it would be better if we move this to some kind of AttackerEntity class which is subclass of Entity
    bool canShoot;

    // Implementations of abstract methods
    void initVariables() override;
    void initTexture() override;
    void initSprite() override;

    void updateShootStatus(); // UPDATES THE CANSHOOT BASED ON LEFT CLICK 
    void updateAnimations() override;
    void updateMovement() override;

public:
    // Constructors - Destructor
    Player();
    ~Player();


    // Implementations of remaining abstract methods
    const sf::FloatRect& getGlobalBounds() override;
    const sf::Vector2f& getPosition() override;
    const sf::Vector2f& getVelocity() override;
    const sf::Vector2f& getVelocityMax() override;
    const sf::Vector2f& getVelocityMin() override;
    const sf::Vector2f& getAcceleration() override;
    const sf::Vector2f& getDrag() override;
    const sf::Vector2f& getMoveDirection() override;
    const float& getJumpForce();
    const bool& getCanJump();
    const bool& getIsGrounded();

    const bool getCanShoot();
    const float getLookDirection();

    void setPosition(float x, float y) override;
    void setVelocity(float x, float y) override;
    void setIsGrounded(bool grounded);

    void update() override;
    void render(sf::RenderTarget& target) override;
};

