#pragma once

#include <SFML/Graphics.hpp>

/**
 * @brief Represents a camera that focuses on the player.
 */
class Camera {
private:
    sf::View camera; /**< View representing the camera. */

public:
    /**
     * @brief Constructs a Camera object.
     */
    Camera();

    /**
     * @brief Destroys the Camera object.
     */
    ~Camera();

    /**
     * @brief Gets the view associated with the camera.
     *
     * @return Reference to the view.
     */
    sf::View& getView();

    /**
     * @brief Sets the center of the camera view.
     *
     * @param center The new center position for the camera.
     */
    void setCenter(const sf::Vector2f& center);
};
