#pragma once
#include "Player.h"

////FIXED BUG2: WHILE FALLING DOWN YOU CAN JUMP ON AIR
////FIXED BUG1: JUMPING NEAR THE WALLS MAKES A SUPER JUMP

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

