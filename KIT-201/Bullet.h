#pragma once
#include "SFML\Graphics.hpp"
#include "Player.h"

class Bullet
{
private:
	sf::Sprite sprite;
	bool toBeDestroyed;
	int damage;

	float direction; // direction that the bullet will move on x-axis (1.f = right, -1.f = left)
	float movementSpeed;
public:
	Bullet(sf::Texture& texture, Player& player);
	~Bullet();

	// Getters
	const sf::FloatRect& getGlobalBounds();
	const int getDamage();
	const bool getToBeDestroyed();

	// Setters
	void setToBeDestroyed(bool destroyStatus);

	void update();
	void render(sf::RenderTarget& target);
};
