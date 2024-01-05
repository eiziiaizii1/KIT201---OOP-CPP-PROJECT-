#include "Enemy.h"
// Pure virtual 

const bool Enemy::isEnemy()
{
	return true;
}

const bool Enemy::getDamage()
{
	return damage;
}

