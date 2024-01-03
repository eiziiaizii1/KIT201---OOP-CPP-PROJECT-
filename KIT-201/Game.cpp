#include "Game.h"

void Game::initVariables() {}

void Game::initWindow() {
    videoMode = sf::VideoMode(1280, 960);
    window = new sf::RenderWindow(videoMode, "KIT-201", sf::Style::Close | sf::Style::Titlebar);
    window->setFramerateLimit(30);
}

Game::Game(): soundManager() {
    initVariables();
    initWindow();
}

Game::~Game() {
    delete window;
}

const bool Game::isRunning() const {
    return window->isOpen();
}

void Game::pollEvents() {
    stateManager.handleEvents(*window); // Delegate event handling to StateManager
}

void Game::update() {
    
   stateManager.update(); // Delegate update to StateManager
   this->soundManager.updateMusic(this->stateManager.getCurrentState()); // update music every time
}

void Game::render() {
    stateManager.render(*window); // Delegate rendering to StateManager
}

