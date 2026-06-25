#include <iostream>
using namespace std;
//HARD (Validity of given Tic-Tac-Toe board configuration)
int win[8][3] = {
    {0,1,2}, {3,4,5}, {6,7,8}, // rows
    {0,3,6}, {1,4,7}, {2,5,8}, // columns
    {0,4,8}, {2,4,6}           // diagonals
};

// Check if player c wins
bool isWin(char board[9], char c) {
    for (int i = 0; i < 8; i++) {
        if (board[win[i][0]] == c &&
            board[win[i][1]] == c &&
            board[win[i][2]] == c) {
            return true;
        }
    }
    return false;
}
// Check if board is valid
bool isValid(char board[9]) {

    int xCount = 0, oCount = 0;

    // Count X and O
    for (int i = 0; i < 9; i++) {
        if (board[i] == 'X') xCount++;
        if (board[i] == 'O') oCount++;
    }

    // Rule 1: turn order check
    if (!(xCount == oCount || xCount == oCount + 1))
        return false;

    bool xWin = isWin(board, 'X');
    bool oWin = isWin(board, 'O');

    // Rule 2: both cannot win
    if (xWin && oWin)
        return false;

    // If X wins, X must be one move ahead
    if (xWin && xCount != oCount + 1)
        return false;

    // If O wins, counts must be equal
    if (oWin && xCount != oCount)
        return false;
    return true;
}

int main() {
   char board[9] = {
        'X','X','O',
        'O','O','X',
        'X','O','X'
    };

    if (isValid(board))
        cout << "Valid board";
    else
        cout << "Invalid board";
    return 0;
}
