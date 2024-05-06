//
// Created by matgi on 4/24/2024.
//

#ifndef HEX_HEXBOARD_H
#define HEX_HEXBOARD_H

#include <array>
#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <sstream>
#include <algorithm>


class HexBoard {
protected:
    double BOARDSIZE;
    int RED;
    int BLUE;
    int SPACES;
    char board[11][11]{};
    std::string last;
    std::vector<std::string> coms = {"BOARD_SIZE", "PAWNS_NUMBER", "IS_BOARD_CORRECT","IS_BOARD_POSSIBLE", "IS_GAME_OVER", "CAN_RED_WIN_IN_1_MOVE_WITH_NAIVE_OPPONENT", "CAN_BLUE_WIN_IN_1_MOVE_WITH_NAIVE_OPPONENT", "CAN_RED_WIN_IN_2_MOVES_WITH_NAIVE_OPPONENT", "CAN_BLUE_WIN_IN_2_MOVES_WITH_NAIVE_OPPONENT", "CAN_RED_WIN_IN_1_MOVE_WITH_PERFECT_OPPONENT", "CAN_BLUE_WIN_IN_1_MOVE_WITH_PERFECT_OPPONENT", "CAN_RED_WIN_IN_2_MOVES_WITH_PERFECT_OPPONENT", "CAN_BLUE_WIN_IN_2_MOVES_WITH_PERFECT_OPPONENT"};
public:

    HexBoard();

    void setLast(std::string input);

    int countRed(std::string& input);

    int countBlue(std::string& input);

    int setBoardSize(const std::string& input);

    void isBoardCorrect(std::string& input);

    void hexParse(const std::string &input);

    std::string isPossible();

    bool isBoardCorrect() const;

    bool dfs(int i, int j, char player, bool **visited);

    std::string isOver();

    void deleteBoard();

    void deleteVisit(bool **board) const;

    std::string Naive(char player, int moves);

    bool isConnected(char player);

    bool iterate( char player);

    bool testTwo( char player);

    std::string Perfect(char player, char enemy, int moves);

    bool perfectPair(char player, char enemy);

    bool perfectTriple(char player, char enemy, int moves);
};

#endif //HEX_HEXBOARD_H