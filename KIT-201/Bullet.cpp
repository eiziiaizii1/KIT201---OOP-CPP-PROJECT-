#include "Bullet.h"

Bullet::Bullet(sf::Texture& texture, float posX, float posY, float directionX, float directionY, float movementSpeed)
{
	this->sprite.setTexture(texture);

	this->sprite.setPosition(posX, posY);
	this->sprite.scale(0.5f, 0.4f);
	this->direction.x = directionX;
	this->direction.y = directionY;
	this->movementSpeed = movementSpeed;
}

Bullet::~Bullet()
{
}

sf::FloatRect Bullet::getGlobalBounds() const
{
	return this->sprite.getGlobalBounds();
}

void Bullet::update()
{
	this->sprite.move(this->movementSpeed * this->direction);
}

void Bullet::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}