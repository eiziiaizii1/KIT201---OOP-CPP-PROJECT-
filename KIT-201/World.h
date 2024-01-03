#pragma once
#include "Entity.h"
#include "TileMap.h"
#include "CollisionManager.h"
#include "PhysicsManager.h"
#include "Camera.h"
#include "Bullet.h"

class World
{
private:
	// Player and stuff
	Player player;
	Camera camera;

	//Bullet
	std::vector<std::unique_ptr<Bullet>> bullets;
	sf::Texture bulletTexture;

	// TileMap 
	TileMap tileMap;

	//Managers
	CollisionManager collisionManager;
	PhysicsManager physicsManager;
	

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

