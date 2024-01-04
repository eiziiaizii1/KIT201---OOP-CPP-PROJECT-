#include "EnemyTypeA.h"

void EnemyTypeA::initVariables()
{
	animationClock.restart();
	turnBackCounter = 0;
	health = 30;
	damage = 10;
	animationState = ANIMATION_STATES::IDLE;
	turnBackCounter = 0;
}

void EnemyTypeA::initTexture()
{
	if (!textureIdle.loadFromFile("Textures/EnemyA_Idle.png"))
		std::cout << "ERROR:: CANNOT LOAD THE ENEMT1 TEXTURE\n";
}

void EnemyTypeA::initSprite()
{
	sprite.setTexture(textureIdle);
	spriteFrame = sf::IntRect(0, 0, this->sprite.getGlobalBounds().width / 7.f, this->sprite.getGlobalBounds().height / 1.f);
	sprite.setScale(2.f, 2.f);
}

void EnemyTypeA::updateAnimations()
{
	if (animationClock.getElapsedTime().asSeconds() > 0.2f) {
		if (animationState == ANIMATION_STATES::IDLE) {
			if (this->spriteFrame.left > 276.f) {
				this->spriteFrame.left = 0.f;
			}
			animationClock.restart();
			sprite.setTexture(textureIdle);
			sprite.setTextureRect(spriteFrame);
			spriteFrame.left += spriteFrame.width;;
		}
	}
	if (turnBackCounter >= 100) {
		// Flip the sprite horizontally
		sprite.setScale(-sprite.getScale().x, sprite.getScale().y);
		this->sprite.setOrigin(sprite.getGlobalBounds().width / 6.f , 0.f);
		// Reset the counter
		turnBackCounter = 0;
	}
	turnBackCounter++;
}

void EnemyTypeA::updateMovement()
{
	sprite.move(velocity);
}


EnemyTypeA::EnemyTypeA()
{
	// Initialize members inherited from Entity class
	// This is a stationary enemy
	velocity = sf::Vector2f(0.f, 0.f);
	acceleration = sf::Vector2f(1.2f, 1.f);
	velocityMax = sf::Vector2f(20.f, 20.f);
	velocityMin = sf::Vector2f(1.f, 1.f);
	drag = sf::Vector2f(0.9f, 1.f);
	moveDirection = sf::Vector2f(0.f, 0.f);;
	jumpForce = 0.f;
	
	canJump = false;
	isGrounded = false;

	initVariables();
	initTexture();
	initSprite();
}

void EnemyTypeA::update()
{
	updateAnimations();
	updateMovement();

	isHit = false;
}
