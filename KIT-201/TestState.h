#pragma once
#include "State.h"
#include "Game.h" // Include the Game class header
#include "World.h"


class Game; // Forward declaration of Game class

class TestState : public State {
private:
    Game& gameRef; // Reference to the Game class instance
    World& worldRef;
public:
    TestState(Game& gameRef , World& worldRef);
    void pollEvents(sf::RenderWindow& window, sf::Event& sfmlEvent) override;
    void update() override;
    void render(sf::RenderWindow& window) override;
};

