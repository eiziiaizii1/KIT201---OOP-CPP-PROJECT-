#pragma once
#include "Player.h"
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

	//Bullet
	std::vector<Bullet*> bullets;
	sf::Texture bulletTexture;

	// TileMap 
	TileMap tileMap;

	//Managers
	CollisionManager collisionManager;
	PhysicsManager physicsManager;
	SoundManager soundManager;

	void initVariables();

public:
	//Constructors
	World();

	Player& getPlayer();
	Camera& getCamera();

	void updatePhysics();
	void update();
	void render(sf::RenderTarget& target);
};

