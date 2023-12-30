#include "ActivePlayState.h"

ActivePlayState::ActivePlayState(Game& gameRef, World& worldRef) : gameRef(gameRef), worldRef(worldRef) {
    // No need to create instances here; use the provided references
}

void ActivePlayState::pollEvents(sf::RenderWindow& window, sf::Event& sfmlEvent) {
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

void ActivePlayState::update() {
    gameRef.pollEvents();
    worldRef.update();
}

void ActivePlayState::render(sf::RenderWindow& window) {
    window.clear(sf::Color(0, 0, 50));
    worldRef.render(window); // Render the world within this state
    window.display(); // Display the rendered frame
}

