// C++ program to implement a simple console-based Tic-Tac-Toe game

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to display the game board
void displayBoard(vector<vector<char>>& board) {
    cout << " 1 | 2 | 3" << endl;
    cout << " ---------" << endl;
    cout << " 4 | 5 | 6" << endl;
    cout << " ---------" << endl;
    cout << " 7 | 8 | 9" << endl;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j] << " ";
            if (j < 2) {
                cout << "|";
            }
        }
        cout << endl;
        if (i < 2) {
            cout << " ---------" << endl;
        }
    }
}

// Function to check for a win
bool checkForWin(vector<vector<char>>& board, char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
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

// Function to check for a draw
bool checkForDraw(vector<vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char currentPlayer = 'X';

    while (true) {
        displayBoard(board);
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        int move;
        cin >> move;

        int row = (move - 1) / 3;
        int col = (move - 1) % 3;

        if (board[row][col] != ' ') {
            cout << "Invalid move, try again." << endl;
            continue;
        }

        board[row][col] = currentPlayer;

        if (checkForWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }

        if (checkForDraw(board)) {
            displayBoard(board);
            cout << "It's a draw!" << endl;
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    cout << "Play again? (y/n): ";
    char response;
    cin >> response;

    if (response == 'y') {
        main();
    }

    return 0;
}