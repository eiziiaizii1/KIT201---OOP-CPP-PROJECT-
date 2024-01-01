#pragma once
#include "SFML\Graphics.hpp"
#include "Player.h"

class Bullet
{
private:
	sf::Sprite sprite;

	float direction; // direction that the bullet will move on x-axis (1.f = right, -1.f = left)
	float movementSpeed;
public:
	Bullet(sf::Texture& texture, Player& player);
	~Bullet();

	//Accessors / Getters
	sf::FloatRect getGlobalBounds() const;

	void update();
	void render(sf::RenderTarget& target);
};
