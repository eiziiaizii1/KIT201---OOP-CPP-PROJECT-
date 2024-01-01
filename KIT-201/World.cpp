#include "World.h"

void World::initVariables()
{
	this->player.setPosition(1280.f/2,0.f);
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
	collisionManager.handleCollisions(this->player, this->tileMap);
	this->physicsManager.update(this->player);

	// Update camera position to follow the player
	camera.setCenter(player.getPosition());
}

void World::render(sf::RenderTarget& target)
{
	this->player.render(target);
	this->tileMap.render(target);
}

Player& World::getPlayer() {
	return this->player;
}

Camera& World::getCamera() {
	return camera;
}