#pragma once
#include "Enemy.h"

class EnemyTypeA :
    public Enemy
{
private:
    short turnBackCounter;
    bool turnBackBoolean;

    void initVariables() override;
    void initTexture() override;
    void initSprite() override;

    void updateAnimations() override;
    void updateMovement() override;

public:
    EnemyTypeA();

    void update();
};

