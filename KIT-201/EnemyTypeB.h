#pragma once
#include "Enemy.h"
class EnemyTypeB :
    public Enemy
{
private:
    short turnBackCounter;

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

