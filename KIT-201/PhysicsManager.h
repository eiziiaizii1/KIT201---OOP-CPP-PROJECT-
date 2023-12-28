#pragma once
#include "Player.h"


class PhysicsManager
{

public:
	PhysicsManager();

	void applyAcceleration(Entity& player);
	void applyDrag(Entity& player);
	void applyGravity(Entity& player);
	void limitVelocity(Entity& player);
	void limitMinimumVelocity(Entity& player);

	void update(Entity& player);
};

