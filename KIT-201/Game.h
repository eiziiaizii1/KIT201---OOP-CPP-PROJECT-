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

class Game {
private:
    sf::VideoMode videoMode;
    sf::RenderWindow* window;
    sf::Event sfmlEvent;

    StateManager stateManager; // Include StateManager in Game
    SoundManager soundManager;


    void initVariables();
    void initWindow();

public:
    Game();
    ~Game();

    const bool isRunning() const;
    void pollEvents();
    void update();
    void render();
};

