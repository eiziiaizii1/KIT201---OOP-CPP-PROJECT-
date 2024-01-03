#pragma once
#include "Entity.h"
#include "Enemy.h"
#include "TileMap.h"
#include "CollisionManager.h"
#include "PhysicsManager.h"
#include "SoundManager.h"
#include "Camera.h"
#include "Bullet.h"

class World
{
private:
	// Player and stuff
	Player player;
	Camera camera;
	
	//Enemy
	Enemy enemy;

	//Bullet
	std::vector<std::unique_ptr<Bullet>> bullets;
	sf::Texture bulletTexture;

	// TileMap 
	TileMap tileMap;

	//Managers
	CollisionManager collisionManager;
	PhysicsManager physicsManager;
	SoundManager soundManager;

	void initVariables();
	//Bullet related
	void shootBullets();
	void updateBullets();
	void renderBullets(sf::RenderTarget& target);

public:
	//Constructors
	World();

	Player& getPlayer();
	Camera& getCamera();

	void updatePhysics();
	void update();
	void render(sf::RenderTarget& target);
};

