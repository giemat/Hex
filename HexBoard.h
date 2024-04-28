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
    char **BOARD;
    std::vector<std::string> coms = {"BOARD_SIZE", "PAWNS_NUMBER", "IS_BOARD_CORRECT","IS_BOARD_POSSIBLE", "IS_GAME_OVER", "CAN_RED_WIN_IN_1_MOVE_WITH_NAIVE_OPPONENT", "CAN_BLUE_WIN_IN_1_MOVE_WITH_NAIVE_OPPONENT", "CAN_RED_WIN_IN_2_MOVES_WITH_NAIVE_OPPONENT", "CAN_BLUE_WIN_IN_2_MOVES_WITH_NAIVE_OPPONENT", "CAN_RED_WIN_IN_1_MOVE_WITH_PERFECT_OPPONENT", "CAN_BLUE_WIN_IN_1_MOVE_WITH_PERFECT_OPPONENT", "CAN_RED_WIN_IN_2_MOVES_WITH_PERFECT_OPPONENT", "CAN_BLUE_WIN_IN_2_MOVES_WITH_PERFECT_OPPONENT"};
public:

    HexBoard();

    int whichCom(std::string& input) const;

    int countRed(std::string& input);

    int countBlue(std::string& input);

    int setBoardSize(std::string input);

    void isBoardCorrect(std::string& input);

    char ** hexParse(const std::string &input);

    std::string isPossible(char **board);

    bool isBoardCorrect(char **board);

    bool dfs(int i, int j, char player, char **board, bool **visited);

    std::string isOver(char **board);

    void deleteBoard(char **board);

    void deleteVisit(bool **board) const;

    std::string Naive(char **board, char player, int moves);
};

#endif //HEX_HEXBOARD_H