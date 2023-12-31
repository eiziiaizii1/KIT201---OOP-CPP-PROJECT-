#pragma once
#include "Player.h"
#include "TileMap.h"
#include "CollisionManager.h"
#include "PhysicsManager.h"
#include "Bullet.h"

class World
{
private:
	// Player and Enemies
	Player player;

	// Bullet related variables
	std::vector<Bullet*> bullets;
	sf::Texture bulletTexture;

	// TileMap 
	TileMap tileMap;

	//Managers
	CollisionManager collisionManager;
	PhysicsManager physicsManager;

	void initVariables();

public:
	//Constructors
	World();

	void updateBullets();
	void updatePhysics();
	void update();
	void render(sf::RenderTarget& target);
};

