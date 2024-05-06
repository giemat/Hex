#include <iostream>
#include <vector>
#include "HexBoard.h"
using namespace std;

int whichCom(string& input, std::vector<std::string> coms){
    for (int i = 0; i < coms.size(); ++i) {
        if (coms[i] == input){
            return i;
        }
    }
    return 20;
}

int main() {
    std::vector<std::string> coms = {"BOARD_SIZE", "PAWNS_NUMBER", "IS_BOARD_CORRECT","IS_BOARD_POSSIBLE", "IS_GAME_OVER", "CAN_RED_WIN_IN_1_MOVE_WITH_NAIVE_OPPONENT", "CAN_BLUE_WIN_IN_1_MOVE_WITH_NAIVE_OPPONENT", "CAN_RED_WIN_IN_2_MOVES_WITH_NAIVE_OPPONENT", "CAN_BLUE_WIN_IN_2_MOVES_WITH_NAIVE_OPPONENT", "CAN_RED_WIN_IN_1_MOVE_WITH_PERFECT_OPPONENT", "CAN_BLUE_WIN_IN_1_MOVE_WITH_PERFECT_OPPONENT", "CAN_RED_WIN_IN_2_MOVES_WITH_PERFECT_OPPONENT", "CAN_BLUE_WIN_IN_2_MOVES_WITH_PERFECT_OPPONENT"};

    string input;
    string Line;
    HexBoard hexBoard;
    while (getline(cin, Line)) {
        switch (whichCom(Line, coms)) {
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
                hexBoard.hexParse(input);
                cout << hexBoard.isPossible() << endl;
                hexBoard.deleteBoard();
                input = "";
                break;
            case 4:
                cout << endl;
                hexBoard.hexParse(input);
                cout << hexBoard.isOver() << endl;
                hexBoard.deleteBoard();
                input = "";
                break;
            case 5:
                cout << endl;
                hexBoard.hexParse(input);
                cout << hexBoard.Naive('r', 1) << endl;
                //hexBoard.deleteBoard();
                break;
            case 6:
                //hexBoard.hexParse(input);
                cout << hexBoard.Naive( 'b', 1) << endl;
                //hexBoard.deleteBoard();
                break;
            case 7:
                //hexBoard.hexParse(input);
                cout << hexBoard.Naive( 'r', 2) << endl;
                //hexBoard.deleteBoard();
                break;
            case 8:
                //hexBoard.hexParse(input);
                cout << hexBoard.Naive( 'b', 2) << endl;
                hexBoard.deleteBoard();
                input = "";
                break;
            case 9:
                cout << endl;
                hexBoard.hexParse(input);
                cout << hexBoard.Perfect('r','b', 1) << endl;
                //hexBoard.deleteBoard();
                break;
            case 10:
                //hexBoard.hexParse(input);
                cout << hexBoard.Perfect('b','r', 1) << endl;
                //hexBoard.deleteBoard();
                break;
            case 11:
                //hexBoard.hexParse(input);
                cout << hexBoard.Perfect('r','b', 2) << endl;
                //hexBoard.deleteBoard();
                break;
            case 12:
                //hexBoard.hexParse(input);
                cout << hexBoard.Perfect('b','r', 2) << endl;
                hexBoard.deleteBoard();
                input = "";
                hexBoard.setLast("");
                break;
            case 20:
                input += Line + "\n";
                break;
        }

    }

    return 0;
}