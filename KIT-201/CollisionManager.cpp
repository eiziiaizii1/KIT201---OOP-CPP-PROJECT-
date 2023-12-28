#include "CollisionManager.h"

// TODO 1: IMPLEMENT THE TOP COLLISSION ON Y-AXIS (DO IT AFTER CODING PLAYER JUMP)
// TODO 2: We can make some variables in handleCollision() method constant (for better performance)
// FIXED - MINOR BUG1 : Colliding with the side edges of the tile while airborne causes a glitch
// MINOR BUG2 : holding down to the cliff :D

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
		//std::cout << "left: "<<leftBottomX <<	"	right: " << rightBottomX << std::endl;
		std::cout << "a" << std::endl;
		player.setVelocity(player.getVelocity().x, 0.f);
	}

	// Lower left side collision
	if (leftBottomX - 1 > 0 && tileMapVector[leftBottomY-1][leftBottomX] == GROUND)
	{
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
		player.setPosition
		(
			tileBounds.width * rightTopX - playerBounds.width,
			player.getPosition().y
		);
		player.setVelocity(0, player.getVelocity().y);
	}

	// Upper left side collision
	if (leftTopX - 1 > 0 && tileMapVector[leftTopY][leftTopX] == GROUND )
	{
		player.setPosition
		(
			tileBounds.width * (leftTopX + 1),
			player.getPosition().y
		);
		player.setVelocity(0, player.getVelocity().y);
	}

	// Upper right side collision
	else if (rightTopX + 1 < tileMapVector[0].size() && tileMapVector[rightTopY][rightTopX] == GROUND)
	{
		player.setPosition
		(
			tileBounds.width * rightTopX - playerBounds.width,
			player.getPosition().y
		);
		player.setVelocity(0, player.getVelocity().y);
	}

}
