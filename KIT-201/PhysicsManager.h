#pragma once
#include "Player.h"

// NOTE: After creating an enemy and entity class, all player parameters will be changed as Entity


class PhysicsManager
{

public:
	PhysicsManager();

	void applyAcceleration(Player& player);
	void applyDrag(Player& player);
	void applyGravity(Player& player);
	void limitVelocity(Player& player);
	void limitMinimumVelocity(Player& player);

	void update(Player& player);
};

