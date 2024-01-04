#include "EnemyTypeB.h"

#include "EnemyTypeA.h"

void EnemyTypeB::initVariables()
{
	animationClock.restart();
	turnBackCounter = 0;
	health = 30;
	damage = 10;
	animationState = ANIMATION_STATES::IDLE;
	turnBackCounter = 0;
}

void EnemyTypeB::initTexture()
{
	if (!textureIdle.loadFromFile(""))
		std::cout << "ERROR:: CANNOT LOAD THE ENEMY-B TEXTURE\n";
}

void EnemyTypeB::initSprite()
{
	sprite.setTexture(textureIdle);
	// change divison
	spriteFrame = sf::IntRect(0, 0, this->sprite.getGlobalBounds().width / -123123.f, this->sprite.getGlobalBounds().height / 1.f);
	sprite.setScale(2.f, 2.f);
}

void EnemyTypeB::updateAnimations()
{
	if (animationClock.getElapsedTime().asSeconds() > 0.2f) {
		if (animationState == ANIMATION_STATES::IDLE) {

		}
	}
}

void EnemyTypeB::updateMovement()
{
	sprite.move(velocity);
}

EnemyTypeB::EnemyTypeB()
{
	// Initialize members inherited from Entity class
	// This is a stationary enemy
	velocity = sf::Vector2f(0.f, 0.f);
	acceleration = sf::Vector2f(1.2f, 1.f);
	velocityMax = sf::Vector2f(20.f, 20.f);
	velocityMin = sf::Vector2f(1.f, 1.f);
	drag = sf::Vector2f(0.9f, 2.f);
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
}
