#pragma once

#include <iostream>

#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\System.hpp"
#include "SFML\Audio.hpp"
#include "Player.h"
#include "TileMap.h"
#include "CollisionManager.h"
#include "World.h"
#include "State.h"
#include "ActivePlayState.h"
#include "TestState.h"

class Game
{
private:
	// main variables for game
	sf::VideoMode videoMode; //Holds information about window height, width, etc.
	sf::RenderWindow* window;
	sf::Event sfmlEvent;

	World world;
	State& currentState;

	//Initializers
	void initVariables();
	void initWindow();

public:
	//Constructors and Destructors
	Game();
	~Game();

	//Getters-Accessors

	//Setters-Modifiers
	void setState(State& state); // Method to set the current state
	//Functions
	const bool isRunning() const;
	void pollEvents();
	void update();
	void render();

};

