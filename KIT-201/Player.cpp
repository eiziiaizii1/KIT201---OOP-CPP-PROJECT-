#include "Player.h"

void Player::initTexture()
{
	if (!this->texture.loadFromFile("Textures/RobotRun.png"))
		std::cout << "PLAYER::initTexture()::ERROR::couldn't load the player texture sheet" << std::endl;
}

void Player::initSprite()
{
	this->sprite.setTexture(this->texture);	

	//	1st row,	width:800 / 8 = 100,		height:100 / 1 = 100  
	this->sprite.setTextureRect(sf::IntRect(0, 0, 100, 100));
	this->sprite.setScale(2.f, 2.f);
}

Player::Player()
{
	initTexture();
	initSprite();
}

Player::~Player()
{
}

void Player::update()
{
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
