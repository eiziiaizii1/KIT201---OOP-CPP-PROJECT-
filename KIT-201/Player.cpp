#include "Player.h"

void Player::initVariables()
{
	this->animationCounter = 0;
	this->animationFrameCount = 0;
}

void Player::initTexture()
{
	if (!this->texture.loadFromFile("Textures/RobotRun.png"))
		std::cout << "PLAYER::initTexture()::ERROR::couldn't load the player texture sheet" << std::endl;
}

void Player::initSprite()
{
	this->sprite.setTexture(this->texture);	

	// respresents 1 frame in spriteSheet (specifically, running sprite sheet)
	this->spriteFrame = sf::IntRect(0, 0, this->sprite.getGlobalBounds().width / 8.f, this->sprite.getGlobalBounds().height / 1.f);

	//	1st row,	width:800 / 8 = 100,		height:100 / 1 = 100  
	this->sprite.setTextureRect(this->spriteFrame);

	this->sprite.setScale(2.f, 2.f);
}

void Player::handleInputs()
{
	if (std::abs(velocity.x) <= velocityMin.x)
	{
		velocity.x = 0.f;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && std::abs(this->velocity.x) < this->velocityMax.x)
	{
		
		this->sprite.setScale(2.f, 2.f);
		this->sprite.setOrigin(0.f, 0.f);
		this->velocity.x += acceleration.x;
		updateAnimations();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && std::abs(this->velocity.x) < this->velocityMax.x)
	{
		this->sprite.setScale(-2.f, 2.f);

		// Character covers nearly 1/2.5 of the texture rect ,so divide it by 2.5 then to make it smoother add the 1/5 of texture rect
		this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 2.5f +( this->sprite.getGlobalBounds().width / 5), 0.f);

		this->velocity.x -= acceleration.x;
		updateAnimations();
	}
	this->velocity.x *= this->drag.x;
}

void Player::move()
{
	this->sprite.move(this->velocity);
}

Player::Player()
	: position(0.f, 0.f), velocity(0.f, 0.f), acceleration(1.15f, 0.f), velocityMax(20.f, 10.f), velocityMin(1.f, 0.f), drag(0.9f, 0.f)
{
	initTexture();
	initSprite();
}

Player::~Player()
{
}

void Player::updateAnimations()
{
	if (animationCounter >= 5)
	{
		if (animationFrameCount >= 7)
		{
			animationFrameCount = 0;
		}
		
		this->spriteFrame = sf::IntRect(spriteFrame.width * animationFrameCount, 0, spriteFrame.width, spriteFrame.height);
		this->sprite.setTextureRect(this->spriteFrame);
		animationFrameCount++;
		animationCounter = 0;
	}
	else
		animationCounter++;
}

void Player::update()
{
	this->handleInputs();
	this->move();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
