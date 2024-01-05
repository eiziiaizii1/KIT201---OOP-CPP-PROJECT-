#pragma once

#include "World.h"

/**
 * @brief Enum representing different game states.
 */
enum class GameState {
    Play, /**< Game playing state. */
    Pause, /**< Game paused state. */
    Menu /**< Game menu state. */
};

/**
 * @brief Manages the different states of the game.
 */
class StateManager {
private:
    GameState currentState; /**< Current game state. */
    World world; /**< The game world. */
    // Add other necessary variables or methods here

public:
    /**
     * @brief Constructs a StateManager object.
     */
    StateManager();

    /**
     * @brief Updates the game state.
     */
    void update();

    /**
     * @brief Renders the game state.
     *
     * @param window The rendering window.
     */
    void render(sf::RenderWindow& window);

    /**
     * @brief Polls events for the game state.
     *
     * @param window The rendering window.
     */
    void pollEvents(sf::RenderWindow& window);

    /**
     * @brief Switches the game state.
     */
    void switchState();

    /**
     * @brief Gets the current game state.
     *
     * @return The current game state.
     */
    GameState& getCurrentState();

    /**
     * @brief Gets the game world.
     *
     * @return The game world.
     */
    World& getWorld();
};

