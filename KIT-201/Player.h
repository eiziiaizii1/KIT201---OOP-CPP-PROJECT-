#pragma once
#include "Entity.h" // Include the base class header

enum horizontalCollisionSide {NONE = 0, LEFT, RIGHT};

class Player : public Entity {
private:
    
    sf::View playerView;

    bool isGrounded;
    bool canJump;
    float jumpForce;

    horizontalCollisionSide collisionSide;

    // Implementations of abstract methods
    void initVariables() override;
    void initTexture() override;
    void initSprite() override;
    void updateAnimations() override;
    void updateMovement() override;

public:
    // Constructors - Destructor
    Player();
    ~Player();

    sf::View& getPlayerView();

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
    const horizontalCollisionSide& getCollisionSide();

    void setPosition(float x, float y) override;
    void setVelocity(float x, float y) override;
    void setIsGrounded(bool grounded);
    void setCollisionSide(int collisionSide);

    void update() override;
    void render(sf::RenderTarget& target) override;
};

