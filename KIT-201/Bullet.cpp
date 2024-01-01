#include "Bullet.h"

// TODO-1: Initial bullet position adjustment

Bullet::Bullet(sf::Texture& texture, Player& player)
{
	this->sprite.setTexture(texture);
	this->direction = player.getLookDirection();

	if (this->direction == 1.f)
	{
		this->sprite.scale(0.5f, 0.5f);
		this->sprite.setPosition(player.getPosition().x, player.getPosition().y);
		this->movementSpeed = player.getVelocityMax().x;
	}
	else
	{
		this->sprite.scale(-0.5f, 0.5f);
		this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 0.5f, 0.f);
		
		this->sprite.setPosition(player.getPosition());
		this->movementSpeed = -player.getVelocityMax().x;
	}
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
	this->sprite.move(this->movementSpeed, 0.f);
}

void Bullet::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}