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
    stateManager.pollEvents(*window); // Delegate event handling to StateManager
}

void Game::update() {
    
   stateManager.update(); // Delegate update to StateManager
<<<<<<< HEAD
   auto currentState = this->stateManager.getCurrentState();
   this->soundManager.updateMusic(currentState); // update music every time
   this->soundManager.updateSoundEffect(currentState,this->stateManager.getWorld().getPlayer()); //updateSoundEffect
=======
   this->soundManager.updateMusic(this->stateManager.getCurrentState()); // update music every time
   this->soundManager.updateSoundEffect(this->stateManager); //updateSoundEffect
>>>>>>> origin/AÖ-v1.7-copy-to-be-merged
}

void Game::render() {
    stateManager.render(*window); // Delegate rendering to StateManager
}

