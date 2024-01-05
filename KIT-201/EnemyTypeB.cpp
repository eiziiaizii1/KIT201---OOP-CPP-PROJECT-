#include "EnemyTypeB.h"

#include "EnemyTypeA.h"

void EnemyTypeB::initVariables()
{
	animationClock.restart();
	moveClock.restart();
	maxHealth = 60;
	health = maxHealth;
	damage = 5;
	animationState = ANIMATION_STATES::IDLE;
}

void EnemyTypeB::initTexture()
{
	if (!textureIdle.loadFromFile("Textures/EnemyB_Idle.png"))
		std::cout << "ERROR:: CANNOT LOAD THE ENEMY-B IDLE TEXTURE\n";
	if (!textureRun.loadFromFile("Textures/EnemyB_Run.png"))
		std::cout << "ERROR:: CANNOT LOAD THE ENEMY-B RUN TEXTURE\n";

}

void EnemyTypeB::initSprite()
{
	sprite.setTexture(textureIdle);
	spriteFrame = sf::IntRect(0, 0, this->sprite.getGlobalBounds().width / 6.f, this->sprite.getGlobalBounds().height / 1.f);
	spriteFrameRun = sf::IntRect(0, 0, this->textureRun.getSize().x / 7.f, this->textureRun.getSize().y / 1.f);
	sprite.setScale(2.f, 2.f);
}

void EnemyTypeB::updateAnimations()
{
	if (this->animationState == ANIMATION_STATES::IDLE)
	{
		// sprite is set to next frame after 0.2 seconds
		if (this->animationClock.getElapsedTime().asSeconds() > 0.2f)
		{
			// there are 2 frames in idle each first frame start is (0, 0), 2nd's start  (0, 44)
			// we should start from beginning, if sprite is set to last frame
			if (this->spriteFrame.left > 150.f)
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
		if (this->animationClock.getElapsedTime().asSeconds() > 0.2f)
		{
			if (this->spriteFrameRun.left > 240.f)
			{
				this->spriteFrameRun.left = 0.f;
			}
			this->animationClock.restart();
			this->sprite.setTexture(textureRun);
			this->sprite.setTextureRect(spriteFrameRun);
			this->spriteFrameRun.left += this->spriteFrameRun.width;
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
			if (this->spriteFrameRun.left > 240.f)
			{
				this->spriteFrameRun.left = 0.f;
			}
			this->animationClock.restart();
			this->sprite.setTexture(textureRun);
			this->sprite.setTextureRect(spriteFrameRun);
			this->spriteFrameRun.left += this->spriteFrameRun.width;
		}
		// if we scale by minus we got mirror effect, our character is not symmetrical
		this->sprite.setScale(-2.f, 2.f);
		this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 2.f, 0.f);
	}
}

void EnemyTypeB::updateMovement()
{
	this->animationState = ANIMATION_STATES::IDLE;
	this->moveDirection = sf::Vector2f(0.f, 1.f);

	float elapsedTime = moveClock.getElapsedTime().asSeconds();
	const float totalTime = 4.f; // Total time for one cycle (2s + 2s + 2s)

	if (elapsedTime <= 1.f) {
		this->moveDirection.x = 1.f;
		this->animationState = ANIMATION_STATES::MOVING_RIGHT;
	}
	else if (elapsedTime <= 2.f) {
		this->moveDirection.x = 0.f;
		this->animationState = ANIMATION_STATES::IDLE;
	}
	else if (elapsedTime <= 3.f) {
		this->moveDirection.x = -1.f;
		setVelocity(getVelocity().x, getVelocity().y);
		this->animationState = ANIMATION_STATES::MOVING_LEFT;
	}
	else {
		// Reset the clock and wait for 2 seconds
		if (elapsedTime >= totalTime) {
			this->moveDirection.x = 0.f;
			this->animationState = ANIMATION_STATES::IDLE;
			moveClock.restart();
		}
	}



	// moves the sprite based on the velocity (it literally moves, changes the sprites position on window)
	sprite.move(velocity);
}

EnemyTypeB::EnemyTypeB()
{
	// Initialize members inherited from Entity class
	// This is a moving enemy
	velocity = sf::Vector2f(0.f, 0.f);
	acceleration = sf::Vector2f(1.2f, 1.f);
	velocityMax = sf::Vector2f(20.f, 20.f);
	velocityMin = sf::Vector2f(1.f, 1.f);
	drag = sf::Vector2f(0.9f, 3.f);
	moveDirection = sf::Vector2f(0.f, 0.f);;
	jumpForce = 0.f;

	canJump = false;
	isGrounded = false;

	initVariables();
	initTexture();
	initSprite();
}

void EnemyTypeB::update()
{
	updateAnimations();
	updateMovement();

	isHit = false;
}
