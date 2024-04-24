//
// Created by matgi on 4/24/2024.
//


#include "HexBoard.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

HexBoard::HexBoard() {
    for (auto &row : board) {
        row.fill('.');
    }
}

bool HexBoard::placePiece(char color, int x, int y) {
    if (isValid(x, y) && board[x][y] == '.') {
        board[x][y] = color;
        return true;
    }
    return false;
}

bool HexBoard::checkForWin(char color) {
    for (auto &row : visited) {
        row.fill(false);
    }
    if (color == 'r') {
        for (int i = 0; i < BOARD_SIZE; ++i) {
            if (board[i][0] == color && dfs(i, 0, color)) {
                return true;
            }
        }
    } else if (color == 'b') {
        for (int i = 0; i < BOARD_SIZE; ++i) {
            if (board[0][i] == color && dfs(0, i, color)) {
                return true;
            }
        }
    }
    return false;
}

void HexBoard::printBoard() {
    for (const auto &row : board) {
        for (char cell : row) {
            std::cout << cell << ' ';
        }
        std::cout << '\n';
    }
}

bool HexBoard::isValid(int x, int y) const {
    return (x >= 0) && (x < BOARD_SIZE) && (y >= 0) && (y < BOARD_SIZE);
}

bool HexBoard::dfs(int x, int y, char color) {
    if ((color == 'r' && y == BOARD_SIZE - 1) || (color == 'b' && x == BOARD_SIZE - 1)) {
        return true;
    }
    visited[x][y] = true;
    std::array<std::pair<int, int>, 6> directions = {{{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, 1}, {1, -1}}};
    for (const auto& dir : directions) {
        int newX = x + dir.first;
        int newY = y + dir.second;
        if (isValid(newX, newY) && !visited[newX][newY] && board[newX][newY] == color) {
            if (dfs(newX, newY, color)) {
                return true;
            }
        }
    }
    return false;
}

void HexBoard::fromAsciiRepresentation(const std::string& asciiBoard) {
    auto parsedLines = parseAsciiBoard(asciiBoard);
    for (int i = 0; i < parsedLines.size(); ++i) {
        for (int j = 0; j < parsedLines[i].size(); ++j) {
            if (parsedLines[i][j] == 'r' || parsedLines[i][j] == 'b') {
                placePiece(parsedLines[i][j], i, j);
            }
        }
    }
}

std::vector<std::string> HexBoard::parseAsciiBoard(const std::string& asciiBoard) {
    std::stringstream ss(asciiBoard);
    std::string line;
    std::vector<std::string> parsedLines;

    while (getline(ss, line)) {
        line.erase(std::remove(line.begin(), line.end(), '-'), line.end());
        line.erase(std::remove(line.begin(), line.end(), '<'), line.end());
        line.erase(std::remove(line.begin(), line.end(), '>'), line.end());
        line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());
        if (!line.empty()) {
            parsedLines.push_back(line);
        }
    }
    return parsedLines;
}