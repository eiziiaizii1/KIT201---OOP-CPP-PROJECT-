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
	//Defalult array size: 15 rows and 20 columns
	short rows = 15;
	short columns = 20;
	tileMap.resize(rows, std::vector<short>(columns, 0)); // 0 initalized (BACKGROUND)

	//TileMapParser uses method to generate the TileMap
	TileMapParser parser("Levels/TileMaps.txt");
	tileMap = parser.parseTileMap(2);

	/*for (int i = 12; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			tileMap[i][j] = GROUND;
		}
	}*/
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

sf::FloatRect TileMap::getTileGlobalBounds()
{
	return this->blockSprite.getGlobalBounds();
}

// basically return 2d map vector 
std::vector<std::vector<short>>& TileMap::getMapVectors()
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

	for (short i = 0; i < this->tileMap.size(); ++i) {
		for (short j = 0; j < this->tileMap[i].size(); ++j) {
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
