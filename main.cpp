#include <iostream>
#include <vector>
#include "HexBoard.h"
using namespace std;

int main() {
    HexBoard hexBoard;
    string input;
    string Line;
    std::vector<std::vector<char>> lines;
    while (getline(cin, Line)) {
        switch (hexBoard.whichCom(Line)) {
            case 0:
                cout << hexBoard.setBoardSize(input) << endl << endl;
                input = "";
                break;
            case 1:
                cout << hexBoard.countBlue(input)+hexBoard.countRed(input) << endl << endl;
                input = "";
                break;
            case 2:
                hexBoard.isBoardCorrect(input);
                input = "";
                break;
            case 3:
                lines = hexBoard.hexParse(input);
                cout << hexBoard.isPossible(lines) << endl << endl;
                input = "";
                break;
            case 4:
                lines = hexBoard.hexParse(input);
                cout << hexBoard.isOver(lines) << endl << endl;
                input = "";
                break;
            case 10:
                input += Line + "\n";
                break;
        }
        lines.clear();
    }

//    for (int i = 0; i < lines.size(); ++i) {
//        for (int j = 0; j < lines.size(); ++j) {
//            cout << lines[i][j];
//        }
//        cout << endl;
//    }
    return 0;
}