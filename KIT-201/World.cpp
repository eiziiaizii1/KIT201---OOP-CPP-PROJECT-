#include "World.h"

void World::initVariables()
{
	this->player.setPosition(1280.f/2,0.f);
}

World::World()
{
	initVariables();
}

void World::update()
{
	this->player.update();
	collisionManager.handleCollisions(this->player, this->tileMap);
}

void World::render(sf::RenderTarget& target)
{
	this->player.render(target);
	this->tileMap.render(target);
}
