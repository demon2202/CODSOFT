#include <iostream>
#include <vector>

using namespace std;

void printBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

bool checkDraw(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '-') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, '-'));
    int row, col;
    bool playerXTurn = true;

    while (true) {
        printBoard(board);
        if (playerXTurn) {
            cout << "Player X, enter your move (row and column): ";
            cin >> row >> col;
            if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == '-') {
                board[row][col] = 'X';
                if (checkWin(board, 'X')) {
                    cout << "Player X wins!" << endl;
                    break;
                } else if (checkDraw(board)) {
                    cout << "The game is a draw." << endl;
                    break;
                }
            }
        } else {
            cout << "Player O, enter your move (row and column): ";
            cin >> row >> col;
            if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == '-') {
                board[row][col] = 'O';
                if (checkWin(board, 'O')) {
                    cout << "Player O wins!" << endl;
                    break;
                } else if (checkDraw(board)) {
                    cout << "The game is a draw." << endl;
                    break;
                }
            }
        }
        playerXTurn = !playerXTurn;
    }

    return 0;
}
