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

void CollisionManager::handleBottomCollisions(Player& player, std::vector<std::vector<short>>& tileMap, short leftTopY, short leftBottomY)
{
	//as we only need these variables here, we don't need to calculate them in handleCollisions() function
	float offSet = (player.getGlobalBounds().width - tileBounds.width) / 2.f;

	short leftMidBottomX = floor((player.getGlobalBounds().left + offSet) / tileBounds.width);
	short rightMidBottomX = floor(((player.getGlobalBounds().left + player.getGlobalBounds().width - offSet)) / tileBounds.width);

	// Bottom Collision
	// entity's y index is same for all bottom parts no need to recalculate BottomY index 
	if (tileMap[leftBottomY][leftMidBottomX] == GROUND ||
		tileMap[leftBottomY][rightMidBottomX] == GROUND)
	{
		std::cout << "BOTTOM\n";
		player.setPosition
		(
			player.getPosition().x,
			tileBounds.height * leftTopY
		);
		player.setVelocity(player.getVelocity().x, 0.f);

		// Setting 'isGrounded' to true here will prevent the player from jumping while falling down.
		
		player.setIsGrounded(true);
	}
	else
	{
		player.setIsGrounded(false);
	}
}

void CollisionManager::handleTopCollisions(
	Player& player, std::vector<std::vector<short>>& tileMap, bool& topCollided, 
	short leftTopX, short leftTopY, short rightTopX, short rightTopY, short midTopX, short midTopY)
{
	if (player.getVelocity().y < 0 &&
		(tileMap[leftTopY][leftTopX] == GROUND ||
			tileMap[rightTopY][rightTopX] == GROUND ||
			tileMap[midTopY][midTopX] == GROUND))
	{
		topCollided = true;
		std::cout << "TOP\n";
		player.setPosition
		(
			player.getPosition().x,
			tileBounds.height * (leftTopY + 1)
		);
		player.setVelocity(player.getVelocity().x, 0.f);
	}
}

void CollisionManager::handleLeftCollisions(
	Player& player, std::vector<std::vector<short>>& tileMap, short leftBottomX, short leftBottomY, short leftTopX, short leftTopY)
{
	// Lower left side collision
	if (tileMap[leftBottomY - 1][leftBottomX] == GROUND)
	{
		std::cout << "left lower\n";
		player.setPosition
		(
			tileBounds.width * (leftTopX + 1),
			player.getPosition().y
		);
		player.setCollisionSide(0);
		player.setVelocity(0.f, player.getVelocity().y);
	}
	// Upper left side collision
	else if (tileMap[leftTopY][leftTopX] == GROUND)
	{
		std::cout << "left upper\n";
		player.setPosition
		(
			tileBounds.width * (leftTopX + 1),
			player.getPosition().y
		);
		player.setCollisionSide(0);
		player.setVelocity(0.f, player.getVelocity().y);
	}
}

void CollisionManager::handleRightCollisions(
	Player& player, std::vector<std::vector<short>>& tileMap, short rightTopX, short rightTopY, short rightBottomX, short rightBottomY)
{
	// Lower right side collision
	if (tileMap[rightBottomY - 1][rightBottomX] == GROUND)
	{
		std::cout << "right lower\n";
		std::cout << player.getVelocity().x<<"\n";
		player.setPosition
		(
			tileBounds.width * rightTopX - player.getGlobalBounds().width,
			player.getPosition().y
		);
		player.setCollisionSide(1);
		player.setVelocity(0.f, player.getVelocity().y);
	}
	// Upper right side collision
	else if (tileMap[rightTopY][rightTopX] == GROUND)
	{
		std::cout << "right upper\n";
		std::cout << player.getVelocity().x << "\n";
		player.setPosition
		(
			tileBounds.width * rightTopX - player.getGlobalBounds().width,
			player.getPosition().y
		);
		player.setCollisionSide(1);
		player.setVelocity(0.f, player.getVelocity().y);
	}
}


void CollisionManager::handleCollisions(Player& player, TileMap& tileMap)
{
	std::vector<std::vector<short>>tileMapVector = tileMap.getMapVector();

	// These variables specify the indices that correspond to the corners of the character sprite on the tile map vector
	short leftTopX = floor(player.getGlobalBounds().left / tileBounds.width);
	short leftTopY = floor(player.getGlobalBounds().top/ tileBounds.height);
	
	short leftBottomX = leftTopX;
	short leftBottomY = floor((player.getGlobalBounds().top + player.getGlobalBounds().height) / tileBounds.height);

	short rightTopX = floor((player.getGlobalBounds().left + player.getGlobalBounds().width) / tileBounds.width);
	short rightTopY = leftTopY;

	short rightBottomX = rightTopX;
	short rightBottomY = floor((player.getGlobalBounds().top + player.getGlobalBounds().height) / tileBounds.height);

	short midTopX = floor((player.getGlobalBounds().left + player.getGlobalBounds().width+ player.getGlobalBounds().left) / 2.f / tileBounds.width);
	short midTopY = floor(player.getGlobalBounds().top / tileBounds.height);

	short midBottomX = floor((player.getGlobalBounds().left + player.getGlobalBounds().width + player.getGlobalBounds().left) / 2.f / tileBounds.width);
	short midBottomY = floor((player.getGlobalBounds().top + player.getGlobalBounds().height) / tileBounds.height);

	bool topCollided = false;

	if (leftTopY < 0 || leftBottomY >= tileMapVector.size() || 
		leftTopX < 0 || rightTopX >= tileMapVector[0].size())
	{
		std::cout << "ERROR::CollisionManager::handleCollisions():: player is out of bounds\n";
	}
	else
	{
		player.setCollisionSide(0);

		handleBottomCollisions(player, tileMapVector,  leftTopY, leftBottomY);

		handleTopCollisions(player, tileMapVector, topCollided, leftTopX, leftTopY, rightTopX, rightTopY, midTopX, midTopY);

		if (topCollided == false) 
		{
			this->handleLeftCollisions(player, tileMapVector, leftBottomX, leftBottomY, leftTopX, leftTopY);

			this->handleRightCollisions(player, tileMapVector, rightTopX, rightTopY, rightBottomX, rightBottomY);
		}
	}
}

