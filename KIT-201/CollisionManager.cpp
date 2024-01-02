#include "CollisionManager.h"

////DONE TODO 1: IMPLEMENT THE TOP COLLISSION ON Y-AXIS (DO IT AFTER CODING PLAYER JUMP)
////FIXED !!BUG3: GAME ABORTS WHEN PLAYER GOES BEYOND THE SCREEN
////FIXED MINOR BUG4: UNEXPECTED and glitchy BEHAVIOR WHEN the player enters a place that is 2 blocks high 
////FIXED MINOR BUG5: When llower, lupper, ltop happens at the same time player teleports to the lower part of the platform
////FIXED MINOR BUG1: Colliding with the side edges of the tile while airborne causes a glitch
////FIXED MINOR BUG2: holding down to the cliff :D (My the god help me I dont know how to fix that)
////FIXED MINOR BUG6: When player is on the leftmost block's leftmost edge it falls (it is due to large player sprite width), can be fixed or minimized
////FIXED NOTE: CHECKING ONLY BOTTOM MID FOR BOTTOM COLLISIONS SOLVES MOST OF THE PROBLEMS, but when player falls as it goes edge of the block

CollisionManager::CollisionManager(TileMap& tileMap)
{
	this->tileBounds = tileMap.getTileGlobalBounds();
}

void CollisionManager::handleBottomCollisions(Entity& entity, std::vector<std::vector<short>>& tileMap, short leftTopY, short leftBottomY)
{
	//as we only need these variables here, we don't need to calculate them in handleCollisions() function
	float offSet = (entity.getGlobalBounds().width - tileBounds.width) / 2.f;

	short leftMidBottomX = floor((entity.getGlobalBounds().left + offSet) / tileBounds.width);
	short rightMidBottomX = floor(((entity.getGlobalBounds().left + entity.getGlobalBounds().width - offSet)) / tileBounds.width);

	// Bottom Collision
	// entity's y index is same for all bottom parts no need to recalculate BottomY index 
	if (tileMap[leftBottomY][leftMidBottomX] == GROUND ||
		tileMap[leftBottomY][rightMidBottomX] == GROUND)
	{
		std::cout << "BOTTOM\n";
		entity.setPosition
		(
			entity.getPosition().x,
			tileBounds.height * leftTopY
		);
		entity.setVelocity(entity.getVelocity().x, 0.f);

		// Setting 'isGrounded' to true here will prevent the player from jumping while falling down.
		
		entity.setIsGrounded(true);
	}
	else
	{
		entity.setIsGrounded(false);
	}
}

void CollisionManager::handleTopCollisions(
	Entity& entity, std::vector<std::vector<short>>& tileMap, bool& topCollided,
	short leftTopX, short leftTopY, short rightTopX, short rightTopY, short midTopX, short midTopY)
{
	if (entity.getVelocity().y < 0 &&
		(tileMap[leftTopY][leftTopX] == GROUND ||
			tileMap[rightTopY][rightTopX] == GROUND ||
			tileMap[midTopY][midTopX] == GROUND))
	{
		topCollided = true;
		std::cout << "TOP\n";
		entity.setPosition
		(
			entity.getPosition().x,
			tileBounds.height * (leftTopY + 1)
		);
		entity.setVelocity(entity.getVelocity().x, 0.f);
	}
}

void CollisionManager::handleLeftCollisions(
	Entity& entity, std::vector<std::vector<short>>& tileMap, short leftBottomX, short leftBottomY, short leftTopX, short leftTopY)
{
	// Lower left side collision
	if (tileMap[leftBottomY - 1][leftBottomX] == GROUND)
	{
		std::cout << "left lower\n";
		entity.setPosition
		(
			tileBounds.width * (leftTopX + 1),
			entity.getPosition().y
		);
		entity.setVelocity(0.f, entity.getVelocity().y);
	}
	// Upper left side collision
	else if (tileMap[leftTopY][leftTopX] == GROUND)
	{
		std::cout << "left upper\n";
		entity.setPosition
		(
			tileBounds.width * (leftTopX + 1),
			entity.getPosition().y
		);
		entity.setVelocity(0.f, entity.getVelocity().y);
	}
}

void CollisionManager::handleRightCollisions(
	Entity& entity, std::vector<std::vector<short>>& tileMap, short rightTopX, short rightTopY, short rightBottomX, short rightBottomY)
{
	// Lower right side collision
	if (tileMap[rightBottomY - 1][rightBottomX] == GROUND)
	{
		std::cout << "right lower\n";
		std::cout << entity.getVelocity().x<<"\n";
		entity.setPosition
		(
			tileBounds.width * rightTopX - entity.getGlobalBounds().width -1.f,
			entity.getPosition().y
		);
		entity.setVelocity(0.f, entity.getVelocity().y);
	}
	// Upper right side collision
	else if (tileMap[rightTopY][rightTopX] == GROUND)
	{
		std::cout << "right upper\n";
		std::cout << entity.getVelocity().x << "\n";
		entity.setPosition
		(
			tileBounds.width * rightTopX - entity.getGlobalBounds().width - 1.f,
			entity.getPosition().y
		);
		entity.setVelocity(0.f, entity.getVelocity().y);
	}
}


void CollisionManager::handleCollisions(Entity& entity, TileMap& tileMap)
{
	std::vector<std::vector<short>>tileMapVector = tileMap.getMapVector();

	// These variables specify the indices that correspond to the corners of the character sprite on the tile map vector
	short leftTopX = floor(entity.getGlobalBounds().left / tileBounds.width);
	short leftTopY = floor(entity.getGlobalBounds().top/ tileBounds.height);
	
	short leftBottomX = leftTopX;
	short leftBottomY = floor((entity.getGlobalBounds().top + entity.getGlobalBounds().height) / tileBounds.height);

	short rightTopX = floor((entity.getGlobalBounds().left + entity.getGlobalBounds().width) / tileBounds.width);
	short rightTopY = leftTopY;

	short rightBottomX = rightTopX;
	short rightBottomY = floor((entity.getGlobalBounds().top + entity.getGlobalBounds().height) / tileBounds.height);

	short midTopX = floor((entity.getGlobalBounds().left + entity.getGlobalBounds().width+ entity.getGlobalBounds().left) / 2.f / tileBounds.width);
	short midTopY = floor(entity.getGlobalBounds().top / tileBounds.height);

	short midBottomX = floor((entity.getGlobalBounds().left + entity.getGlobalBounds().width + entity.getGlobalBounds().left) / 2.f / tileBounds.width);
	short midBottomY = floor((entity.getGlobalBounds().top + entity.getGlobalBounds().height) / tileBounds.height);

	bool topCollided = false;

	if (leftTopY < 0 || leftBottomY >= tileMapVector.size() || 
		leftTopX < 0 || rightTopX >= tileMapVector[0].size())
	{
		std::cout << "ERROR::CollisionManager::handleCollisions():: player is out of bounds\n";
	}
	else
	{

		handleBottomCollisions(entity, tileMapVector,  leftTopY, leftBottomY);

		handleTopCollisions(entity, tileMapVector, topCollided, leftTopX, leftTopY, rightTopX, rightTopY, midTopX, midTopY);

		if (topCollided == false) 
		{
			this->handleLeftCollisions(entity, tileMapVector, leftBottomX, leftBottomY, leftTopX, leftTopY);

			this->handleRightCollisions(entity, tileMapVector, rightTopX, rightTopY, rightBottomX, rightBottomY);
		}
	}
}

