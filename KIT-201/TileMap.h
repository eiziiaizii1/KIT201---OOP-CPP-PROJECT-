#pragma once

#include "SFML\Graphics.hpp"
#include <iostream>
#include <vector>

/**
 * @brief Enum defining different tile types.
 */
enum TileType {
    BACKGROUND = 0, /**< Background tile type. */
    GROUND = 1, /**< Ground tile type. */
    ENEMY_A = 2, /**< Enemy type A tile type. */
    ENEMY_B = 3, /**< Enemy type B tile type. */
    PLAYER = 4 /**< Player tile type. */
};

/**
 * @brief Represents a tile map.
 */
class TileMap {
private:
    sf::Texture blockTexture; /**< Texture for tiles. */
    sf::Sprite blockSprite; /**< Sprite for tiles. */
    std::vector<std::vector<short>> tileMap; /**< 2D vector representing the tile map. */

    // Init functions are for constructor
    void initTextures();
    void initSprites();
    void initDefaultMap(); // Default map is for testing

public:
    /**
     * @brief Constructs a TileMap object.
     */
    TileMap();

    /**
     * @brief Constructs a TileMap object with a provided tile map.
     *
     * @param tileMap The tile map to initialize.
     */
    TileMap(std::vector<std::vector<short>>& tileMap);

    /**
     * @brief Destroys the TileMap object.
     */
    ~TileMap();

    // Getters
    const sf::FloatRect& getTileGlobalBounds() const;
    const std::vector<std::vector<short>>& getMapVector();

    /**
     * @brief Updates the tile map.
     */
    void update();

    /**
     * @brief Renders the tile map on the provided render target.
     *
     * @param target The render target to render the tile map onto.
     */
    void render(sf::RenderTarget& target);
};


