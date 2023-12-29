#include "Player.h"

void Player::initVariables()
{
	this->animationClock.restart();
	this->animationFrameCount = 0;
	this->animationState = ANIMATION_STATES::IDLE;
	this->isGrounded = false;
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

	this->moveDirection = sf::Vector2f(0.f, 1.f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->moveDirection.x = 1.f;
		this->animationState = ANIMATION_STATES::MOVING_RIGHT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->moveDirection.x = -1.f;
		this->animationState = ANIMATION_STATES::MOVING_LEFT;
	}

	canJump = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && isGrounded ==true)
	{
		canJump = true;
		this->moveDirection.y = -1.f;
		//std::cout << "space\n";
		isGrounded = false;
	}
	//std::cout << this->velocity.y<<std::endl;

	// moves the sprite based on the velocity (it literally moves, changes the sprites position on window)
	this->sprite.move(this->velocity);
}

Player::Player()
{
	// Initialize members inherited from Entity class
	position = sf::Vector2f(0.f, 0.f);
	velocity = sf::Vector2f(0.f, 0.f);
	acceleration = sf::Vector2f(1.2f, 1.f);
	velocityMax = sf::Vector2f(20.f, 20.f);
	velocityMin = sf::Vector2f(1.f, 1.f);
	drag = sf::Vector2f(0.9f, 3.f);
	this->moveDirection = sf::Vector2f(0.f,0.f);;
	this->jumpForce = 30.f;
	this->canJump = false;

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

const sf::Vector2f& Player::getVelocityMax()
{
	return this->velocityMax;
}

const sf::Vector2f& Player::getVelocityMin()
{
	return this->velocityMin;
}

const sf::Vector2f& Player::getAcceleration()
{
	return this->acceleration;
}

const sf::Vector2f& Player::getDrag()
{
	return this->drag;
}

const sf::Vector2f& Player::getMoveDirection()
{
	return this->moveDirection;
}

const float& Player::getJumpForce()
{
	return jumpForce;
}

const bool& Player::getCanJump()
{
	// TODO: insert return statement here
	return this->canJump;
}

const sf::Vector2f& Player::getPosition()
{
	return this->sprite.getPosition();
}

void Player::setVelocity(float x, float y)
{
	this->velocity = sf::Vector2f(x, y);
}

void Player::setIsGrounded(bool grounded)
{
	this->isGrounded = grounded;
}

void Player::setPosition(float x, float y)
{
	sprite.setPosition(sf::Vector2f(x, y));
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
		this->sprite.setScale(2.f, 2.f);
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
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}