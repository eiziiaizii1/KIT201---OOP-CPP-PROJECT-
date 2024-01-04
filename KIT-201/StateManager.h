#pragma once

#include "World.h"
#include "State.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

enum class GameState {
    Play = 0,
    Pause
};

class StateManager {
private:
    GameState currentState;
    World world;
    std::vector<std::unique_ptr<State>> states;

public:
    StateManager();

    void update();
    void render(sf::RenderWindow& window);
    void pollEvents(sf::RenderWindow& window);
    void initStates();
    void changeState(GameState newState);
    World& getWorld();
    GameState getCurrentState();
};



/*
enum class GameState {
    Play,
    Pause
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

    void handleEvents(sf::RenderWindow& window);
    void switchState();
    GameState& getCurrentState();
    World& getWorld();
    
};
*/