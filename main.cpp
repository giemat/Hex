#include <iostream>
#include <vector>
#include "HexBoard.h"
using namespace std;

int main() {
    HexBoard hexBoard;
    string input;
    string Line;
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

                cout << hexBoard.isPossible(hexBoard.hexParse(input)) << endl << endl;
                input = "";
                break;
            case 4:

                cout << hexBoard.isOver(hexBoard.hexParse(input)) << endl << endl;
                input = "";
                break;
            case 10:
                input += Line + "\n";
                break;
        }

    }

//    for (int i = 0; i < lines.size(); ++i) {
//        for (int j = 0; j < lines.size(); ++j) {
//            cout << lines[i][j];
//        }
//        cout << endl;
//    }
    return 0;
}