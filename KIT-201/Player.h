#pragma once
#include "SFML\Graphics.hpp"
#include <iostream>

class Player
{
private:
	sf::Texture texture;
	sf::Sprite sprite;

	void initTexture();
	void initSprite();
public:

	Player();
	~Player();

	void update();
	void render(sf::RenderTarget& target);
};

