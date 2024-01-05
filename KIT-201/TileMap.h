#pragma once
#include "SFML\Graphics.hpp"
#include <iostream>
#include <vector>

/**
 * @brief Enumeration representing different types of tiles.
 */
enum TileType {
    BACKGROUND = 0, /**< Background tile. */
    GROUND = 1, /**< Ground tile. */
    ENEMY_A = 2, /**< Enemy type A tile. */
    ENEMY_B = 3, /**< Enemy type B tile. */
    PLAYER = 4 /**< Player tile. */
};

/**
 * @brief Represents a tile map consisting of different types of tiles.
 */
class TileMap
{
private:
    sf::Texture blockTexture; /**< Texture for the tiles. */
    sf::Sprite blockSprite; /**< Sprite for rendering tiles. */

    std::vector<std::vector<short>> tileMap; /**< 2D vector storing tile values. */

    // Private methods for initialization
    void initTextures(); /**< Initializes textures. */
    void initSprites(); /**< Initializes sprites. */
    void initDefaultMap(); /**< Initializes default map (for testing). */

public:
    /**
     * @brief Default constructor for TileMap.
     */
    TileMap();

    /**
     * @brief Constructor that takes an existing tile map.
     * @param tileMap The tile map to initialize from.
     */
    TileMap(std::vector<std::vector<short>>& tileMap);

    /**
     * @brief Destructor for TileMap.
     */
    ~TileMap();

    // Getters

    /**
     * @brief Retrieves the global bounds of a tile.
     * @return The global bounds of a tile.
     */
    const sf::FloatRect& getTileGlobalBounds() const;

    /**
     * @brief Retrieves the map vector containing tile values.
     * @return The vector containing tile values.
     */
    const std::vector<std::vector<short>>& getMapVector();

    /**
     * @brief Updates the tile map.
     */
    void update();

    /**
     * @brief Renders the tile map onto a render target.
     * @param target The render target to draw the tile map on.
     */
    void render(sf::RenderTarget& target);
};

