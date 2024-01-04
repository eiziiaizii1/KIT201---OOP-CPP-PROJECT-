#pragma once
#include "Entity.h"
#include "Enemy.h"
#include "TileMap.h"
#include "CollisionManager.h"
#include "PhysicsManager.h"
#include "Camera.h"
#include "Bullet.h"
#include "EnemyTypeA.h"
#include "EnemyTypeB.h"

class World
{
private:
	Camera camera;
	
	//Entities
	//Enemy enemy;


	// index 0 represents player, other indices represent enemies
	std::vector<std::unique_ptr<Entity>> entities;

	//Bullet
	std::vector<std::unique_ptr<Bullet>> bullets;
	sf::Texture bulletTexture;

	// TileMap 
	TileMap tileMap;

	//Managers
	//CollisionManager collisionManager;

	void initVariables();
	void initEntities();
	void updateEntities();

	//Bullet related
	void shootBullets();
	void updateBullets();
	void renderBullets(sf::RenderTarget& target);

	void renderEntities(sf::RenderTarget& target);

public:
	//Constructors
	World();

	Player& getPlayer();
	Camera& getCamera();

	void updateCollisions();
	void updatePhysics();
	void update();
	void render(sf::RenderTarget& target);
};

