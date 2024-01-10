#include "Bullet.h"

// TODO-1: Initial bullet position adjustment

// Spawns the bullet based on the position of player's position, rotation, and velocityMax
Bullet::Bullet(sf::Texture& texture, Player& player)
{
	this->sprite.setTexture(texture);
	this->direction = player.getLookDirection();
	this->toBeDestroyed = false;
	this->damage = 10;

	if (this->direction == 1.f)
	{
		this->sprite.scale(0.5f, 0.5f);
		this->sprite.setPosition(
			player.getPosition().x + player.getGlobalBounds().width/2.5f, 
			player.getPosition().y + player.getGlobalBounds().height / 12.f);
		this->movementSpeed = player.getVelocityMax().x;
	}
	else
	{
		this->sprite.scale(-0.5f, 0.5f);
		this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 0.5f, 0.f);
		
		this->sprite.setPosition(
			player.getPosition().x - player.getGlobalBounds().width / 2.5f,
			player.getPosition().y + player.getGlobalBounds().height / 12.f);
		this->movementSpeed = -player.getVelocityMax().x;
	}
}

Bullet::~Bullet()
{
}

const sf::FloatRect Bullet::getGlobalBounds()
{
	return this->sprite.getGlobalBounds();
}

const int Bullet::getDamage()
{
	return this->damage;
}

const bool Bullet::getToBeDestroyed()
{
	return this->toBeDestroyed;
}

const sf::Vector2f& Bullet::getPosition()
{
	return sprite.getPosition();
}

void Bullet::setToBeDestroyed(bool destroyStatus)
{
	this->toBeDestroyed = destroyStatus;
}

// Updates the bullet's sprite position based on its speed
void Bullet::update()
{
	this->sprite.move(this->movementSpeed, 0.f);
}

void Bullet::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}