#pragma once
#include "SFML\Graphics.hpp"

class Bullet
{
private:
	sf::Sprite sprite;

	sf::Vector2f direction;
	float movementSpeed;
public:
	Bullet(sf::Texture& texture, float posX, float posY, float directionX, float directionY, float movementSpeed);
	~Bullet();

	//Accessors / Getters
	sf::FloatRect getGlobalBounds() const;

	void update();
	void render(sf::RenderTarget& target);
};

