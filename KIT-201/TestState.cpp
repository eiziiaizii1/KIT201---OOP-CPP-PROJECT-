#include "TestState.h"


TestState::TestState(Game& gameRef, World& worldRef) : gameRef(gameRef) , worldRef(worldRef)
{
}

void TestState::pollEvents(sf::RenderWindow& window, sf::Event& sfmlEvent) {
    while (window.pollEvent(sfmlEvent)) {
        switch (sfmlEvent.type) {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::KeyPressed:
            if (sfmlEvent.key.code == sf::Keyboard::Escape) {
                window.close();
            }

            break;
        default:
            break;
        }
    }
}

void TestState::update() {
    // nothing to write here for now
}

void TestState::render(sf::RenderWindow& window) {
    window.clear(sf::Color::Black); // Fill the screen with black color
    window.display(); // Display the black screen
}
