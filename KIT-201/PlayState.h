#pragma once
#include "State.h"
#include "World.h"
#include <SFML/Graphics.hpp>

class PlayState : public State {
private:
    World& world;

public:
    PlayState() = delete;
    PlayState(World& worldRef);
    void init() override;
    void update() override;
    void render(sf::RenderWindow& window) override;
    void pollEvents(sf::RenderWindow& window) override;
    void pause() override;
    void resume() override;
};


