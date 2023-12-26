#include "CollisionManager.h"

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

	bool isNextToBlock =false;

	for (short i = 0; i < tileMapVector.size(); ++i) {
		for (short j = 0; j < tileMapVector[i].size(); ++j) {

			if (tileMapVector[i][j] == TileType::GROUND)
			{
				sf::FloatRect currentTile = sf::FloatRect(j * tileBounds.width, i * tileBounds.height, tileBounds.width, tileBounds.height);

				if (playerBounds.intersects(currentTile))
				{
					// handle lower collision 
					if (player.getVelocity().y > 0)
					{
						player.setPosition(player.getPosition().x, currentTile.top - playerBounds.height);
						player.setVelocity(player.getVelocity().x, 0.f);
					}
				}
			}
		}	
	}
}
