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
        window.setView(world.getCamera().getView());
        window.clear(sf::Color(0, 0, 50));
        world.render(window);
        

        if (currentState == GameState::Pause) {
            sf::RenderTarget& target = window;

            // Get the current view center and window size
            sf::Vector2f viewCenter = target.getView().getCenter();
            sf::Vector2u windowSize = target.getSize();

            // Semi-transparent gray rectangle to cover the screen
            sf::RectangleShape pauseOverlay(sf::Vector2f(windowSize.x, windowSize.y));
            pauseOverlay.setFillColor(sf::Color(0, 0, 0, 125)); // Adjust the opacity here (0-255)
            pauseOverlay.setPosition(viewCenter - sf::Vector2f(windowSize.x / 2.0f, windowSize.y / 2.0f));
            target.draw(pauseOverlay);

            sf::Font font; // Load your font
            font.loadFromFile("Fonts/VT323.ttf"); // Load your font file

            sf::Text pausedText;
            pausedText.setFont(font);
            pausedText.setString("PAUSED");
            pausedText.setCharacterSize(128);
            pausedText.setFillColor(sf::Color::White);
            pausedText.setStyle(sf::Text::Bold);

            // Center the 'PAUSED' text accurately on the current screen's center
            sf::FloatRect textRect = pausedText.getLocalBounds();
            pausedText.setOrigin(textRect.left + textRect.width / 2.0f,
                textRect.top + textRect.height / 2.0f);

            pausedText.setPosition(viewCenter.x  + textRect.left,
                viewCenter.y - textRect.height / 2.0f + textRect.top);

            target.draw(pausedText);
        }

        window.display();
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

GameState& StateManager::getCurrentState() {
    return this->currentState;
}
World& StateManager::getWorld() {
    return this->world;
}
