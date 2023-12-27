#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class TileMapParser {
private:
    std::ifstream fileStream;

public:
    TileMapParser(const std::string& filename);
    std::vector<std::vector<short>> parseTileMap(short);
};