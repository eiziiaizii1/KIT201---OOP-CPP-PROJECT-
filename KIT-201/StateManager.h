#pragma once

#include "World.h"

enum class GameState {
    Play,
    Pause,
    Menu
};

class StateManager {
private:
    GameState currentState;
    World world;
    // Add other necessary variables or methods here

public:
    StateManager();

    void update();
    void render(sf::RenderWindow& window);

    void pollEvents(sf::RenderWindow& window);
    void switchState();
    GameState& getCurrentState();
    World& getWorld();

    
};
