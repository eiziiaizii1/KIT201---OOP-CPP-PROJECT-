#pragma once
#include <SFML/Graphics.hpp> // Include SFML as needed

class State {
public:
    virtual void pollEvents(sf::RenderWindow& window, sf::Event& sfmlEvent) = 0;
    virtual void update() = 0;
    virtual void render(sf::RenderWindow& window) = 0;
    virtual ~State() {}
};


