#pragma once
#include "SFML\Graphics.hpp"
#include <iostream>
#include <vector>

// Tile type determined by the enumaration
enum TileType {BACKGROUND = 0, GROUND = 1 };

class TileMap
{
private:
	//There is only 1 sprite, if the tile value is equal to GROUND it will render that specific tile as sprite texture 
	sf::Texture blockTexture;
	sf::Sprite blockSprite;

	std::vector<std::vector<short>> tileMap;

	// init functions are for constructor
	void initTextures();
	void initSprites();
	void initDefaultMap(); // default map is for testing
public:
	TileMap();
	TileMap(std::vector<std::vector<short>>& tileMap);
	~TileMap();

	//Getters
	const sf::FloatRect& getTileGlobalBounds() const;
	std::vector<std::vector<short>>& getMapVectors();

	void update();
	void render(sf::RenderTarget& target);
};

