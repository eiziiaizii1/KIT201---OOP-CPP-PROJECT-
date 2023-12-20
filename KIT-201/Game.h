#pragma once

#include <iostream>

#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\System.hpp"
#include "SFML\Audio.hpp"
#include "Player.h"

class Game
{
private:
	// main variables for game
	sf::VideoMode videoMode; //Holds information about window height, width, etc.
	sf::RenderWindow* window;
	sf::Event sfmlEvent;

	// Player and stuff
	Player player;

	//Initializers
	void initVariables();
	void initWindow();

public:
	//Constructors and Destructors
	Game();
	~Game();

	//Getters-Accessors

	//Setters-Modifiers

	//Functions
	const bool isRunning() const;
	void pollEvents();
	void update();
	void render();

};

