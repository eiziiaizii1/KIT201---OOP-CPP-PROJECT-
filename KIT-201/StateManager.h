#pragma once

#include "World.h"

/**
 * @brief Enumerates the different states of the game.
 */
enum class GameState {
    Play, /**< Game is in the playing state. */
    Pause, /**< Game is in the paused state. */
    Menu /**< Game is in the menu state. */
};

/**
 * @brief Manages the different states of the game.
 */
class StateManager {
private:
    GameState currentState; /**< Current state of the game. */
    World world; /**< Instance of the game world. */
    // Add other necessary variables or methods here

public:
    /**
     * @brief Default constructor for StateManager.
     */
    StateManager();

    /**
     * @brief Updates the current state of the game.
     */
    void update();

    /**
     * @brief Renders the current state of the game.
     * @param window The render window to draw the game state on.
     */
    void render(sf::RenderWindow& window);

    /**
     * @brief Polls events from the window to update game state.
     * @param window The render window to poll events from.
     */
    void pollEvents(sf::RenderWindow& window);

    /**
     * @brief Switches the game state.
     */
    void switchState();

    /**
     * @brief Gets the current state of the game.
     * @return The current game state.
     */
    GameState& getCurrentState();

    /**
     * @brief Gets the game world.
     * @return Reference to the game world.
     */
    World& getWorld();
};

