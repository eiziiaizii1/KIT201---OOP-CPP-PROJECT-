#pragma once
#include <SFML/Graphics.hpp>

class Camera {

private:
	sf::View camera;

public:
	Camera();
	~Camera();
	sf::View& getView();
};