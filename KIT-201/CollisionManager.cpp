#include "CollisionManager.h"

//// DONE TODO 1: IMPLEMENT THE TOP COLLISSION ON Y-AXIS (DO IT AFTER CODING PLAYER JUMP)
// TODO 2: We can make some variables in handleCollision() method constant (for better performance)
//// FIXED - MINOR BUG1: Colliding with the side edges of the tile while airborne causes a glitch
// MINOR BUG2: holding down to the cliff :D
// !!!BUG3: GAME ABORTS WHEN PLAYER GOES BEYOND THE SCREEN
// MINOR BUG4: UNEXPECTED and glitchy BEHAVIOR WHEN the player enters a place that is 2 blocks high 
//			   (player's height 66, block's height is 64)
// MINOR BUG5: When llower, lupper, ltop happens at the same time player teleports to the lower part of the platform

CollisionManager::CollisionManager()
{
}

CollisionManager::~CollisionManager()
{
}

void CollisionManager::handleCollisions(Player& player, TileMap& tileMap)
{
	sf::FloatRect playerBounds = player.getGlobalBounds();
	sf::FloatRect tileBounds = tileMap.getTileGlobalBounds();
	std::vector<std::vector<short>>tileMapVector = tileMap.getMapVectors();


	// These variables specify the indices that correspond to the corners of the character sprite on the tile map vector
	short leftTopX = floor(playerBounds.left / tileBounds.width);
	short leftTopY = floor(playerBounds.top/ tileBounds.height);
	
	short leftBottomX = leftTopX;
	short leftBottomY = floor((playerBounds.top + playerBounds.height) / tileBounds.height);

	short rightTopX = floor((playerBounds.left + playerBounds.width) / tileBounds.width);
	short rightTopY = leftTopY;

	short rightBottomX = rightTopX;
	short rightBottomY = floor((playerBounds.top + playerBounds.height) / tileBounds.height);



	// Bottom Collision
	if (leftBottomY + 1 < tileMapVector.size() &&
		(tileMapVector[leftBottomY][leftBottomX] == GROUND) || (tileMapVector[rightBottomY][rightBottomX] == GROUND))
	{
		player.setPosition
		(
			player.getPosition().x,
			tileBounds.height * leftBottomY - playerBounds.height
		);
		player.setVelocity(player.getVelocity().x, 0.f);
		player.setIsGrounded(true);
	}

	// Top Collision
	if (tileMapVector[leftTopY][leftTopX] == GROUND || tileMapVector[rightTopY][rightTopX] == GROUND)
	{
		std::cout << "lt\n";
		player.setPosition
		(
			player.getPosition().x,
			tileBounds.height * (leftTopY+1)
		);
		player.setVelocity(player.getVelocity().x, 0.f);
	}

	// Lower left side collision
	if (leftBottomX - 1 > 0 && tileMapVector[leftBottomY-1][leftBottomX] == GROUND)
	{
		std::cout << "llower\n";
		player.setPosition
		(
			tileBounds.width * (leftTopX+1),
			player.getPosition().y
		);
		player.setVelocity(0, player.getVelocity().y);
	}
	// Lower right side collision
	else if (rightBottomX + 1 < tileMapVector[0].size() && tileMapVector[rightBottomY - 1][rightBottomX] == GROUND)
	{
		std::cout << "rlower\n";
		player.setPosition
		(
			tileBounds.width * rightTopX - playerBounds.width,
			player.getPosition().y
		);
		player.setVelocity(0, player.getVelocity().y);
	}

	// Upper left side collision
	if (leftTopX - 1 > 0 && tileMapVector[leftTopY+1][leftTopX] == GROUND )
	{
		std::cout << "lupper\n";
		player.setPosition
		(
			tileBounds.width * (leftTopX + 1),
			player.getPosition().y
		);
		player.setVelocity(0, player.getVelocity().y);
	}

	// Upper right side collision
	else if (rightTopX + 1 < tileMapVector[0].size() && tileMapVector[rightTopY+1][rightTopX] == GROUND)
	{
		std::cout << "rupper\n";
		player.setPosition
		(
			tileBounds.width * rightTopX - playerBounds.width,
			player.getPosition().y
		);
		player.setVelocity(0, player.getVelocity().y);
	}

}
