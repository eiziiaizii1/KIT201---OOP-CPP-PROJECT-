#pragma once
#include "Entity.h" // Include the base class header
#include "Camera.h"
//#include 
class Player : public Entity {
private:

    float lookDirection;
    sf::Vector2f startPosition;

    // it would be better if we move shooting variables to some kind of ShooterEntity class which is subclass of Entity
    bool canShoot;
    sf::Clock shootClock;

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

    const bool getCanShoot();
    const float getLookDirection();

    void revive(sf::Vector2f& startPos);

    const bool isEnemy() override;

    void update() override;
};

