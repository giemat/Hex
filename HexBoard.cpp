//
// Created by matgi on 4/24/2024.
//


#include "HexBoard.h"


HexBoard::HexBoard():BOARDSIZE(0),RED(0),BLUE(0) {
}

int HexBoard::whichCom(std::string& input) const{
    for (int i = 0; i < coms.size(); ++i) {
        if (coms[i] == input){
            return i;
        }
    }
    return 10;
}

int HexBoard::countRed(std::string& input) {
    RED = 0;
    for (char ch : input) {
        if (ch == 'r'){
            RED++;
        }
    }
    return RED;}

int HexBoard::countBlue(std::string& input) {
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

void HexBoard::isBoardCorrect(std::string& input) {
    if(countRed(input) == countBlue(input) || countRed(input)-1 == countBlue(input)){
        std::cout << "YES" << std::endl << std::endl;
    }else{
        std::cout << "NO" << std::endl << std::endl;
    }
}

bool HexBoard::isBoardCorrect(const std::vector<std::vector<char>>& board) {
    int red = 0;
    int blue = 0;
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board.size(); ++j){
            if (board[i][j] == 'r'){
                red++;
            } else if(board[i][j] == 'b'){
                blue++;
            }
        }
    }
    return (red == blue || red-1 == blue);
}

std::vector<std::vector<char>> HexBoard::hexParse(const std::string& input) {
    setBoardSize(input);
    std::istringstream iss(input);
    std::string line;
    std::vector<std::string> lines;

    while (std::getline(iss, line)) {
        size_t first = line.find_first_not_of(' ');
        if (first != std::string::npos) {
            line.erase(0, first);
        }
        line.erase(std::remove(line.begin(), line.end(), '-'), line.end());
        line.erase(std::remove(line.begin(), line.end(), '<'), line.end());
        line.erase(std::remove(line.begin(), line.end(), '>'), line.end());
        if (!line.empty()) {
            lines.push_back(line);
        }
    }
    std::vector<std::vector<char>> array(int(BOARDSIZE), std::vector<char>(int(BOARDSIZE), '*'));

    for (int i = 0; i < BOARDSIZE; ++i) {
        for (int j = 0; j < BOARDSIZE; ++j) {
            lines[j].pop_back();
            array[i][j] = lines[j].back();
//            for (int k = 0; k < 2; ++k) {
//                lines[j].pop_back();
//            }
            lines[j].pop_back();
            lines[j].pop_back();

        }
        lines.erase(lines.begin());
    }

    return array;
}


void HexBoard::print(const std::vector<std::vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}

bool HexBoard::dfs(int i, int j, char player, std::vector<std::vector<char>>& board, std::vector<std::vector<bool>>& visited) {
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j] || board[i][j] != player) {
        return false;
    }

    visited[i][j] = true;

    // red right edge
    if (player == 'r' && j == board[0].size() - 1) {
        return true;
    }

    // blue bottom edge
    if (player == 'b' && i == board.size() - 1) {
        return true;
    }
//all possible neighbours
    std::vector<std::pair<int, int>> neighbours = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {1, 1}, {-1, -1}};
    for (auto& dir : neighbours) {
        if (dfs(i + dir.first, j + dir.second, player, board, visited)) {
            return true;
        }
    }
    return false;
}

std::string HexBoard::isOver(std::vector<std::vector<char>>& board) {
    if (isBoardCorrect(board)){
        int rows = board.size();
        int cols = rows;
        std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));

        for (int i = 0; i < rows; ++i) {
            if (board[i][0] == 'r' && dfs(i, 0, 'r', board, visited)) {
                return "YES RED";
            }
        }

        for (auto& row : visited) {
            std::fill(row.begin(), row.end(), false);
        }

        for (int j = 0; j < cols; ++j) {
            if (board[0][j] == 'b' && dfs(0, j, 'b', board, visited)) {
                return "YES BLUE";
            }
        }
        return "NO";
    }else{
        return "NO";
    }
}

std::string HexBoard::isPossible(std::vector<std::vector<char>>& board) {
    if (!isBoardCorrect(board)){
        return "NO";
    }
    if(isOver(board) == "NO"){
        return "YES";
    }
    std::string win = isOver(board);
    char player = (win == "YES BLUE") ? 'b' : 'r';
    char other = (win == "YES BLUE") ? 'r' : 'b';
    int done = 0;
    while(isOver(board) == win){
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board.size(); ++j) {
                if(done == 0){
                    if (board[i][j] == other){
                        board[i][j] = ' ';
                        done = 1;
                    }
                }
                if(board[i][j] == player){
                    board[i][j] = ' ';
                    if (isOver(board) == win){
                        board[i][j] = player;
                    }else{
                        return "YES";
                    }
                }
            }
        }
    }
    return "NO";
}
