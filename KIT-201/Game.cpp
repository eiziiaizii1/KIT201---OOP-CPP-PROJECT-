#include "Game.h"

void Game::initVariables()
{
	
}

void Game::initWindow()
{
	//Fixed Values For now
	this->videoMode = sf::VideoMode(1280,960);
	this->window = new sf::RenderWindow(this->videoMode,"KIT-201",sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(30);
}

//Constructors and Destructors:
Game::Game()
	: currentState(*(new ActivePlayState(*this, world))){ //This will be MainMenuState normally
	initVariables();
	initWindow();
}

Game::~Game() {
	// Clean up the state reference
	delete& currentState;
	delete this->window;
}

void Game::setState(State& state) {
	// Clean up the existing state
	delete& currentState;
	// Set the new state
	currentState = state;
}


//Functions:
const bool Game::isRunning() const
{
	return this->window->isOpen();
}

void Game::pollEvents()
{
	this->currentState.pollEvents(*this->window, this->sfmlEvent);
}

void Game::update()
{
	this->currentState.update();
}

void Game::render() {
	//*****Render stuff:***** 
	currentState.render(*this->window); // Pass window 

	//this->window->display();
}

