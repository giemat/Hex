#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include "HexBoard.h"
using namespace std;

int main() {
    HexBoard hexBoard;
    string input;
    string Line;
    while (getline(cin, Line) && !Line.empty()) {
        switch (hexBoard.whichCom(Line)) {
            case 0:
                cout << hexBoard.setBoardSize(input) << endl << endl;
                //input = "";
                break;
            case 1:
                cout << hexBoard.countBlue(input)+hexBoard.countRed(input) << endl << endl;
                //input = "";
                break;
            case 2:
                hexBoard.isBoardCorrect(input);
                //input = "";
                break;
            case 4:
//                try {
//                    vector<vector<char>> hex_board = hexBoard.hex_to_2d_array(input);
//                    hexBoard.print_hex_board(hex_board);
//                } catch (const std::exception& e) {
//                    std::cerr << "Error: " << e.what() << std::endl;
//                }
            case 10:
                input += Line + "\n";
                break;
            }
        }
//    std::istringstream iss(input);
//    std::string line;
//    std::vector<std::string> lines;
//
//    // Extracting lines from the input
//    while (std::getline(iss, line)) {
//        size_t firstDash = line.find_first_not_of(' ');
//        if (firstDash != std::string::npos) {
//            line.erase(0, firstDash);
//        }
//        // Remove unnecessary characters
//        line.erase(std::remove(line.begin(), line.end(), '-'), line.end());
//        line.erase(std::remove(line.begin(), line.end(), '<'), line.end());
//        line.erase(std::remove(line.begin(), line.end(), '>'), line.end());
//        if (!line.empty()) {
//            lines.push_back(line);
//        }
//    }
//
//    // Determine the size of the hex board based on the input
//    int size = lines.size();
    std::vector<std::vector<char>> lines;
    lines = hexBoard.hexParse(input);

    for (int i = 0; i < lines.size(); ++i) {
        for (int j = 0; j < lines.size(); ++j) {
            cout << lines[i][j];
        }
        cout << endl;
    }
    return 0;
}

