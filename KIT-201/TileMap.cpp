#include "TileMap.h"
#include "TileMapParser.h"

void TileMap::initTextures()
{
	if (!this->blockTexture.loadFromFile("Textures/block.png"))
		std::cout << "TileMap::initTextures::ERROR::couldn't load the tile map textures" << std::endl;
}

void TileMap::initSprites()
{
	this->blockSprite.setTexture(this->blockTexture);
}

void TileMap::initDefaultMap()
{
	TileMapParser parser("Levels/TileMaps.txt");
	tileMap = parser.parseTileMap(2);
}

TileMap::TileMap()
{
	initTextures();
	initSprites();
	initDefaultMap();
}

// it will make easier to create specific tile map from other classes
TileMap::TileMap(std::vector<std::vector<short>>& tileMap)
{
	this->tileMap = tileMap;
}

TileMap::~TileMap()
{
}

const sf::FloatRect& TileMap::getTileGlobalBounds() const
{
	return this->blockSprite.getGlobalBounds();
}

// basically return 2d map vector 
const std::vector<std::vector<short>>& TileMap::getMapVector()
{
	return this->tileMap;
}

void TileMap::update()
{
}

void TileMap::render(sf::RenderTarget& target)
{
	// Our tile(block) sprite is a square so each edge is equal
	float tileSize = this->blockSprite.getGlobalBounds().height;

	for (int i = 0; i < this->tileMap.size(); ++i) {
		for (int j = 0; j < this->tileMap[i].size(); ++j) {
			if (tileMap[i][j] == GROUND)
			{
				float renderPosY = i * tileSize;
				float renderPosX = j * tileSize;
				
				this->blockSprite.setPosition(renderPosX, renderPosY);
				target.draw(this->blockSprite);
			}
		}
	}
}
