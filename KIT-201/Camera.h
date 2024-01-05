#pragma once
#include <SFML/Graphics.hpp>

/**
 * The Camera class represents a wrapper for SFML view to focus the view on the player.
 */
class Camera {
private:
    sf::View camera;

public:
    /**
     * Constructor for the Camera class.
     */
    Camera();

    /**
     * Destructor for the Camera class.
     */
    ~Camera();

    /**
     * Retrieves the SFML view.
     * @return Reference to the SFML view.
     */
    sf::View& getView();

    /**
     * Sets the center of the view.
     * @param center The position to set as the center of the view.
     */
    void setCenter(const sf::Vector2f& center);
};
