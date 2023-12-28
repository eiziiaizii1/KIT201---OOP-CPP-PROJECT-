#include "PhysicsManager.h"

PhysicsManager::PhysicsManager()
{

}

void PhysicsManager::applyAcceleration(Player& player,float x_dir, float y_dir)
{
	player.setVelocity(x_dir * player.getAcceleration().x, y_dir);

	// limits the maximum amount of velocity
	limitVelocity(player);
}

void PhysicsManager::applyDrag()
{
}

void PhysicsManager::applyGravity()
{
}

void PhysicsManager::limitVelocity(Player& player)
{
	if (std::abs(player.getVelocity().x) >= player.getVelocityMax().x)
	{
		if (player.getVelocity().x < 0.f)
			player.setVelocity(player.getVelocityMax().x * -1.f, player.getVelocity().y);
			//this->velocity.x = this->velocityMax.x * -1.f;
		else
			player.setVelocity(player.getVelocityMax().x * 1.f, player.getVelocity().y);
			//this->velocity.x = this->velocityMax.x * 1.f;

		std::cout << "velocity limited" << std::endl;
	}
}

void PhysicsManager::limitMinimumVelocity()
{
}

void PhysicsManager::update()
{
}
