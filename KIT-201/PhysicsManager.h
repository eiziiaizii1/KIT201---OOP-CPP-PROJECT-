#pragma once
#include "Entity.h"

////FIXED BUG2: WHILE FALLING DOWN YOU CAN JUMP ON AIR
////FIXED BUG1: JUMPING NEAR THE WALLS MAKES A SUPER JUMP

class PhysicsManager
{

public:
	PhysicsManager();

	static void applyAcceleration(Entity& entity);
	static void applyDrag(Entity& entity);
	static void applyGravity(Entity& entity);
	static void limitVelocity(Entity& entity);
	static void limitMinimumVelocity(Entity& entity);
	static void handleJumping(Entity& entity);
	static void addForce(Entity& entity, float amountX, float amountY);


	static void update(Entity& entity);
};

