#include "PhysicsManager.h"

PhysicsManager::PhysicsManager()
{

}

void PhysicsManager::applyAcceleration(Entity& entity)
{
	sf::Vector2f currentVelocity = entity.getVelocity();
	entity.setVelocity(currentVelocity.x + entity.getMoveDirection().x * entity.getAcceleration().x,
		currentVelocity.y + entity.getMoveDirection().y * entity.getAcceleration().y);

}

// this function also applies gravity as drag.y represents gravity
void PhysicsManager::applyDrag(Entity& entity)
{
	sf::Vector2f currentVelocity = entity.getVelocity();
	entity.setVelocity(currentVelocity.x * entity.getDrag().x, currentVelocity.y + entity.getDrag().y);
}

void PhysicsManager::applyGravity(Entity& entity)
{
}

// limits the maximum amount of velocity
void PhysicsManager::limitVelocity(Entity& entity)
{
	// limits on x
	if (std::abs(entity.getVelocity().x) >= entity.getVelocityMax().x)
	{
		if (entity.getVelocity().x < 0.f)
			entity.setVelocity(entity.getVelocityMax().x * -1.f, entity.getVelocity().y);
		else
			entity.setVelocity(entity.getVelocityMax().x * 1.f, entity.getVelocity().y);
	}

	// limits on y
	if (entity.getVelocity().y > entity.getVelocityMax().y)
	{
		if (entity.getVelocity().y < 0.f)
			entity.setVelocity(entity.getVelocity().x, entity.getVelocityMax().y * -1.f);
		else
			entity.setVelocity(entity.getVelocity().x, entity.getVelocityMax().y * 1.f);
	}
}

void PhysicsManager::limitMinimumVelocity(Entity& entity)
{
	if (std::abs(entity.getVelocity().x) < entity.getVelocityMin().x)
	{
		entity.setVelocity(0.f, entity.getVelocity().y);
	}
	if (std::abs(entity.getVelocity().y) < entity.getVelocityMin().y)
	{
		//std::cout << "in if\n";
		entity.setVelocity(entity.getVelocity().x, 0.f);
	}
}

void PhysicsManager::handleJumping(Entity& entity)
{
	if (entity.getCanJump() == true)
	{
		entity.setVelocity(entity.getVelocity().x, -entity.getJumpForce());
	}
}

void PhysicsManager::update(Entity& entity)
{
	applyAcceleration(entity);
	applyDrag(entity);
	limitVelocity(entity);
	limitMinimumVelocity(entity);
	handleJumping(entity);
}
