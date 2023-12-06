#include "Game.h"

void Game::initVariables()
{
}

void Game::initWindow()
{
	//Fixed Values For now
	this->videoMode = sf::VideoMode(1280,720);
	this->window = new sf::RenderWindow(this->videoMode,"KIT-201",sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
}

//Constructors and Destructors:
Game::Game()
{
	initVariables();
	initWindow();
}

Game::~Game()
{
	delete this->window;
}


//Functions:

const bool Game::isRunning() const
{
	return this->window->isOpen();
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->sfmlEvent)) {
		switch (this->sfmlEvent.type) {
			case sf::Event::Closed:
				this->window->close();
				break;
			case sf::Event::KeyPressed:
				if (this-> sfmlEvent.key.code == sf::Keyboard::Escape) {
					this->window->close();
				}
				break;
			default:
				break;
		}
	}
}

void Game::update()
{
	this->pollEvents();
}

void Game::render()
{
	this->window->clear();


	//Render stuff:

	this->window->display();
}
