#include "PhysicsManager.h"

PhysicsManager::PhysicsManager()
{

}

void PhysicsManager::applyAcceleration(Entity& player)
{
	sf::Vector2f currentVelocity = player.getVelocity();
	player.setVelocity(currentVelocity.x + player.getMoveDirection().x * player.getAcceleration().x,
		currentVelocity.y * player.getMoveDirection().y * player.getAcceleration().y);
}

// this function also applies gravity as drag.y represents gravity
void PhysicsManager::applyDrag(Entity& player)
{
	sf::Vector2f currentVelocity = player.getVelocity();
	player.setVelocity(currentVelocity.x * player.getDrag().x, currentVelocity.y + player.getDrag().y);
}

void PhysicsManager::applyGravity(Entity& player)
{
}

// limits the maximum amount of velocity
void PhysicsManager::limitVelocity(Entity& player)
{
	// limits on x
	if (std::abs(player.getVelocity().x) >= player.getVelocityMax().x)
	{
		if (player.getVelocity().x < 0.f)
			player.setVelocity(player.getVelocityMax().x * -1.f, player.getVelocity().y);
		else
			player.setVelocity(player.getVelocityMax().x * 1.f, player.getVelocity().y);
	}

	// limits on y
	if (player.getVelocity().y > player.getVelocityMax().y)
	{
		if (player.getVelocity().y < 0.f)
			player.setVelocity(player.getVelocity().x, player.getVelocityMax().y * -1.f);
		else
			player.setVelocity(player.getVelocity().x, player.getVelocityMax().y * 1.f);
	}
}

void PhysicsManager::limitMinimumVelocity(Entity& player)
{
	if (std::abs(player.getVelocity().x) < player.getVelocityMin().x)
	{
		player.setVelocity(0.f, player.getVelocity().y);
	}
	if (std::abs(player.getVelocity().y) < player.getVelocityMin().y)
	{
		std::cout << "in if\n";
		player.setVelocity(player.getVelocity().x, 0.f);
	}
}

void PhysicsManager::handleJumping(Entity& player)
{
	if (player.getCanJump() == true)
	{
		player.setVelocity(player.getVelocity().x, -player.getJumpForce());
	}
}

void PhysicsManager::update(Entity& player)
{
	this->applyAcceleration(player);
	this->applyDrag(player);
	this->limitVelocity(player);
	this->limitMinimumVelocity(player);
	this->handleJumping(player);
}
