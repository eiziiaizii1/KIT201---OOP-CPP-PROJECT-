#include "Enemy.h"

void Enemy::initVariables()
{
	animationClock.restart();
	turnBackCounter = 0;
	health = 30;
	damage = 10;
	animationState = ANIMATION_STATES::IDLE;
}

void Enemy::initTexture()
{
	if (!textureIdle.loadFromFile("Textures/Enemy1Idle.png"))
		std::cout << "ERROR:: CANNOT LOAD THE ENEMT1 TEXTURE\n";
}

void Enemy::initSprite()
{
	sprite.setTexture(textureIdle);
	spriteFrame = sf::IntRect(0, 0, this->sprite.getGlobalBounds().width / 7.f, this->sprite.getGlobalBounds().height / 1.f);
	sprite.setScale(2.f, 2.f);

	sprite.setPosition(640.f,480.f);
}

void Enemy::updateAnimations()
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
}

void Enemy::updateMovement()
{
	sprite.move(velocity);
}


Enemy::Enemy()
{
	// Initialize members inherited from Entity class
	// This is a stationary enemy
	velocity = sf::Vector2f(0.f, 0.f);
	acceleration = sf::Vector2f(1.2f, 1.f);
	velocityMax = sf::Vector2f(0.f, 20.f);
	velocityMin = sf::Vector2f(1.f, 1.f);
	drag = sf::Vector2f(0.9f, 3.f);
	moveDirection = sf::Vector2f(0.f, 1.f);;
	jumpForce = 30.f;
	canJump = false;
	isGrounded = false;

	initVariables();
	initTexture();
	initSprite();
}


void Enemy::update()
{
	updateAnimations();
	updateMovement();
}

void Enemy::render(sf::RenderTarget& target)
{
	target.draw(sprite);
}
