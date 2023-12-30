#include "CollisionManager.h"

////DONE TODO 1: IMPLEMENT THE TOP COLLISSION ON Y-AXIS (DO IT AFTER CODING PLAYER JUMP)
////FIXED !!BUG3: GAME ABORTS WHEN PLAYER GOES BEYOND THE SCREEN
////FIXED MINOR BUG4: UNEXPECTED and glitchy BEHAVIOR WHEN the player enters a place that is 2 blocks high 
////FIXED MINOR BUG5: When llower, lupper, ltop happens at the same time player teleports to the lower part of the platform
////FIXED MINOR BUG1: Colliding with the side edges of the tile while airborne causes a glitch
////HALF-DONE TODO 2: We can make some variables in handleCollision() method constant, (it would be revise that after implementing other classes)
// MINOR BUG2: holding down to the cliff :D (My the god help me I dont know how to fix that)
// MINOR BUG6: When player is on the leftmost block's leftmost edge it falls (it is due to large player sprite width), can be fixed or minimized

CollisionManager::CollisionManager()
{
}

CollisionManager::~CollisionManager()
{
}

CollisionManager::CollisionManager(TileMap& tileMap)
{
	this->tileBounds = tileMap.getTileGlobalBounds();
}


void CollisionManager::handleCollisions(Player& player, TileMap& tileMap)
{
	sf::FloatRect playerBounds = player.getGlobalBounds();
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

	bool topCollided = false;

	/*std::cout << "Left top x: " << leftTopX  << std::endl;
	std::cout << "Left top y: " << leftTopY << std::endl;*/
	//std::cout << "Right top x: " << rightTopX << std::endl;
	//std::cout << "Right top y: " << rightTopY << std::endl;
	std::cout << player.getVelocity().y << std::endl;

	if (leftTopY < 0 || leftBottomY >= tileMapVector.size() || 
		leftTopX < 0 || rightTopX >= tileMapVector[0].size())
	{
		std::cout << "ERROR::CollisionManager::handleCollisions():: player is out of bounds\n";
	}
	else
	{
		// Bottom Collision
		if (tileMapVector[leftBottomY][leftBottomX] == GROUND || 
			tileMapVector[rightBottomY][rightBottomX] == GROUND || 
			tileMapVector[leftBottomY][(leftBottomX + rightBottomX) / 2] == GROUND)
		{
			std::cout << "BOTTOM\n";
			player.setPosition
			(
				player.getPosition().x,
				tileBounds.height * leftBottomY - playerBounds.height
			);
			player.setVelocity(player.getVelocity().x, 0.f);
			//player.setIsGrounded(true);
		}

		if (tileMapVector[leftBottomY][(leftBottomX + rightBottomX) / 2] == GROUND)
		{
			player.setIsGrounded(true);
		}
		else
		{
			player.setIsGrounded(false);
		}

		// Top Collision
		if (player.getVelocity().y < 0 && 
			   (tileMapVector[leftTopY][leftTopX] == GROUND ||
				tileMapVector[rightTopY][rightTopX] == GROUND ||
				tileMapVector[leftTopY][(leftTopX + rightTopX) / 2] == GROUND))
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

		if (topCollided == false) 
		{
			// Lower left side collision
			if (player.getVelocity().x < 0.f && 
				(tileMapVector[leftBottomY - 1][leftBottomX] == GROUND))
			{
				std::cout << "left lower\n";
				player.setPosition
				(
					tileBounds.width * (leftTopX + 1),
					player.getPosition().y
				);
				player.setVelocity(0.f, player.getVelocity().y);
			}
			// Upper left side collision
			else if (player.getVelocity().x < 0.f && tileMapVector[leftTopY][leftTopX] == GROUND)
			{
				std::cout << "left upper\n";
				player.setPosition
				(
					tileBounds.width * (leftTopX + 1),
					player.getPosition().y
				);
				player.setVelocity(0.f, player.getVelocity().y);
			}


			// Lower right side collision
			if (player.getVelocity().x > 0.f && tileMapVector[rightBottomY - 1][rightBottomX] == GROUND)
			{
				std::cout << "right lower\n";
				player.setPosition
				(
					tileBounds.width * rightTopX - playerBounds.width,
					player.getPosition().y
				);
				player.setVelocity(0.f, player.getVelocity().y);
			}
			// Upper right side collision
			else if (player.getVelocity().x > 0.f && tileMapVector[rightTopY][rightTopX] == GROUND)
			{
				std::cout << "right upper\n";
				player.setPosition
				(
					tileBounds.width * rightTopX - playerBounds.width,
					player.getPosition().y
				);
				player.setVelocity(0.f, player.getVelocity().y);
			}
		}
	}
}

