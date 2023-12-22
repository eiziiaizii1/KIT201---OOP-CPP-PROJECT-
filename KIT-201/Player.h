#pragma once
#include "SFML\Graphics.hpp"
#include <iostream>

class Player
{
private:
	sf::Texture texture;
	sf::Sprite sprite;

	//Physics variables
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Vector2f velocityMax;
	sf::Vector2f velocityMin;
	sf::Vector2f acceleration;
	sf::Vector2f drag;

	int animationCounter;
	sf::IntRect spriteFrame;
	short int animationFrameCount;
	bool goingLeft;

	void initVariables();
	void initTexture();
	void initSprite();

	void handleInputs();
	void move();
public:
	//Constructors - Dectructor
	Player();
	~Player();

	void updateAnimations();
	void update();
	void render(sf::RenderTarget& target);
};

