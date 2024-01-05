#pragma once
#include "Enemy.h"
class EnemyTypeB :
    public Enemy
{
private:
    sf::Clock moveClock; 
    sf::IntRect spriteFrameRun; // has diferent sizes for run and idle texture-sheets, so I had to add another spriteFrame


    void initVariables() override;
    void initTexture() override;
    void initSprite() override;

    void updateAnimations() override;
    void updateMovement() override;

public:
    EnemyTypeB();

    void update();
};

