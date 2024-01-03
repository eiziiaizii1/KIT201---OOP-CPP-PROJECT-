#pragma once
#include "Entity.h"
#include "Bullet.h"

class Enemy :
    public Entity
{
protected:
    short turnBackCounter;
    int damage;

public:
    virtual void dealDamage(int damage, Bullet& player)=0;
    virtual void takeDamage(int damage)=0;
    virtual const bool isEnemy();
private:

};

