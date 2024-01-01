#pragma once
#include "Player.h"
#include "TileMap.h"
#include "CollisionManager.h"
#include "PhysicsManager.h"
#include "SoundManager.h"
class World
{
private:
	// Player and stuff
	Player player;

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
	void updatePhysics();
	void update();
	void render(sf::RenderTarget& target);
};

