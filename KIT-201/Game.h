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
 * @brief Represents the main game class managing the game loop and components.
 */
class Game {
private:
    sf::VideoMode videoMode; /**< Video mode of the game window. */
    sf::RenderWindow* window; /**< Pointer to the game window. */
    sf::Event sfmlEvent; /**< Event object handling SFML events. */

    StateManager stateManager; /**< Manages different game states. */
    SoundManager soundManager; /**< Manages game audio. */

    /**
     * @brief Initializes member variables.
     */
    void initVariables();

    /**
     * @brief Initializes the game window.
     */
    void initWindow();

public:
    /**
     * @brief Default constructor for Game class.
     */
    Game();

    /**
     * @brief Destructor for Game class.
     */
    ~Game();

    /**
     * @brief Checks if the game is running.
     * @return true if the game is running, false otherwise.
     */
    const bool isRunning() const;

    /**
     * @brief Handles SFML events.
     */
    void pollEvents();

    /**
     * @brief Updates the game logic.
     */
    void update();

    /**
     * @brief Renders game elements onto the window.
     */
    void render();
};

