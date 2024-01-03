#pragma once
#include "Entity.h"
#include "Bullet.h"

class Enemy :
    public Entity
{
protected:
    short turnBackCounter;
    int damage;

    virtual void dealDamage(int damage, Bullet& player)=0;
    virtual void takeDamage(int damage)=0;
private:

};

