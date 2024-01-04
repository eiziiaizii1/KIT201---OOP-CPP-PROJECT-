#include "PlayState.h"

//PlayState::PlayState(){}

PlayState::PlayState(World& worldRef) : world(worldRef) {}

void PlayState::init() {
    // Initialize the world object using its default constructor
}


void PlayState::update() {
    // Update the world object
    world.update();
}

void PlayState::render(sf::RenderWindow& window) {
    // Render the world
    window.setView(world.getCamera().getView());
    window.clear(sf::Color(0, 0, 50));
    world.render(window);
    window.display();
}

void PlayState::pollEvents(sf::RenderWindow& window) {
    // Handle events specific to PlayState if needed
    // You can add specific event handling logic here
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
            /*else if (sfmlEvent.key.code == sf::Keyboard::P) {
                switchState();
            }
            */
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

void PlayState::pause() {
    // Pause logic for PlayState if needed
}

void PlayState::resume() {
    // Resume logic for PlayState if needed
}
