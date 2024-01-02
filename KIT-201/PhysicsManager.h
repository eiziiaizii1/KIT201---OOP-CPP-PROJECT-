#pragma once
#include "Entity.h"

////FIXED BUG2: WHILE FALLING DOWN YOU CAN JUMP ON AIR
////FIXED BUG1: JUMPING NEAR THE WALLS MAKES A SUPER JUMP

class PhysicsManager
{

public:
	PhysicsManager();

	void applyAcceleration(Entity& entity);
	void applyDrag(Entity& entity);
	void applyGravity(Entity& entity);
	void limitVelocity(Entity& entity);
	void limitMinimumVelocity(Entity& entity);
	void handleJumping(Entity& entity);

	void update(Entity& entity);
};

