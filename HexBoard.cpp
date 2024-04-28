//
// Created by matgi on 4/24/2024.
//


#include "HexBoard.h"


HexBoard::HexBoard():BOARDSIZE(0),RED(0),BLUE(0), SPACES(0) {
}

int HexBoard::whichCom(std::string& input) const{
    for (int i = 0; i < coms.size(); ++i) {
        if (coms[i] == input){
            return i;
        }
    }
    return 20;
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

bool HexBoard::isBoardCorrect(char** board) {
    int red = 0;
    int blue = 0;
    int space = 0;
    for (int i = 0; i < BOARDSIZE; ++i) {
        for (int j = 0; j < BOARDSIZE; ++j){
            if (board[i][j] == 'r'){
                red++;
            } else if(board[i][j] == 'b'){
                blue++;
            }else{
                space++;
            }
        }
    }
    RED = red;
    BLUE = blue;
    SPACES = space;
    return (red == blue || red-1 == blue);
}

char ** HexBoard::hexParse(const std::string& input) {
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
    int size = BOARDSIZE;
    char** array = new char*[size];
    for (int i = 0; i < size; i++) {
        array[i] = new char[size]{};
    }

    for (int i = 0; i < BOARDSIZE; ++i) {
        for (int j = 0; j < BOARDSIZE; ++j) {
            lines[j].pop_back();
            array[i][j] = lines[j].back();
            lines[j].pop_back();
            lines[j].pop_back();

        }
        lines.erase(lines.begin());
    }

    return array;
}

bool HexBoard::dfs(int i, int j, char player, char** board, bool** visited) {
    if (i < 0 || i >= BOARDSIZE || j < 0 || j >= BOARDSIZE || visited[i][j] || board[i][j] != player) {
        return false;
    }

    visited[i][j] = true;

    // red right edge
    if (player == 'r' && j == BOARDSIZE - 1) {
        return true;
    }

    // blue bottom edge
    if (player == 'b' && i == BOARDSIZE - 1) {
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

std::string HexBoard::isOver(char** board) {
    if (isBoardCorrect(board)){
        int rows = BOARDSIZE;
        int cols = rows;

        bool** visited = new bool*[rows];
        for (int i = 0; i < rows; i++) {
            visited[i] = new bool[cols]{};
        }

        for (int i = 0; i < rows; ++i) {
            if (board[i][0] == 'r' && dfs(i, 0, 'r', board, visited)) {
                deleteVisit(visited);
                return "YES RED";
            }
        }


        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; ++j) {
                visited[i][j] = false;
            }
        }

        for (int j = 0; j < cols; ++j) {
            if (board[0][j] == 'b' && dfs(0, j, 'b', board, visited)) {
                deleteVisit(visited);
                //deleteBoard(board);
                return "YES BLUE";
            }
        }
        deleteVisit(visited);
        //deleteBoard(board);
        return "NO";
    }else{
        //deleteBoard(board);
        return "NO";
    }
}

std::string HexBoard::isPossible(char **board) {
    if (isBoardCorrect(board)){
        if (isOver(board) == "YES RED"){
            if (RED-1 == BLUE){
                for (int i = 0; i < BOARDSIZE; ++i) {
                    for (int j = 0; j < BOARDSIZE; ++j) {
                        if (board[i][j] == 'r'){
                            board[i][j] = ' ';
                            if(isOver(board) == "NO"){
                                //deleteBoard(board);
                                return "YES";
                            }
                            board[i][j] = 'r';
                        }
                    }
                }
            }
        }else if(isOver(board) == "YES BLUE"){
            if (RED == BLUE){
                for (int i = 0; i < BOARDSIZE; ++i) {
                    for (int j = 0; j < BOARDSIZE; ++j) {
                        if (board[i][j] == 'b'){
                            board[i][j] = ' ';
                            if(isOver(board) == "NO"){
                                //deleteBoard(board);
                                return "YES";
                            }
                            board[i][j] = 'b';
                        }
                    }
                }
            }
        }else{
            //deleteBoard(board);
            return "YES";
        }
    }
    //deleteBoard(board);
    return "NO";
}

void HexBoard::deleteVisit(bool **board) const {
    for (int i = 0; i < BOARDSIZE; ++i) {
        delete[] board[i];
    }
    delete[] board;
}

void HexBoard::deleteBoard(char **board) {
    for (int i = 0; i < BOARDSIZE; ++i) {
        delete[] board[i];
    }
    delete[] board;
    BOARDSIZE = 0;
    BLUE = 0;
    RED = 0;
    SPACES = 0;
}

std::string HexBoard::Naive(char** board, char player, int moves) {
    if (isPossible(board) == "NO"){
        return "NO";//for all
    }
    if (isOver(board) != "NO"){
        return "NO";//for all
    }
    if (RED-1 == BLUE){//blue turn
        if (player == 'b'){
            if (moves == 1){
                if(SPACES < 1){
                    return "NO";
                }
                for (int i = 0; i < BOARDSIZE; ++i) {
                    for (int j = 0; j < BOARDSIZE; ++j) {
                        if (board[i][j] == ' '){
                            board[i][j] = 'b';
                            if (isOver(board) == "YES BLUE"){
                                return "YES";
                            }
                            board[i][j] = ' ';
                        }
                    }
                }
            }
        }else{
            if (moves == 1){
                if(SPACES < 2){
                    return "NO";
                }
                for (int i = 0; i < BOARDSIZE; ++i) {
                    for (int j = 0; j < BOARDSIZE; ++j) {
                        if (board[i][j] == ' '){
                            board[i][j] = 'r';
                            if (isOver(board) == "YES RED"){
                                return "YES";
                            }
                            board[i][j] = ' ';
                        }
                    }
                }
            }
        }
    } else{//red turn
        if (player == 'b'){
            if (moves == 1){
                if(SPACES < 2){
                    return "NO";
                }
                for (int i = 0; i < BOARDSIZE; ++i) {
                    for (int j = 0; j < BOARDSIZE; ++j) {
                        if (board[i][j] == ' '){
                            board[i][j] = 'b';
                            if (isOver(board) == "YES BLUE"){
                                return "YES";
                            }
                            board[i][j] = ' ';
                        }
                    }
                }
            }
        }else{
            if (moves == 1){
                if(SPACES < 1){
                    return "NO";
                }
                for (int i = 0; i < BOARDSIZE; ++i) {
                    for (int j = 0; j < BOARDSIZE; ++j) {
                        if (board[i][j] == ' '){
                            board[i][j] = 'r';
                            if (isOver(board) == "YES RED"){
                                return "YES";
                            }
                            board[i][j] = ' ';
                        }
                    }
                }
            }
        }
    }


    return "NO";//not needed
}