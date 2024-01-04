#include "World.h"

// TODO 1: More modular bullet culling

void World::initVariables()
{
	//this->player.setPosition(1280.f/2,0.f);

	if (!this->bulletTexture.loadFromFile("Textures/LaserBullet.png"))
		std::cout << "failed to load the bullet texture" << std::endl;
}

void World::initEntities()
{
	entities.push_back(std::make_unique<Player>());
	entities.push_back(std::make_unique<EnemyTypeA>());
	entities.push_back(std::make_unique<EnemyTypeA>());
	entities.push_back(std::make_unique<EnemyTypeB>());

	entities[1]->setPosition(740.f,2.f);
	entities[2]->setPosition(800.f, 2.f);
	entities[3]->setPosition(1000.f, 2.f);
}

void World::updateEntities()
{
	for (auto& entity: entities)
	{
		entity->update();
	}
}

void World::renderEntities(sf::RenderTarget& target)
{
	for (auto& entity : entities)
	{
		entity->render(target);
	}
}

void World::shootBullets()
{
	// Only player can shoot so we need to cast it to player
	Player* playerEntity = dynamic_cast<Player*>(entities[0].get());

	// Makes sure that it is player and then it checks canShoot
	if (playerEntity && playerEntity->getCanShoot()) {
		std::unique_ptr<Bullet> newBullet = std::make_unique<Bullet>(this->bulletTexture, *playerEntity);
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

World::World()
{
	initVariables();
	initEntities();
}

void World::updateCollisions()
{
	for (auto& entity : entities)
	{
		CollisionManager::handleCollisions(*entity, this->tileMap);
	}

	CollisionManager::handleCollisions(bullets,entities);
}

void World::updatePhysics()
{
	for (auto& entity : entities)
	{
		PhysicsManager::update(*entity);
	}
}

void World::update()
{

	

	//collisionManager.handleBulletEnemyCollisions(bullets,entities);

	updatePhysics();

	updateEntities();

	updateCollisions();
	
	shootBullets();

	updateBullets();
	
	// Update camera position to follow the player
	camera.setCenter(entities[0]->getPosition());
}

void World::render(sf::RenderTarget& target)
{
	tileMap.render(target);
	renderBullets(target);

	renderEntities(target);
}

Player& World::getPlayer() {
	return dynamic_cast<Player&>(*entities[0]);
}

Camera& World::getCamera() {
	return camera;
}