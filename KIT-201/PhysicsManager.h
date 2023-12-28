#pragma once
#include "Player.h"

class PhysicsManager
{

public:
	PhysicsManager();

	static void applyAcceleration(Player& player, float x_dir, float y_dir);
	void applyDrag();
	void applyGravity();
	static void limitVelocity(Player& player);
	void limitMinimumVelocity();

	void update();
};

