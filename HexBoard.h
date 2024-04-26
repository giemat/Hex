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
    char **BOARD;
    std::string naive ="CAN_RED_WIN_IN_1_MOVE_WITH_NAIVE_OPPONENT\n"
                       "CAN_BLUE_WIN_IN_1_MOVE_WITH_NAIVE_OPPONENT\n"
                       "CAN_RED_WIN_IN_2_MOVES_WITH_NAIVE_OPPONENT\n"
                       "CAN_BLUE_WIN_IN_2_MOVES_WITH_NAIVE_OPPONENT";
    std::string perfect ="CAN_RED_WIN_IN_1_MOVE_WITH_PERFECT_OPPONENT\n"
                         "CAN_BLUE_WIN_IN_1_MOVE_WITH_PERFECT_OPPONENT\n"
                         "CAN_RED_WIN_IN_2_MOVES_WITH_PERFECT_OPPONENT\n"
                         "CAN_BLUE_WIN_IN_2_MOVES_WITH_PERFECT_OPPONENT";
    std::vector<std::string> coms = {"BOARD_SIZE", "PAWNS_NUMBER", "IS_BOARD_CORRECT","IS_BOARD_POSSIBLE", "IS_GAME_OVER", perfect, naive};
public:
    HexBoard();
    int whichCom(std::string str) const;
    int countRed(std::string input);
    int countBlue(std::string input);
    int setBoardSize(std::string input);
    void isBoardCorrect(std::string input);
    void print_hex_board(const std::vector<std::vector<char>> &board);

    std::vector<std::vector<char>> hexParse(const std::string &input);
};

#endif //HEX_HEXBOARD_H
