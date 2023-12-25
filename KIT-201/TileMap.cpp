#include "TileMap.h"

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
	//Defalult array size: 15 rows and 20 columns
	short rows = 15;
	short columns = 20;
	tileMap.resize(rows, std::vector<short>(columns, 0)); // 0 initalized (BACKGROUND)

	for (int i = 12; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			tileMap[i][j] = GROUND;
		}
	}
}

TileMap::TileMap()
{
	initTextures();
	initSprites();
	initDefaultMap();
}

TileMap::TileMap(std::vector<std::vector<short>>& tileMap)
{
	this->tileMap = tileMap;
}

TileMap::~TileMap()
{
}

sf::FloatRect TileMap::getTileGlobalBounds()
{
	return this->blockSprite.getGlobalBounds();
}

std::vector<std::vector<short>>& TileMap::getMapVectors()
{
	return this->tileMap;
}

void TileMap::update()
{
}

void TileMap::render(sf::RenderTarget& target)
{
	// Our sprite is square
	float tileSize = this->blockSprite.getGlobalBounds().height;

	for (short i = 0; i < this->tileMap.size(); ++i) {
		for (short j = 0; j < this->tileMap[i].size(); ++j) {
			if (tileMap[i][j] == GROUND)
			{
				float renderPosY = static_cast<float>(i * tileSize);
				float renderPosX = static_cast<float>(j * tileSize);
				
				this->blockSprite.setPosition(renderPosX, renderPosY);
				target.draw(this->blockSprite);
			}
		}
	}
}
