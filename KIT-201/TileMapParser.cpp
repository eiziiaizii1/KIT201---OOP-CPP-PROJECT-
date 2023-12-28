#include "TileMapParser.h"

TileMapParser::TileMapParser(const std::string& filename) : fileStream(filename) {
    if (!fileStream.is_open()) {
        throw std::runtime_error("Unable to open file");
    }
}

std::vector<std::vector<short>> TileMapParser::parseTileMap(short targetIndex) {
    std::vector<std::vector<short>> result;
    std::string line;

    while (std::getline(fileStream, line)) {
        if (line.empty()) {
            continue; // Skip empty lines
        }

        int index;
        if (!(std::istringstream(line) >> index)) {
            throw std::runtime_error("Invalid index format");
        }

        if (index == targetIndex) {
            std::getline(fileStream, line); // Read the row and column format line
            std::istringstream formatStream(line);
            int rows, cols;
            if (!(formatStream >> rows >> cols)) {
                throw std::runtime_error("Invalid row/column format");
            }

            // Read the string with space-separated short values
            for (int i = 0; i < rows; ++i) {
                std::vector<short> rowData;
                std::getline(fileStream, line);
                std::istringstream dataStream(line);
                short value;
                while (dataStream >> value) {
                    rowData.push_back(value);
                }

                if (static_cast<int>(rowData.size()) != cols) {
                    throw std::runtime_error("Invalid data size for TileMap row");
                }

                result.push_back(rowData);
            }
            return result;
        }
        else {
            // Skip to the next TileMap block
            while (std::getline(fileStream, line) && !line.empty()) {
                // Skip lines until an empty line
            }
        }
    }

    throw std::runtime_error("Desired index not found");
}


void printTileMap(const std::vector<std::vector<short>>& tileMap) {
    for (const auto& row : tileMap) {
        for (short value : row) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
}

/*
int main() {
    TileMapParser parser("C:/EMIN SALIH/Programming/C++ Projects/TileMapParser/TileMapParser/test.txt");

    try {
        std::vector<std::vector<short>> tileMap = parser.parseTileMap(1);
        printTileMap(tileMap);
        std::cout << "Bruh";
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 12;
}
*/