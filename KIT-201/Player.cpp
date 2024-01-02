#include "Player.h"

void Player::initVariables()
{
	this->animationClock.restart();
	this->shootClock.restart();
	this->animationState = ANIMATION_STATES::IDLE;
	this->isGrounded = false;
	this->canShoot = false;
	this->lookDirection = 1.f;
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
		this->lookDirection = 1.f;
		this->animationState = ANIMATION_STATES::MOVING_RIGHT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->moveDirection.x = -1.f;
		this->lookDirection = -1.f;
		this->animationState = ANIMATION_STATES::MOVING_LEFT;
	}

	canJump = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && isGrounded ==true)
	{
		canJump = true;
		this->moveDirection.y = -1.f;
		isGrounded = false;
	}

	// moves the sprite based on the velocity (it literally moves, changes the sprites position on window)
	this->sprite.move(this->velocity);
}

void Player::updateShootStatus()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && shootClock.getElapsedTime().asSeconds() > 0.4f)
	{
		this->canShoot = true;
		this->shootClock.restart();
	}
	else
	{
		this->canShoot = false;
	}
}

Player::Player()
{
	// Initialize members inherited from Entity class
	velocity = sf::Vector2f(0.f, 0.f);
	acceleration = sf::Vector2f(1.2f, 1.f);
	velocityMax = sf::Vector2f(20.f, 20.f);
	velocityMin = sf::Vector2f(1.f, 1.f);
	drag = sf::Vector2f(0.9f, 3.f);
	moveDirection = sf::Vector2f(0.f,0.f);;
	jumpForce = 30.f;
	canJump = false;

	initVariables();
	initTexture();
	initSprite();
}

Player::~Player()
{
}

const bool Player::getCanShoot()
{
	return this->canShoot;
}

const float Player::getLookDirection()
{
	return this->lookDirection;
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

// will be called each frame in game loop
void Player::update()
{
	this->updateMovement();
	this->updateAnimations();
	this->updateShootStatus();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
