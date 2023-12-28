#pragma once
#include "Entity.h" // Include the base class header

class Player : public Entity {
private:
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

    // Implementations of remaining abstract methods
    const sf::FloatRect& getGlobalBounds() override;
    const sf::Vector2f& getPosition() override;
    const sf::Vector2f& getVelocity() override;
    const sf::Vector2f& getVelocityMax() override;
    const sf::Vector2f& getVelocityMin() override;
    const sf::Vector2f& getAcceleration() override;
    const sf::Vector2f& getDrag() override;
    const float& getMoveDirectionX() override;

    void setPosition(float x, float y) override;
    void setVelocity(float x, float y) override;

    void update() override;
    void render(sf::RenderTarget& target) override;
};

