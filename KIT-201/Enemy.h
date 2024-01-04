#pragma once
#include "Entity.h"
#include "Bullet.h"

class Enemy :
    public Entity
{
protected:
    int damage;

public:

    virtual void takeDamage(int damage)=0;
    virtual const bool isEnemy();
private:

};

