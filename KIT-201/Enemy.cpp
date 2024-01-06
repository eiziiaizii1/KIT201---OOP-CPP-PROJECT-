#include "Enemy.h"
// Pure virtual 

const bool Enemy::isEnemy()
{
	return true;
}

const int Enemy::getDamage()
{
	return damage;
}

