#include "PhysicsManager.h"

PhysicsManager::PhysicsManager()
{

}

void PhysicsManager::applyAcceleration(Player& player)
{
	sf::Vector2f currentVelocity = player.getVelocity();
	player.setVelocity(currentVelocity.x + player.getMoveDirectionX() * player.getAcceleration().x,
		currentVelocity.y); // y = 0.f for now
}

// this function also applies gravity as drag.y represents gravity
void PhysicsManager::applyDrag(Player& player)
{
	sf::Vector2f currentVelocity = player.getVelocity();
	player.setVelocity(currentVelocity.x * player.getDrag().x, currentVelocity.y + player.getDrag().y);
}

void PhysicsManager::applyGravity(Player& player)
{
}

// limits the maximum amount of velocity
void PhysicsManager::limitVelocity(Player& player)
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
	if (std::abs(player.getVelocity().y) > player.getVelocityMax().y)
	{
		if (player.getVelocity().y < 0.f)
			player.setVelocity(player.getVelocity().x, player.getVelocityMax().y * -1.f);
		else
			player.setVelocity(player.getVelocity().x, player.getVelocityMax().y * 1.f);
	}
}

void PhysicsManager::limitMinimumVelocity(Player& player)
{
	if (std::abs(player.getVelocity().x) < player.getVelocityMin().x)
	{
		player.setVelocity(0.f, player.getVelocity().y);
	}
	if (std::abs(player.getVelocity().y) < player.getVelocityMin().y)
	{
		player.setVelocity(player.getVelocity().x, 0.f);
	}
}

void PhysicsManager::update(Player& player)
{
	this->applyAcceleration(player);
	this->applyDrag(player);
	this->limitVelocity(player);
	this->limitMinimumVelocity(player);
}
