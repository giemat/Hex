//
// Created by matgi on 4/24/2024.
//


#include "HexBoard.h"


HexBoard::HexBoard():BOARDSIZE(0),RED(0),BLUE(0) {

}

int HexBoard::whichCom(std::string str) const{
    for (int i = 0; i < coms.size(); ++i) {
        if (coms[i] == str){
            return i;
        }
    }
    return 10;
}

int HexBoard::countRed(std::string input) {
    RED = 0;
    for (char ch : input) {
        if (ch == 'r'){
            RED++;
        }
    }
    return RED;}

int HexBoard::countBlue(std::string input) {
    BLUE = 0;
    for (char ch : input) {
        if (ch == 'b'){
            BLUE++;
        }
    }
    return BLUE;}

int HexBoard::setBoardSize(std::string input) {
    BOARDSIZE = 0;
    for (char ch : input) {
        if (ch == '<'){
            BOARDSIZE++;
        }
    }
    BOARDSIZE = sqrt(BOARDSIZE);
    return int(BOARDSIZE);
}

void HexBoard::isBoardCorrect(std::string input) {
    if(countRed(input) == countBlue(input) || countRed(input)-1 == countBlue(input)){
        std::cout << "YES" << std::endl << std::endl;
    }else{
        std::cout << "NO" << std::endl << std::endl;
    }
}

std::vector<std::vector<char>> HexBoard::hexParse(const std::string& input) {
    setBoardSize(input);
    std::istringstream iss(input);
    std::string line;
    std::vector<std::string> lines;

    // Extracting lines from the input
    while (std::getline(iss, line)) {
        size_t firstDash = line.find_first_not_of(' ');
        if (firstDash != std::string::npos) {
            line.erase(0, firstDash);
        }
        // Remove unnecessary characters
        line.erase(std::remove(line.begin(), line.end(), '-'), line.end());
        line.erase(std::remove(line.begin(), line.end(), '<'), line.end());
        line.erase(std::remove(line.begin(), line.end(), '>'), line.end());
        if (!line.empty()) {
            lines.push_back(line);
        }
    }

    // Determine the size of the hex board based on the input
    int size = lines.size();
//    for (int i = 0; i < size; ++i) {
//        std::replace(lines[i].begin(), lines[i].end(), ' ', '*');
//        //lines[i].replace(lines[i].begin(),lines[i].end(), ' ', '*');
//    }
//    for (int i = 0; i < size; ++i) {
//        std::cout << lines[i] << std::endl;
//    }
    // Create a 2D array with the appropriate size
    std::vector<std::vector<char>> array(int(BOARDSIZE), std::vector<char>(int(BOARDSIZE), '*'));

    // Map the hex board to the 2D array
    for (int i = 0; i < BOARDSIZE; ++i) {
        for (int j = 0; j < BOARDSIZE; ++j) {
            lines[j].pop_back();
            array[i][j] = lines[j].back();
            //std::cout << lines[j].back();
            for (int k = 0; k < 2; ++k) {
                lines[j].pop_back();
            }
//            array[i][j] = lines[j].back();
        }
//        std::cout << std::endl;
//        for (int i = 0; i < size; ++i) {
//            std::cout << lines[i] << std::endl;
//        }
        lines.erase(lines.begin());
//        size--;
//        for (int i = 0; i < size; ++i) {
//            std::cout << lines[i] << std::endl;
//        }
    }

    return array;
}


void HexBoard::print_hex_board(const std::vector<std::vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}