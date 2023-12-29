#pragma once
#include "Player.h"

// BUG1: JUMPING NEAR THE WALLS MAKES A SUPER JUMP
// BUG2: WHILE FALLING DOWN YOU CAN JUMP ON AIR

class PhysicsManager
{

public:
	PhysicsManager();

	void applyAcceleration(Entity& player);
	void applyDrag(Entity& player);
	void applyGravity(Entity& player);
	void limitVelocity(Entity& player);
	void limitMinimumVelocity(Entity& player);
	void handleJumping(Entity& player);

	void update(Entity& player);
};

