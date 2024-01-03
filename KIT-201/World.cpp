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

	entities[1]->setPosition(740.f,2.f);
	entities[2]->setPosition(800.f, 2.f);

	std::cout << entities[0]->isEnemy() << std::endl;
	std::cout << entities[1]->isEnemy() << std::endl;
	std::cout << entities[2]->isEnemy() << std::endl;
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

World::World() : collisionManager(tileMap)
{
	initVariables();
	initEntities();
}

void World::updateCollisions()
{
	for (auto& entity : entities)
	{
		collisionManager.handleCollisions(*entity, this->tileMap);
	}
}

void World::updatePhysics()
{
	for (auto& entity : entities)
	{
		physicsManager.update(*entity);
	}
}

void World::update()
{

	for (int i = 1u; i < this->entities.size(); i++)
	{
		for (int k = 0u; k < this->bullets.size(); k++)
		{
			if (bullets[k]->getGlobalBounds().left < entities[i]->getGlobalBounds().left + entities[i]->getGlobalBounds().width &&
				bullets[k]->getGlobalBounds().left + bullets[k]->getGlobalBounds().width > entities[i]->getGlobalBounds().left &&
				bullets[k]->getGlobalBounds().top < entities[i]->getGlobalBounds().top + entities[i]->getGlobalBounds().height &&
				bullets[k]->getGlobalBounds().top + bullets[k]->getGlobalBounds().height > entities[i]->getGlobalBounds().top)
			{
				// Remove the bullet from the vector
				bullets.erase(bullets.begin() + k);
				k--;
				break; // Exit the inner loop after collision is handled for this entity
			}
		}
	}

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