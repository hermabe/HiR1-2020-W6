#include "game.h"


void TicTacToe::printBoard() const {
    // Skriver ut brettet til skjerm på en fin måte.
    for (int i = 0; i < 3; i++) {
        cout << "+---+---+---+\n";
        for (int j = 0; j < 3; j++) {
            cout << "| " << board[i][j] << " ";
        }
        cout << "|\n";
    }
    cout << "+---+---+---+\n";
}

pair<int, int> TicTacToe::getPlayerInput() const {
    // Leser inn et trekk (rad og kolonne) fra bruker. Sørger for at trekket er lovlig.
    cout << "Enter row and column: ";
    int row, col;
    cin >> row >> col;
    while (!isLegalCoordinate(row, col)) {
        cout << "Invalid coordinates. Please enter again: ";
        cin >> row >> col;
    }
    return make_pair(row, col); // Bruker std::pair for å returnere to verdier samtidig
}

bool TicTacToe::hasWon(int row, int col) const {
    // Returnerer hvorvidt en spiller har vunnet ved å sjekke diagonalene og raden og kolonnen der det ble spilt
    if (board[row][0] == board[row][1] && board[row][1] == board[row][2]) return true; // Rad
    if (board[0][col] == board[1][col] && board[1][col] == board[2][col]) return true; // Kolonne
    if (board[1][1] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true; // Diagonal
    return board[1][1] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]; // Diagonal
}

bool TicTacToe::isFull() const {
    // Sjekker om det er spilt i alle rutene på brettet.
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

// Oppgavene implementeres her
