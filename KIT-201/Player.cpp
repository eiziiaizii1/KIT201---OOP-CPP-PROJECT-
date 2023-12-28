#include "Player.h"

void Player::initVariables()
{
	this->animationClock.restart();
	this->animationFrameCount = 0;
	this->animationState = ANIMATION_STATES::IDLE;
}

void Player::initTexture()
{
	/*if (!this->textureRun.loadFromFile("Textures/RobotRun.png"))
		std::cout << "PLAYER::initTexture()::ERROR::couldn't load the player texture sheet" << std::endl;
	if (!this->textureIdle.loadFromFile("Textures/RobotIdle.png"))
		std::cout << "PLAYER::initTexture()::ERROR::couldn't load the player texture sheet" << std::endl;*/

	if (!this->textureRun.loadFromFile("Textures/run resized.png"))
		std::cout << "PLAYER::initTexture()::ERROR::couldn't load the player texture sheet" << std::endl;
	if (!this->textureIdle.loadFromFile("Textures/idle resized.png"))
		std::cout << "PLAYER::initTexture()::ERROR::couldn't load the player texture sheet" << std::endl;

}

void Player::initSprite()
{
	//initially player is in idle animation
	this->sprite.setTexture(this->textureIdle);

	// respresents 1 frame in spriteSheet, in each sheet our character covers  pixel (setTextureREct gets IntRect parameter)
	this->spriteFrame = sf::IntRect(0, 0, this->sprite.getGlobalBounds().width / 2.f, this->sprite.getGlobalBounds().height / 1.f);

	this->sprite.setTextureRect(this->spriteFrame);

	this->sprite.setScale(2.f, 2.f);
}

void Player::updateMovement()
{
	this->animationState = ANIMATION_STATES::IDLE;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->move(1.f, 0.f); // moves physically
		this->animationState = ANIMATION_STATES::MOVING_RIGHT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->move(-1.f, 0.f); // moves physically
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
	// applies drag, helps to slow downs to player horizontally
	this->velocity.x *= drag.x;

	// applies gravity
	this->velocity.y += this->drag.y;
	
	// Limits the velocity.y to based on the maxiumum value
	if (std::abs(this->velocity.y) > velocityMax.y)
	{
		if (this->velocity.y < 0.f)
			this->velocity.y = this->velocityMax.y * -1.f;
		else
			this->velocity.y = this->velocityMax.y * 1.f;
	}

	// Limits the velocity to based on the minimum value
	// As we multiply velocity.x by drag.x velocity never reaches the zero, so we must make it 0 if it becomes less then a min value
	if (std::abs(this->velocity.x) < this->velocityMin.x)
	{
		this->velocity.x = 0.f;
	}
	if(std::abs(this->velocity.y) < this->velocityMin.y)
	{
		this->velocity.y = 0.f;
	}

	// moves the sprite based on the velocity (it literally moves, changes the sprites position)
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
		// sprite is set to next frame after 0.2 seconds
		if (this->animationClock.getElapsedTime().asSeconds() > 0.2f)
		{
			// there are 2 frames in idle each first frame start is (0, 0), 2nd's start  (0, 44)
			// we should start from beginning, if sprite is set to last frame
			if (this->spriteFrame.left > 44.f)
			{
				this->spriteFrame.left = 0.f;
			}
			this->animationClock.restart();
			this->sprite.setTexture(textureIdle);
			this->sprite.setTextureRect(spriteFrame);
			this->spriteFrame.left += this->spriteFrame.width; //next frame
		}
	}
	else if (this->animationState == ANIMATION_STATES::MOVING_RIGHT)
	{
		if (this->animationClock.getElapsedTime().asSeconds() > 0.1f)
		{
			if (this->spriteFrame.left > 308.f)
			{
				this->spriteFrame.left = 0.f;
			}
			this->animationClock.restart();
			this->sprite.setTexture(textureRun);
			this->sprite.setTextureRect(spriteFrame);
			this->spriteFrame.left += this->spriteFrame.width;
		}
		// we should scale by positive value to get rid of mirror effect
		// and the origin changes when we scale by minus so we should set origin back to (0, 0)
		this->sprite.setScale(2.f,2.f);
		this->sprite.setOrigin(0.f, 0.f); 
	}
	else if (this->animationState == ANIMATION_STATES::MOVING_LEFT)
	{
		if (this->animationClock.getElapsedTime().asSeconds() > 0.1f)
		{
			if (this->spriteFrame.left > 308.f)
			{
				this->spriteFrame.left = 0.f;
			}
			this->animationClock.restart();
			this->sprite.setTexture(textureRun);
			this->sprite.setTextureRect(spriteFrame);
			this->spriteFrame.left += this->spriteFrame.width;
		}
		// if we scale by minus we got mirror effect, our character is not symmetrical
		this->sprite.setScale(-2.f, 2.f);
		this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 2.f, 0.f);
	}

}

const sf::FloatRect& Player::getGlobalBounds()
{
	return this->sprite.getGlobalBounds();
}

// will be called each frame in game loop
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
