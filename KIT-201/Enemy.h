#pragma once
#include "Entity.h"
class Enemy :
    public Entity
{
private:

    void initVariables() override;
    void initTexture() override;
    void initSprite() override;

    void updateAnimations() override;
    void updateMovement() override;

public:
    Enemy();

    void update();
    void render(sf::RenderTarget& target);
};

