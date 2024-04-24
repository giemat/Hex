#include <iostream>
#include <algorithm>
#include "HexBoard.h"


bool isCom(const std::vector<std::string>& vec, const std::string& str) {
    return std::find(vec.begin(), vec.end(), str) != vec.end();
}

int main() {
    HexBoard hexBoard;
    std::string size = "BOARD_SIZE";
    std::string number = "PAWNS_NUMBER";
    std::string boardCorrect = "IS_BOARD_CORRECT";
    std::string over = "IS_GAME_OVER";
    std::string possible = "IS_BOARD_POSSIBLE";
    std::string naive = "CAN_RED_WIN_IN_1_MOVE_WITH_NAIVE_OPPONENT\n"
                       "CAN_BLUE_WIN_IN_1_MOVE_WITH_NAIVE_OPPONENT\n"
                       "CAN_RED_WIN_IN_2_MOVES_WITH_NAIVE_OPPONENT\n"
                       "CAN_BLUE_WIN_IN_2_MOVES_WITH_NAIVE_OPPONENT";
    std::string perfect = "CAN_RED_WIN_IN_1_MOVE_WITH_PERFECT_OPPONENT\n"
                          "CAN_BLUE_WIN_IN_1_MOVE_WITH_PERFECT_OPPONENT\n"
                          "CAN_RED_WIN_IN_2_MOVES_WITH_PERFECT_OPPONENT\n"
                          "CAN_BLUE_WIN_IN_2_MOVES_WITH_PERFECT_OPPONENT";
    std::vector<std::string> coms;
    coms.push_back(size);
    coms.push_back(number);
    coms.push_back(boardCorrect);
    coms.push_back(over);
    coms.push_back(perfect);
    coms.push_back(possible);
    coms.push_back(naive);

    std::string input;
    std::string line;
    std::string query;
    std::cout << "Enter the ASCII representation of the Hex board (Enter an empty line to finish):" << std::endl;

    while (std::getline(std::cin, line) && !line.empty()) {
        input += line + '\n';
    }

    std::cout << input << std::endl;
    //hexBoard.fromAsciiRepresentation(input);

    //hexBoard.printBoard();
        return 0;
    }
