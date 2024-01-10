#include "StateManager.h"

StateManager::StateManager() : currentState(GameState::Menu), world() {
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

    if (currentState == GameState::Menu) {
        sf::RenderTarget& target = window;

        // Get the current view center and window size
        sf::Vector2f viewCenter = target.getView().getCenter();
        sf::Vector2u windowSize = target.getSize();

        // Opaque rectangle that covers screen
        sf::RectangleShape menuOverlay(sf::Vector2f(windowSize.x, windowSize.y));
        menuOverlay.setFillColor(sf::Color(25, 0, 5, 255)); // Adjust the opacity here (0-255)
        menuOverlay.setPosition(viewCenter - sf::Vector2f(windowSize.x / 2.0f, windowSize.y / 2.0f));
        target.draw(menuOverlay);

        // Loads the Font
        sf::Font font;
        font.loadFromFile("Fonts/VT323.ttf");

        // Sets the appearance of the text
        sf::Text TitleText;
        TitleText.setFont(font);
        TitleText.setString("KIT-201");
        TitleText.setCharacterSize(128);
        TitleText.setFillColor(sf::Color::White);
        TitleText.setStyle(sf::Text::Bold);

        // Centers the overlay and text using the local bounds currently displayed on the screen
        sf::FloatRect titleTextRect = TitleText.getLocalBounds();
        TitleText.setOrigin(titleTextRect.left + titleTextRect.width / 2.0f, titleTextRect.top + titleTextRect.height / 2.0f);
        TitleText.setPosition(viewCenter.x + titleTextRect.left, viewCenter.y - titleTextRect.height / 2.0f + titleTextRect.top);

        target.draw(TitleText);

        // Add the "Press P to Play" text
        sf::Text pressToPlayText;
        pressToPlayText.setFont(font);
        pressToPlayText.setString("Press P to Play");
        pressToPlayText.setCharacterSize(24);
        pressToPlayText.setFillColor(sf::Color::White);
        pressToPlayText.setStyle(sf::Text::Bold);

        // Center the "Press P to Play" text underneath the 'PAUSED' text
        sf::FloatRect pressToPlayTextRect = pressToPlayText.getLocalBounds();
        pressToPlayText.setOrigin(pressToPlayTextRect.left + pressToPlayTextRect.width / 2.0f,
            pressToPlayTextRect.top + pressToPlayTextRect.height / 2.0f);
        pressToPlayText.setPosition(viewCenter.x  + pressToPlayTextRect.left,
            viewCenter.y + titleTextRect.height + pressToPlayTextRect.top + 10.0f);

        target.draw(pressToPlayText);
    }
    
        

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

            // Loads the Pause Font
            sf::Font font; 
            font.loadFromFile("Fonts/VT323.ttf"); 

            // Sets the appearance of the text
            sf::Text pausedText;
            pausedText.setFont(font);
            pausedText.setString("PAUSED");
            pausedText.setCharacterSize(128);
            pausedText.setFillColor(sf::Color::White);
            pausedText.setStyle(sf::Text::Bold);

            // Centers the overlay and text using the local bounds currently displayed on the screen
            sf::FloatRect textRect = pausedText.getLocalBounds();
            pausedText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
            pausedText.setPosition(viewCenter.x  + textRect.left, viewCenter.y - textRect.height / 2.0f + textRect.top);

            target.draw(pausedText);
        }

        window.display();
}

void StateManager::pollEvents(sf::RenderWindow& window) {
    static bool pKeyPressed = false; // Static variable to track P key state, Implements check to prevent p being held

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
            else if (sfmlEvent.key.code == sf::Keyboard::P && !pKeyPressed) {
                switchState();
                pKeyPressed = true;
            }
            break;
        case sf::Event::KeyReleased:
            if (sfmlEvent.key.code == sf::Keyboard::P) {
                pKeyPressed = false;
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

    if (currentState == GameState::Menu) {
        currentState = GameState::Play;
    }
}

GameState& StateManager::getCurrentState() {
    return this->currentState;
}
World& StateManager::getWorld() {
    return this->world;
}
