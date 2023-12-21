#pragma once
#include "SFML\Graphics.hpp"
#include <iostream>
#include <vector>


enum TileType {BACKGROUND = 0, GROUND = 1 };

class TileMap
{
private:
	sf::Texture blockTexture;
	sf::Sprite blockSprite;

	std::vector<std::vector<short>> tileMap;

	void initTextures();
	void initSprites();
	void initDefaultMap();
public:
	TileMap();
	TileMap(std::vector<std::vector<short>>& tileMap);
	~TileMap();

	void update();
	void render(sf::RenderTarget& target);
};

