#include <iostream>
#include <cstdlib>

using namespace std;

// Function prototypes
void drawBoard(char board[3][3]);
bool isBoardFull(char board[3][3]);
bool isWinner(char board[3][3], char player);
void playerMove(char board[3][3], char player);
void switchPlayer(char &currentPlayer);

int main() {
    char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    char currentPlayer = 'X';

    do {
        drawBoard(board);
        playerMove(board, currentPlayer);

        if (isWinner(board, currentPlayer)) {
            cout << "Player " << currentPlayer << " wins!" << endl;
            drawBoard(board);
            break;
        } else if (isBoardFull(board)) {
            cout << "It's a draw!" << endl;
            drawBoard(board);
            break;
        }

        switchPlayer(currentPlayer);

    } while (true);

    return 0;
}

void drawBoard(char board[3][3]) {
    cout << "Tic Tac Toe" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) {
                cout << " | ";
            }
        }
        cout << endl;
        if (i < 2) {
            cout << "---------" << endl;
        }
    }
    cout << endl;
}

bool isBoardFull(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

bool isWinner(char board[3][3], char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
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

void playerMove(char board[3][3], char player) {
    int choice;

    do {
        cout << "Player " << player << ", enter a number (1-9) to make your move: ";
        cin >> choice;
    } while (choice < 1 || choice > 9 || board[(choice - 1) / 3][(choice - 1) % 3] == 'X' || board[(choice - 1) / 3][(choice - 1) % 3] == 'O');

    board[(choice - 1) / 3][(choice - 1) % 3] = player;
}

void switchPlayer(char &currentPlayer) {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}
