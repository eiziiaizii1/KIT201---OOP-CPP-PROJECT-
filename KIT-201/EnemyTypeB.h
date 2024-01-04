#pragma once
#include "Enemy.h"
class EnemyTypeB :
    public Enemy
{
private:
    
    // example: player goes to right while timer is less then a specific amount then go left etc.
    sf::Clock moveClock;

    void initVariables() override;
    void initTexture() override;
    void initSprite() override;

    void updateAnimations() override;
    void updateMovement() override;

public:
    EnemyTypeB();

    //void dealDamage(int damage, Bullet& player) override;

    void update();
};

