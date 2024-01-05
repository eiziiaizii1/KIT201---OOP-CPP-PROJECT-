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
#include "StateManager.h"
#include "SoundManager.h"

/**
 * The Game class manages the game loop and holds game-related components.
 */
class Game {
private:
    sf::VideoMode videoMode;
    sf::RenderWindow* window;
    sf::Event sfmlEvent;

    StateManager stateManager; // Manages game states
    SoundManager soundManager; // Manages game sounds

    /**
     * Initializes internal variables.
     */
    void initVariables();

    /**
     * Initializes the game window.
     */
    void initWindow();

public:
    /**
     * Constructor for the Game class.
     */
    Game();

    /**
     * Destructor for the Game class.
     */
    ~Game();

    /**
     * Checks if the game is running.
     * @return True if the game is running, false otherwise.
     */
    const bool isRunning() const;

    /**
     * Polls SFML events.
     */
    void pollEvents();

    /**
     * Updates the game logic.
     */
    void update();

    /**
     * Renders the game.
     */
    void render();
};


