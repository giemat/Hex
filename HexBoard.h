//
// Created by matgi on 4/24/2024.
//

#ifndef HEX_HEXBOARD_H
#define HEX_HEXBOARD_H

#include <array>
#include <string>
#include <vector>

class HexBoard {
public:
    HexBoard();
    bool placePiece(char color, int x, int y);
    bool checkForWin(char color);
    void printBoard();
    void fromAsciiRepresentation(const std::string& asciiBoard);

private:
    static const int BOARD_SIZE = 11;
    std::array<std::array<char, BOARD_SIZE>, BOARD_SIZE> board;
    std::array<std::array<bool, BOARD_SIZE>, BOARD_SIZE> visited;
    bool isValid(int x, int y) const;
    bool dfs(int x, int y, char color);
    static std::vector<std::string> parseAsciiBoard(const std::string& asciiBoard);
};

#endif //HEX_HEXBOARD_H
