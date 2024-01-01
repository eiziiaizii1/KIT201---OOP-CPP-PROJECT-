#include "World.h"

// TODO 1: More modular bullet culling

void World::initVariables()
{
	this->player.setPosition(1280.f/2,0.f);

	if (!this->bulletTexture.loadFromFile("Textures/LaserBullet.png"))
		std::cout << "failed to load the bullet texture" << std::endl;
}

void World::shootBullets()
{
	if (this->player.getCanShoot())
	{
		std::unique_ptr<Bullet> newBullet = std::make_unique<Bullet>(this->bulletTexture, this->player);
		this->bullets.push_back(std::move(newBullet));
	}
}

void World::updateBullets()
{
	// Use remove_if with a lambda function to erase elements matching the condition
	this->bullets.erase(
		std::remove_if(this->bullets.begin(), this->bullets.end(),
		[](const std::unique_ptr<Bullet>& bullet) 
		{
			// Update and check for bullet culling
			bullet->update();
			return (bullet->getGlobalBounds().left + bullet->getGlobalBounds().width) < 0.f ||
				   (bullet->getGlobalBounds().left > 6400.f); // Hard coded value for now
		}), this->bullets.end());
}

void World::renderBullets(sf::RenderTarget& target)
{
	for (const auto& bullet : this->bullets)
	{
		bullet->render(target);
	}
}

World::World() : collisionManager(tileMap)
{
	initVariables();
}

void World::updatePhysics()
{
	this->physicsManager.update(this->player);
}

void World::update()
{
	this->player.update();
	this->collisionManager.handleCollisions(this->player, this->tileMap);
	this->physicsManager.update(this->player);
	this->shootBullets();
	this->updateBullets();

	// Update camera position to follow the player
	camera.setCenter(player.getPosition());
}

void World::render(sf::RenderTarget& target)
{
	this->tileMap.render(target);
	this->player.render(target);
	this->renderBullets(target);
}

Player& World::getPlayer() {
	return this->player;
}

Camera& World::getCamera() {
	return camera;
}