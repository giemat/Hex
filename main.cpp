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
                cout << endl;
                cout << hexBoard.setBoardSize(input) << endl;
                input = "";
                break;
            case 1:
                cout << endl;
                cout << hexBoard.countBlue(input)+hexBoard.countRed(input) << endl;
                input = "";
                break;
            case 2:
                cout << endl;
                hexBoard.isBoardCorrect(input);
                input = "";
                break;
            case 3:
                cout << endl;
                cout << hexBoard.isPossible(hexBoard.hexParse(input)) << endl;
                hexBoard.deleteBoard(hexBoard.hexParse(input));
                input = "";
                break;
            case 4:
                cout << endl;
                cout << hexBoard.isOver(hexBoard.hexParse(input)) << endl;
                hexBoard.deleteBoard(hexBoard.hexParse(input));
                input = "";
                break;
                case 5:
                    cout << endl;
                    cout << hexBoard.Naive(hexBoard.hexParse(input), 'r', 1) << endl;
                hexBoard.deleteBoard(hexBoard.hexParse(input));

                break;
                case 6:
                    cout << hexBoard.Naive(hexBoard.hexParse(input), 'b', 1) << endl;
                hexBoard.deleteBoard(hexBoard.hexParse(input));

                break;
                case 7:
                    cout << hexBoard.Naive(hexBoard.hexParse(input), 'r', 2) << endl;
                hexBoard.deleteBoard(hexBoard.hexParse(input));

                break;
                case 8:
                    cout << hexBoard.Naive(hexBoard.hexParse(input), 'b', 2) << endl;
                    hexBoard.deleteBoard(hexBoard.hexParse(input));
                input = "";
                break;
            case 20:
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