#include "Camera.h";

Camera::Camera() : camera(sf::FloatRect(0, 0, 1280, 960)) {

}

Camera::~Camera(){

}

sf::View& Camera::getView() {
	return this->camera;
}

void Camera::setCenter(const sf::Vector2f& center) {
	this->camera.setCenter(center);
}