#pragma once
#include "SFML\Graphics.hpp"
#include <iostream>

enum ANIMATION_STATES {IDLE = 0, MOVING_RIGHT, MOVING_LEFT};

class Player
{
private:
	sf::Texture textureRun;
	sf::Texture textureIdle;
	sf::Sprite sprite;

	//Physics variables
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Vector2f velocityMax;
	sf::Vector2f velocityMin;
	sf::Vector2f acceleration;
	sf::Vector2f drag; //drag.x is friction, drag.y is gravity

	sf::Clock animationClock;
	sf::IntRect spriteFrame;
	short int animationFrameCount;
	ANIMATION_STATES animationState;

	void initVariables();
	void initTexture();
	void initSprite();

	void updateAnimations();
	void updateMovement();
	void move(const float x_dir, const float y_dir);
	void updatePhysics();
public:
	//Constructors - Dectructor
	Player();
	~Player();

	
	void update();
	void render(sf::RenderTarget& target);
};

