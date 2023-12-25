#include "Player.h"

void Player::initVariables()
{
	this->animationClock.restart();
	this->animationFrameCount = 0;
	this->animationState = ANIMATION_STATES::IDLE;
}

void Player::initTexture()
{
	if (!this->textureRun.loadFromFile("Textures/RobotRun.png"))
		std::cout << "PLAYER::initTexture()::ERROR::couldn't load the player texture sheet" << std::endl;
	if (!this->textureIdle.loadFromFile("Textures/RobotIdle.png"))
		std::cout << "PLAYER::initTexture()::ERROR::couldn't load the player texture sheet" << std::endl;

}

void Player::initSprite()
{
	this->sprite.setTexture(this->textureIdle);

	// respresents 1 frame in spriteSheet, in each sheet our character covers 100x100 pixel
	this->spriteFrame = sf::IntRect(0, 0, this->sprite.getGlobalBounds().width / 2.f, this->sprite.getGlobalBounds().height / 1.f);

	this->sprite.setTextureRect(this->spriteFrame);

	this->sprite.setScale(2.f, 2.f);
}

void Player::updateMovement()
{
	this->animationState = ANIMATION_STATES::IDLE;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->move(1.f, 0.f);
		this->animationState = ANIMATION_STATES::MOVING_RIGHT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && std::abs(this->velocity.x) < this->velocityMax.x)
	{
		this->move(-1.f, 0.f);
		this->animationState = ANIMATION_STATES::MOVING_LEFT;
	}
}

void Player::move(const float x_dir, const float y_dir)
{
	this->velocity.x += x_dir * this->acceleration.x;

	// limits the maximum amount of velocity
	if (std::abs(this->velocity.x) >= this->velocityMax.x)
	{
		if(this->velocity.x < 0.f)
			this->velocity.x = this->velocityMax.x * -1.f;
		else
			this->velocity.x = this->velocityMax.x * 1.f;
	}
}

void Player::updatePhysics()
{
	// applies drag
	this->velocity.x *= drag.x;

	// applies gravity
	this->velocity.y += this->drag.y;
	
	// Limits the velocity.y to based on the maxiumum value
	if (std::abs(this->velocity.y) > velocityMax.y)
	{
		if (this->velocity.y < 0.f)
		{
			this->velocity.y = this->velocityMax.y * -1.f;
		}
		else
		{
			this->velocity.y = this->velocityMax.y * 1.f;
		}
	}

	// Limits the velocity to based on the minimum value
	if (std::abs(this->velocity.x) < this->velocityMin.x)
	{
		this->velocity.x = 0.f;
	}
	if(std::abs(this->velocity.y) < this->velocityMin.y)
	{
		this->velocity.y = this->velocityMin.y;
	}

	// moves the sprite
	this->sprite.move(this->velocity);
}

Player::Player()
	: position(0.f, 0.f), velocity(0.f, 0.f), acceleration(1.2f, 0.f), velocityMax(20.f, 10.f), velocityMin(1.f, 1.f), drag(0.9f, 3.f)
{
	initTexture();
	initSprite();
}

Player::~Player()
{
}

const sf::Vector2f& Player::getVelocity() 
{
	return this->velocity;
}

const sf::Vector2f& Player::getPosition()
{
	return this->sprite.getPosition();
}

void Player::setVelocity(float x, float y)
{
	this->velocity = sf::Vector2f(x, y);
}

void Player::setPosition(float x, float y)
{
	sprite.setPosition(sf::Vector2f(x,y));
}

void Player::updateAnimations()
{
	if (this->animationState == ANIMATION_STATES::IDLE)
	{
		if (this->animationClock.getElapsedTime().asSeconds() > 0.2f)
		{
			if (this->spriteFrame.left > 100.f)
			{
				this->spriteFrame.left = 0.f;
			}
			this->animationClock.restart();
			this->sprite.setTexture(textureIdle);
			this->sprite.setTextureRect(spriteFrame);
			this->spriteFrame.left += this->spriteFrame.width;
		}
	}
	else if (this->animationState == ANIMATION_STATES::MOVING_RIGHT)
	{
		if (this->animationClock.getElapsedTime().asSeconds() > 0.1f)
		{
			if (this->spriteFrame.left > 700.f)
			{
				this->spriteFrame.left = 0.f;
			}
			this->animationClock.restart();
			this->sprite.setTexture(textureRun);
			this->sprite.setTextureRect(spriteFrame);
			this->spriteFrame.left += this->spriteFrame.width;
		}
		this->sprite.setScale(2.f,2.f);
		this->sprite.setOrigin(0.f, 0.f);
	}
	else if (this->animationState == ANIMATION_STATES::MOVING_LEFT)
	{
		if (this->animationClock.getElapsedTime().asSeconds() > 0.1f)
		{
			if (this->spriteFrame.left >= 700.f)
			{
				this->spriteFrame.left = 0.f;
			}
			this->animationClock.restart();
			this->sprite.setTexture(textureRun);
			this->sprite.setTextureRect(spriteFrame);
			this->spriteFrame.left += this->spriteFrame.width;
		}
		this->sprite.setScale(-2.f, 2.f);
		this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 2.5f + (this->sprite.getGlobalBounds().width / 5), 0.f);
	}

}

sf::FloatRect Player::getGlobalBounds()
{
	return this->sprite.getGlobalBounds();
}

void Player::update()
{
	this->updateMovement();
	this->updateAnimations();
	this->updatePhysics();
}

void Player::render(sf::RenderTarget& target)
{
	//target.draw(*currentSprite);
	target.draw(this->sprite);
}
