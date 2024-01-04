#pragma once
#include "Entity.h"
#include "Bullet.h"

class Enemy :
    public Entity
{
protected:
    int damage;

public:

    virtual const bool isEnemy();
};

