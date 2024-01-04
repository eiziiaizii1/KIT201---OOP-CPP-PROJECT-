#pragma once
#include <SFML/Graphics.hpp>

class State {
public:
    virtual ~State() = default;
    virtual void init() = 0;
    virtual void update() = 0;
    virtual void render(sf::RenderWindow& window) = 0;
    virtual void pollEvents(sf::RenderWindow& window) = 0;
    virtual void pause() = 0;
    virtual void resume() = 0;
};


