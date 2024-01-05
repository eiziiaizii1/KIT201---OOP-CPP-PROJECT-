#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

/**
 * @brief Handles parsing of tile map data from a file.
 */
class TileMapParser {
private:
    std::ifstream fileStream; /**< Input file stream for reading the tile map file. */

public:
    /**
     * @brief Constructs a TileMapParser object with a given filename.
     *
     * @param filename The name of the file containing tile map data.
     */
    TileMapParser(const std::string& filename);

    /**
     * @brief Parses the tile map data from the file.
     *
     * @param defaultTile The default value for tiles in case of parsing errors.
     * @return A 2D vector representing the parsed tile map.
     */
    std::vector<std::vector<short>> parseTileMap(short defaultTile);
};
