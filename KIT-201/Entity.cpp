#include "Entity.h"
//Empty because it's purely virtual

const sf::FloatRect& Entity::getGlobalBounds()
{
	return this->sprite.getGlobalBounds();
}

const sf::Vector2f& Entity::getPosition()
{
	return this->sprite.getPosition();
}

const sf::Vector2f& Entity::getVelocity()
{
	// TODO: insert return statement here
	return this->velocity;
}

const sf::Vector2f& Entity::getVelocityMax()
{
	// TODO: insert return statement here
	return velocityMax;
}

const sf::Vector2f& Entity::getVelocityMin()
{
	// TODO: insert return statement here
	return velocityMin;
}

const sf::Vector2f& Entity::getAcceleration()
{
	// TODO: insert return statement here
	return acceleration;
}

const sf::Vector2f& Entity::getDrag()
{
	// TODO: insert return statement here
	return drag;
}

const sf::Vector2f& Entity::getMoveDirection()
{
	// TODO: insert return statement here
	return moveDirection;
}

const float& Entity::getJumpForce()
{
	// TODO: insert return statement here
	return jumpForce;
}

const bool& Entity::getCanJump()
{
	// TODO: insert return statement here
	return canJump;
}

const bool& Entity::getIsGrounded()
{
	// TODO: insert return statement here
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

void Entity::takeDamage(int damage)
{
	health -= damage;
}

void Entity::dealDamage(int damage, Entity& entity)
{
	entity.takeDamage(damage);
}
