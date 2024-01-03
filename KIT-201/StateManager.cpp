#include "StateManager.h"

StateManager::StateManager() : currentState(GameState::Play), world() {
    // Initialize other necessary variables or methods here
}

void StateManager::update() {
    if (currentState == GameState::Play) {
        // Update the world when in play state
        world.update();
    }
}

void StateManager::render(sf::RenderWindow& window) {
    if (currentState == GameState::Play) {
        // Render the world when in play state
        window.setView(world.getCamera().getView());
        window.clear(sf::Color(0, 0, 50));
        world.render(window);
        window.display();
    }
    else if (currentState == GameState::Pause) {
        // Render the pause screen when in pause state
        window.clear(sf::Color::Black);
        // Render white rectangle and other elements for pause screen
        // ...
        window.display();
    }
}

void StateManager::handleEvents(sf::RenderWindow& window) {
    sf::Event sfmlEvent;
    while (window.pollEvent(sfmlEvent)) {
        switch (sfmlEvent.type) {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::KeyPressed:
            if (sfmlEvent.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            else if (sfmlEvent.key.code == sf::Keyboard::P) {
                switchState();
            }
            break;
        case sf::Event::MouseButtonPressed:
            // Logic for handling mouse clicks in pause screen
            // ...
            break;
        default:
            break;
        }
    }
}

void StateManager::switchState() {
    if (currentState == GameState::Play) {
        currentState = GameState::Pause;
    }
    else {
        currentState = GameState::Play;
    }
}
