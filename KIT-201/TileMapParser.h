#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

/**
 * @brief A class responsible for parsing a tile map from a file.
 */
class TileMapParser {
private:
    std::ifstream fileStream; /**< Input file stream for reading the tile map file. */

public:
    /**
     * @brief Constructs a TileMapParser object.
     * @param filename The name of the file containing the tile map data.
     */
    TileMapParser(const std::string& filename);

    /**
     * @brief Parses the tile map from the file.
     * @param tileSize The size of each tile.
     * @return A 2D vector representing the parsed tile map.
     */
    std::vector<std::vector<short>> parseTileMap(short tileSize);
};
