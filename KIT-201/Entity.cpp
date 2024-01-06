#include "Entity.h"

const sf::FloatRect Entity::getGlobalBounds()
{
	return this->sprite.getGlobalBounds();
}

const sf::Vector2f& Entity::getPosition()
{
	return this->sprite.getPosition();
}

const sf::Vector2f& Entity::getVelocity()
{
	return this->velocity;
}

const sf::Vector2f& Entity::getVelocityMax()
{
	return velocityMax;
}

const sf::Vector2f& Entity::getVelocityMin()
{
	return velocityMin;
}

const sf::Vector2f& Entity::getAcceleration()
{
	return acceleration;
}

const sf::Vector2f& Entity::getDrag()
{
	return drag;
}

const sf::Vector2f& Entity::getMoveDirection()
{
	return moveDirection;
}

const float& Entity::getJumpForce()
{
	return jumpForce;
}

const bool& Entity::getCanJump()
{
	return canJump;
}

const bool& Entity::getIsGrounded()
{
	return isGrounded;
}

const bool Entity::getIsDead()
{
	return isDead;
}

const int Entity::getHealth()
{
	return health;
}

const int Entity::getMaxHealth()
{
	return maxHealth;
}

const bool Entity::getIsHit()
{
	return isHit;
}

void Entity::setPosition(float x, float y)
{
	sprite.setPosition(sf::Vector2f(x, y));
}

void Entity::setVelocity(float x, float y)
{
	velocity = sf::Vector2f(x, y);
}

void Entity::setIsGrounded(bool grounded)
{
	isGrounded = grounded;
}

void Entity::setDead()
{
	isDead = true;
}

void Entity::setIsHit(bool hitStatus)
{
	isHit = hitStatus;
}

void Entity::takeDamage(int damage)
{
	health -= damage;
}

void Entity::render(sf::RenderTarget& target)
{
	target.draw(sprite);
}
