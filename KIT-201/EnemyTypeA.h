#pragma once
#include "Enemy.h"

class EnemyTypeA :
    public Enemy
{
    void initVariables() override;
    void initTexture() override;
    void initSprite() override;

    void updateAnimations() override;
    void updateMovement() override;

public:
    EnemyTypeA();

    void dealDamage(int damage, Bullet& player) override;
    void takeDamage(int damage) override;

    void update();
    void render(sf::RenderTarget& target);
};

